/*! 
  \file interpreter.y
  \brief Grammar file
  \author Alicia Muriel Fernández
  \author Lucía Cañero Moslero
  \date 2026-05-24
  \version 1.0
*/


%{
#include <iostream>
#include <string>

/*******************************************/
/* NEW in example 5 */
/* pow */
#include <math.h>
/*******************************************/

/*******************************************/
/* NEW in example 6 */
/* Use for recovery of runtime errors */
#include <setjmp.h>
#include <signal.h>
/*******************************************/

/* Error recovery functions */
#include "../error/error.hpp"

/* Macros for the screen */
#include "../includes/macros.hpp"


/*******************************************/
/* 
  NEW in example 16
  AST class
  IMPORTANT: this file must be before init.hpp
*/
#include "../ast/ast.hpp"


/*******************************************/
/* NEW in example 7 */
/* Table of symbol */
#include "../table/table.hpp"
/*******************************************/

/*******************************************/
#include "../table/numericVariable.hpp"
/*******************************************/

/* NEW in example 15 */
#include "../table/logicalVariable.hpp"

/*******************************************/
/* NEW in example 11 */
#include "../table/numericConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 15 */
#include "../table/logicalConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 13 */
#include "../table/builtinParameter1.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 14 */
#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter2.hpp"
/*******************************************/


/*******************************************/
/* NEW in example 10 */
#include "../table/init.hpp"
/*******************************************/

/*! 
	\brief  Lexical or scanner function
	\return int
	\note   C++ requires that yylex returns an int value
	\sa     yyparser
*/
int yylex();


extern int lineNumber; //!< External line counter


/* NEW in example 15 */
extern bool interactiveMode; //!< Control the interactive mode of execution of the interpreter

/* New in example 17 */
extern int control; //!< External: to control the interactive mode in "if" and "while" sentences 

/***********************************************************/
/* NEW in example 2 */
extern std::string progname; //!<  Program name
/***********************************************************/

/*******************************************/
/* NEW in example 6 */
/*
 jhmp_buf
    This is an array type capable of storing the information of a calling environment to be restored later.
   This information is filled by calling macro setjmp and can be restored by calling function longjmp.
*/
jmp_buf begin; //!<  It enables recovery of runtime errors 
/*******************************************/


/*******************************************/
/* NEW in example 7 */
extern lp::Table table; //!< Extern Table of Symbols

/*******************************************/
/* NEW in example 16 */
extern lp::AST *root; //!< External root of the abstract syntax tree AST

%}

/* In case of a syntactic error, more information is shown */
/* DEPRECATED */
/* %error-verbose */

/* ALTERNATIVA a %error-verbose */
%define parse.error verbose

/* %define parse.trace */


/* Initial grammar symbol */
%start program

/*******************************************/
/* Data type YYSTYPE  */
/* NEW in example 4 */
%union {
  double number;
  char * string; 				 /* NEW in example 7 */
  bool logic;						 /* NEW in example 15 */
  lp::ExpNode *expNode;  			 /* NEW in example 16 */
  std::list<lp::ExpNode *>  *parameters;    // New in example 16; NOTE: #include<list> must be in interpreter.l, init.cpp, interpreter.cpp
  std::list<lp::Statement *> *stmts; /* NEW in example 16 */
  lp::Statement *st;				 /* NEW in example 16 */
  lp::AST *prog;					 /* NEW in example 16 */
  std::list<lp::CaseStmt *> *cases;  /* Lista de casos para el switch */
  lp::CaseStmt *casestmt;            /* Nodo de un caso individual */
}

/* Type of the non-terminal symbols */
%type <expNode> exp cond 

/* New in example 14 */
%type <parameters> listOfExp  restOfListOfExp

%type <stmts> stmtlist

// New in example 17: if, while, block
%type <st> stmt asgn print read if while block repeat for read_string clear_screen place switch do_while

%type <cases> case_list
%type <casestmt> case

%type <prog> program

/* Defined tokens */

/* Minimum precedence */

%token SEMICOLON COMMA
%token LETFCURLYBRACKET RIGHTCURLYBRACKET
%token ASSIGNMENT

/* Palabras reservadas */
%token PRINT READ READ_STRING IF THEN ELSE END_IF WHILE DO END_WHILE REPEAT UNTIL FOR FROM TO STEP END_FOR SWITCH CASE DEFAULT END_SWITCH CONCATENATION DO_WHILE

/* Operadores lógicos */
%token AND OR NOT

/* Comandos de pantalla */
%token CLEAR_SCREEN_CMD PLACE_CMD

%token INC DEC FACT PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN QUESTION

