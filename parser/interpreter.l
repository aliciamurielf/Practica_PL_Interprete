/*! 
  \file interpreter.l
  \brief Lexical or scanner file
  \author Alicia Muriel Fernández
  \author Lucía Cañero Moslero
  \date 2026-05-24
  \version 1.0
*/
%{
#include <iostream>

/*********************/
/* atof */
#include <stdlib.h>
/*********************/

/* Macros for the screen */
#include "../includes/macros.hpp"

/*********************/
/* 
  AST class
  IMPORTANT: must be written before interpreter.tab.h
*/
#include "../ast/ast.hpp"
/*********************/

/*  interpreter.tab.h contains the numeric values of the tokens produced by the parser */
#include "interpreter.tab.h"

/********************/
#include "../error/error.hpp"
/********************/


/*********************************************/
/* Table of symbols */
#include "../table/table.hpp"

#include "../table/numericVariable.hpp"

extern lp::Table table; //!< External Table of Symbols
/*********************************************/

extern int lineNumber; //!< External line counter

/* uso de strdup */
#include <string.h>


%}

%option caseless

DIGIT  [0-9] 

LETTER [a-zA-Z]

NUMBER1 {DIGIT}+\.?

NUMBER2 {DIGIT}*\.{DIGIT}+(e[+-]?{DIGIT}+)?

IDENTIFIER  {LETTER}({LETTER}|{DIGIT}|"_"({LETTER}|{DIGIT}))*

CADENA      '([^'\\]|\\.)*'

ERROR_NUM   {DIGIT}+\.{DIGIT}+\.{DIGIT}+
ERROR_ID_FIN   {LETTER}({LETTER}|{DIGIT}|_)*_
ERROR_ID_DOBLE {LETTER}({LETTER}|{DIGIT}|_)*__({LETTER}|{DIGIT}|_)*

%x ERROR COMENTARIO_BLOQUE

%%

[ \t] 	{ ; }   

\n      { 
           	lineNumber++; 
        }

";"		{
			return SEMICOLON;
		}

","		{
			return COMMA;
		}

":"		{
			/* PARA LOS CASOS DEL SWITCH */
			return ':';
		}
"-"		{ return MINUS;  } 			
"+"		{ return PLUS;   } 			

"*"	    { return MULTIPLICATION; } 	
"/"     { return DIVISION; } 		

"("     { return LPAREN; } 			
")"	    { return RPAREN; } 			

"mod"     { return MODULO; }			

"^"	    { return POWER; }		

":=" 	{ return ASSIGNMENT; }		

"="	{ return EQUAL; }			

"<>"	{ return NOT_EQUAL; }		

">="	{ return GREATER_OR_EQUAL; } 

"<="	{ return LESS_OR_EQUAL; }	

">"		{ return GREATER_THAN; }	
"<"		{ return LESS_THAN; }		

"||"	{ return CONCATENATION; }				

"{"		{ return LETFCURLYBRACKET; } 	

"}"		{ return RIGHTCURLYBRACKET; }	

"//"    { return INTEGER_DIVISION; }  

"++"    { return INC; }

"--"    { return DEC; }

"!"     { return FACT; }

"+="    { return PLUS_ASSIGN; }

"-="    { return MINUS_ASSIGN; }

"*="    { return MULT_ASSIGN; }

"/="    { return DIV_ASSIGN; }

"%="    { return MOD_ASSIGN; }

"?"     { return QUESTION; }
"red_text"     { return RED_TEXT; }
"green_text"   { return GREEN_TEXT; }
"blue_text"    { return BLUE_TEXT; }
"yellow_text"  { return YELLOW_TEXT; }
"reset_text"   { return RESET_TEXT; }

{ERROR_NUM}   { warning("Lexical error: Numero mal formado (demasiados puntos)", yytext); }

{ERROR_ID_FIN}   { warning("Lexical error: Un identificador no puede terminar en guion bajo", yytext); }

{ERROR_ID_DOBLE} { warning("Lexical error: Un identificador no puede tener dos guiones bajos seguidos", yytext); }
		
{NUMBER1}|{NUMBER2}  { 
						yylval.number = atof(yytext); 
						return NUMBER; 
                      }

{IDENTIFIER}   		 {
						 std::string identifier(yytext);

						for(int i = 0; identifier[i]; i++) 
							identifier[i] = tolower(identifier[i]);

						yylval.string = strdup(identifier.c_str());

						// Buscamos en la tabla con el nombre en minúsculas
						if (table.lookupSymbol(identifier) == false)
						{
							lp::NumericVariable *n = new lp::NumericVariable(identifier, VARIABLE, UNDEFINED, 0.0);
							table.installSymbol(n);
							return VARIABLE;
						}
						else 
						{
							return table.getSymbol(identifier)->getToken();
						}
                     }

{CADENA}            {
						yytext[yyleng-1] = '\0';
						yytext++;
						yyleng--;
						yylval.string = strdup(yytext);
						return STRING;
					}

"(*"    { BEGIN(COMENTARIO_BLOQUE); } 
<COMENTARIO_BLOQUE>"*)" { BEGIN(INITIAL); }
<COMENTARIO_BLOQUE>\n   { lineNumber++; }   
<COMENTARIO_BLOQUE>.    { /* Ignoramos cualquier otro carácter */ }

"#".* { 
                    /* Comentario de una linea: no hacemos nada, lo ignoramos */ 
      }


<<EOF>> { /* The interpreter finishes when finds the end of file character */
		/*  PLACE(24,10);
	  	  std::cout <<  BICYAN;
	   	  std::cout <<  ">>>>>>> End of program <<<<<<<";
	 	  std::cout << std::endl;
	   	  std::cout << RESET;
		  PLACE(25,1);
		*/
	  	  return 0;
	}


.								{ 	
									BEGIN(ERROR); 
									yymore();  
								}

<ERROR>[^0-9+\-*/()\^% \t\n\;a-zA-Z=<>!&]	{ 
									yymore(); 
								}

<ERROR>(.|\n)                { 
								yyless(yyleng-1); 
								warning("Lexical error", yytext);
   								BEGIN(INITIAL);
							}
%%

