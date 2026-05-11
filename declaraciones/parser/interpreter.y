/*! 
  \file interpreter.y
  \brief Grammar file
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

/*! 
	\brief  Lexical or scanner function
	\return int
	\note   C++ requires that yylex returns an int value
	\sa     yyparser
*/
int yylex();

extern int lineNumber; //!< External line counter


/***********************************************************/
/* NEW in example 2 */
extern std::string progname; //!<  Program name
/***********************************************************/

%}

/* In case of a syntactic error, more information is shown */
/* DEPRECATED */
/* %error-verbose */

/* ALTERNATIVA a %error-verbose */
%define parse.error verbose

/* Initial grammar symbol */
%start program

/*******************************************/
/* Data type YYSTYPE  */
%union {
  char * string;   
}

/* Defined token */

/* Minimum precedence */

%token SEMICOLON COMMA COLON

%token ENTERO REAL

%token <string> VARIABLE
/*******************************************/

%%

//! \name Grammar rules

program : stmtlist {  }
;

stmtlist:  /* empty: epsilon rule */

        | stmtlist stmt 

        | stmtlist error 
			{
				// The function yyerror is called
				// If %error-verbose is used then an error message is displayed
			}
;
 
/* NEW rules in example 9 */
stmt: list COLON type SEMICOLON
;

list: VARIABLE
	{
		std::cout << "List --> VARIABLE"  << std::endl;
		std::cout <<  BIYELLOW <<  "VARIABLE: " << $1<< RESET << std::endl;
	}
	| list COMMA VARIABLE
	{
		std::cout << "List --> List COMMA VARIABLE"  << std::endl;
		std::cout <<  BIYELLOW << "VARIABLE: " << $3 << RESET << std::endl;
	}

type : ENTERO
		{
			std::cout <<  BIGREEN << "Type: entero"  << RESET << std::endl;
		}
	  |
		REAL
		{
			std::cout <<  BIGREEN << "Type: real"  << RESET << std::endl;
		}
;	



%%