%token RED_TEXT GREEN_TEXT BLUE_TEXT YELLOW_TEXT RESET_TEXT FACTORIAL_KW

/*******************************************/
/* Tokens con valor asociado (Tipados) */
/*******************************************/

%token <number> NUMBER
%token <logic> BOOL
%token <string> VARIABLE UNDEFINED CONSTANT BUILTIN STRING

/* Left associativity */

/*******************************************************/
/* NEW in example 15 */
%left OR

%left AND

%nonassoc GREATER_OR_EQUAL LESS_OR_EQUAL GREATER_THAN LESS_THAN  EQUAL NOT_EQUAL

%left NOT
/*******************************************************/
%left CONCATENATION

/* Ternary operator */
%right QUESTION

/* MODIFIED in example 3 */
%left PLUS MINUS 

/* MODIFIED in example 5 */
%left MULTIPLICATION DIVISION MODULO INTEGER_DIVISION

/* Compound assignment operators */
%right PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN

%left LPAREN RPAREN

%nonassoc  UNARY

/* Increment and Decrement */
%left INC DEC FACT

// Maximum precedence 
/* MODIFIED in example 5 */
%right POWER


%%
 //! \name Grammar rules

program : stmtlist
		  { 
		    // Create a new AST
			$$ = new lp::AST($1); 

			// Assign the AST to the root
			root = $$; 

			// End of parsing
			//	return 1;
		  }
;

stmtlist:  /* empty: epsilon rule */
		  { 
			$$ = new std::list<lp::Statement *>(); 
		  }  

        | stmtlist stmt 
		  { 
			$$ = $1;
			$$->push_back($2);

			if (interactiveMode == true && control == 0)
 			{
				for(std::list<lp::Statement *>::iterator it = $$->begin(); 
						it != $$->end(); 
						it++)
				{
					// (*it)->printAST();
					(*it)->evaluate();
				}
				$$->clear();
			}
		}

    | stmtlist error 
      { 
			 $$ = $1;
			 yyclearin; 
       } 
;

stmt: SEMICOLON { $$ = new lp::EmptyStmt(); }
    | asgn SEMICOLON 
		{ 
			$$ = $1; 
		}
    | print SEMICOLON 
		{ 
			$$ = $1; 
		}
    | read SEMICOLON 
		{ 
			$$ = $1; 
		}
    | read_string SEMICOLON 
		{ 
			$$ = $1; 
		}
    | clear_screen SEMICOLON 
		{ 
			$$ = $1; 
		}
    | place SEMICOLON 
		{ 
			$$ = $1; 
		}
    | if 
		{ 
			$$ = $1; 
		}     
    | while 
		{ 
			$$ = $1; 
		}  
    | for 
		{ 
			$$ = $1; 
		}    
    | repeat 
		{ 
			$$ = $1; 
		} 
    | block 
		{ 
			$$ = $1; 
		}
	| switch 
		{ 
			$$ = $1; 
		}
	| do_while 
		{
			$$ = $1;
		}
	| VARIABLE INC SEMICOLON 
		{ 
			$$ = new lp::AssignmentStmt($1, new lp::PlusNode(new lp::VariableNode($1), new lp::NumberNode(1))); 
		}
    | VARIABLE DEC SEMICOLON 
		{ 
			$$ = new lp::AssignmentStmt($1, new lp::MinusNode(new lp::VariableNode($1), new lp::NumberNode(1))); 
		}
    | VARIABLE PLUS_ASSIGN exp SEMICOLON 
		{ 
			$$ = new lp::AssignmentStmt($1, new lp::PlusNode(new lp::VariableNode($1), $3)); 
		}
    | VARIABLE MINUS_ASSIGN exp SEMICOLON 
		{ 
			$$ = new lp::AssignmentStmt($1, new lp::MinusNode(new lp::VariableNode($1), $3)); 
		}
	| VARIABLE MULT_ASSIGN exp SEMICOLON
		{
			$$ = new lp::AssignmentStmt($1, new lp::MultiplicationNode(new lp::VariableNode($1), $3)); 
		}
	| VARIABLE DIV_ASSIGN exp SEMICOLON
		{
			$$ = new lp::AssignmentStmt($1, new lp::DivisionNode(new lp::VariableNode($1), $3)); 
		}
	| RED_TEXT SEMICOLON    
		{ 
			$$ = new lp::ColorStmt("\033[31m"); 
		}
    |  GREEN_TEXT SEMICOLON  
		{ 
			$$ = new lp::ColorStmt("\033[32m"); 
		}
    |  BLUE_TEXT SEMICOLON   
		{ 
			$$ = new lp::ColorStmt("\033[34m"); 
		}
    | YELLOW_TEXT SEMICOLON 
		{ 
			$$ = new lp::ColorStmt("\033[33m"); 
		}
    | RESET_TEXT SEMICOLON  
		{ 
			$$ = new lp::ColorStmt("\033[0m"); 
		}
;

/* Regla IF */
if: IF controlSymbol cond THEN stmtlist END_IF 
         { 
           lp::BlockStmt *aux_1 = new lp::BlockStmt($5);
           $$ = new lp::IfStmt($3, aux_1); 
           control--; 
         }
       | IF controlSymbol cond THEN stmtlist ELSE stmtlist END_IF 
         { 
           lp::BlockStmt *aux_1 = new lp::BlockStmt($5);
           lp::BlockStmt *aux_2 = new lp::BlockStmt($7);
           
           $$ = new lp::IfStmt($3, aux_1, aux_2); 

           control--; 
         }
;

/* Regla WHILE*/
while: WHILE controlSymbol cond DO stmtlist END_WHILE 
            { 
              lp::BlockStmt *aux_1 = new lp::BlockStmt($5);
              $$ = new lp::WhileStmt($3, aux_1); 
              control--; 
            }
;

/* Regla FOR */
for: FOR controlSymbol VARIABLE FROM exp TO exp DO stmtlist END_FOR
          { 
            $$ = new lp::ForStmt($3, $5, $7, new lp::NumberNode(1), $9); 
            control--;
          }
        | FOR controlSymbol VARIABLE FROM exp TO exp STEP exp DO stmtlist END_FOR
          { 
            $$ = new lp::ForStmt($3, $5, $7, $9, $11); 
            control--;
          }
;

repeat: REPEAT controlSymbol stmtlist UNTIL cond
    {
        $$ = new lp::RepeatStmt($3, $5);
        control--;
    }
;

do_while: DO controlSymbol block WHILE cond SEMICOLON
          {
              $$ = new lp::DoWhileStmt($3, $5);
              control--;
          }
;

cond: LPAREN exp RPAREN { $$ = $2; } ;

block: LETFCURLYBRACKET stmtlist RIGHTCURLYBRACKET  
		{
			$$ = new lp::BlockStmt($2); 
		}
;

controlSymbol:  /* Epsilon rule*/
		{
			control++;
		}
	;

asgn:   VARIABLE ASSIGNMENT exp 
		{ 
			$$ = new lp::AssignmentStmt($1, $3);
		}

	|  VARIABLE ASSIGNMENT asgn 
		{ 
			
			$$ = new lp::AssignmentStmt($1, (lp::AssignmentStmt *) $3);
		}
	  
	| CONSTANT ASSIGNMENT exp 
		{   
 			execerror("Semantic error in assignment: it is not allowed to modify a constant ", $1);
		}
	  
	| CONSTANT ASSIGNMENT asgn 
		{   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a constant ",$1);
		}
;

print:  PRINT exp 
		{
			 $$ = new lp::PrintStmt($2);
		}
;	

read:  READ LPAREN VARIABLE RPAREN  
		{
			 $$ = new lp::ReadStmt($3);
		}

	| READ LPAREN CONSTANT RPAREN  
		{   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a constant ",$3);
		}
;

read_string: READ_STRING LPAREN VARIABLE RPAREN
    {
        $$ = new lp::ReadStringStmt($3);
    }

	| READ_STRING LPAREN CONSTANT RPAREN
		{
			execerror("Semantic error in \"read statement\": it is not allowed to modify a constant ",$3);
		}
;

exp:	NUMBER 
		{ 
			$$ = new lp::NumberNode($1);
		}

	| STRING  
		{
		$$ = new lp::StringNode($1);
		}
	
	| exp FACT
		{
			$$ = new lp::FactorialNode($1);
		}

	| exp QUESTION exp COMMA exp
		{
			$$ = new lp::TernaryNode($1, $3, $5);
		}
		
	| 	exp PLUS exp 
		{ 
			 $$ = new lp::PlusNode($1, $3);
		 }

	| 	exp MINUS exp
      	{
			$$ = new lp::MinusNode($1, $3);
		}

	| 	exp MULTIPLICATION exp 
		{ 
			$$ = new lp::MultiplicationNode($1, $3);
		}

	| 	exp DIVISION exp
		{
		  $$ = new lp::DivisionNode($1, $3);
	   }

	|   exp INTEGER_DIVISION exp
     	{
			$$ = new lp::IntegerDivisionNode($1, $3);
		}
		
	| exp CONCATENATION exp 
        {
          $$ = new lp::ConcatenationNode($1, $3);
        }

	| 	LPAREN exp RPAREN
       	{ 
			$$ = $2;
		 }

  	| 	PLUS exp %prec UNARY
		{ 
  		  $$ = new lp::UnaryPlusNode($2);
		}

	| 	MINUS exp %prec UNARY
		{ 
  		  $$ = new lp::UnaryMinusNode($2);
		}

	|	exp MODULO exp 
		{
		  $$ = new lp::ModuloNode($1, $3);
       }

	|	exp POWER exp 
     	{ 
  		  $$ = new lp::PowerNode($1, $3);
		}

	 | VARIABLE
		{
		  $$ = new lp::VariableNode($1);
		}

	 | CONSTANT
		{
		  $$ = new lp::ConstantNode($1);

		}

	| BUILTIN LPAREN listOfExp RPAREN
		{
			// Get the identifier in the table of symbols as Builtin
			lp::Builtin *f= (lp::Builtin *) table.getSymbol($1);

			// Check the number of parameters 
			if (f->getNParameters() ==  (int) $3->size())
			{
				switch(f->getNParameters())
				{
					case 0:
						{
							// Create a new Builtin Function with 0 parameters node	
							$$ = new lp::BuiltinFunctionNode_0($1);
						}
						break;

					case 1:
						{
							// Get the expression from the list of expressions
							lp::ExpNode *e = $3->front();

							// Create a new Builtin Function with 1 parameter node	
							$$ = new lp::BuiltinFunctionNode_1($1,e);
						}
						break;

					case 2:
						{
							// Get the expressions from the list of expressions
							lp::ExpNode *e1 = $3->front();
							$3->pop_front();
							lp::ExpNode *e2 = $3->front();

							// Create a new Builtin Function with 2 parameters node	
							$$ = new lp::BuiltinFunctionNode_2($1,e1,e2);
						}
						break;

					default:
				  			 execerror("Syntax error: too many parameters for function ", $1);
				} 
			}
			else
	  			 execerror("Syntax error: incompatible number of parameters for function", $1);
		}

	| exp GREATER_THAN exp
	 	{
 			$$ = new lp::GreaterThanNode($1,$3);
		}

	| exp GREATER_OR_EQUAL exp 
	 	{
 			$$ = new lp::GreaterOrEqualNode($1,$3);
		}

	| exp LESS_THAN exp 	
	 	{
 			$$ = new lp::LessThanNode($1,$3);
		}

	| exp LESS_OR_EQUAL exp 
	 	{
 			$$ = new lp::LessOrEqualNode($1,$3);
		}

	| exp EQUAL exp 	
	 	{
 			$$ = new lp::EqualNode($1,$3);
		}

    | exp NOT_EQUAL exp 	
	 	{
 			$$ = new lp::NotEqualNode($1,$3);
		}

    | exp AND exp 
	 	{
 			$$ = new lp::AndNode($1,$3);
		}

    | exp OR exp 
	 	{
 			$$ = new lp::OrNode($1,$3);
		}

    | NOT exp 
	 	{
 			$$ = new lp::NotNode($2);
		}
;


listOfExp: 
			/* Empty list of numeric expressions */
			{
				$$ = new std::list<lp::ExpNode *>(); 
			}

	|  exp restOfListOfExp
			{
				$$ = $2;
				$$->push_front($1);
			}
;

restOfListOfExp:
			/* Empty list of numeric expressions */
			{
				$$ = new std::list<lp::ExpNode *>(); 
			}

		|	COMMA exp restOfListOfExp
			{
				$$ = $3;
				$$->push_front($2);
			}
;

clear_screen: CLEAR_SCREEN_CMD
    { 
        $$ = new lp::ClearScreenStmt(); 
    }
;

place: PLACE_CMD LPAREN exp COMMA exp RPAREN 
    { 
        $$ = new lp::PlaceStmt($3, $5); 
    }
;

/* Definición del SWITCH con y sin DEFAULT */
switch: SWITCH controlSymbol cond case_list END_SWITCH
             {
               $$ = new lp::SwitchStmt($3, $4, NULL);
               control--;
             }
           | SWITCH controlSymbol cond case_list DEFAULT ':' stmtlist END_SWITCH
             {
               $$ = new lp::SwitchStmt($3, $4, new lp::BlockStmt($7));
               control--;
             }
;

case_list: case 
           { 
             $$ = new std::list<lp::CaseStmt *>(); 
             $$->push_back($1); 
           }
         | case_list case 
           { 
             $$ = $1; 
             $$->push_back($2); 
           }
;

case: CASE exp ':' stmtlist 
           { 
             $$ = new lp::CaseStmt($2, new lp::BlockStmt($4)); 
           }
;
%%
// %precedence ELSE

// %token IF ELSE



