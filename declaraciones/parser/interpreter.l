/*! 
  \file interpreter.l
  \brief Lexical or scanner file
*/

%{
#include <iostream>

/* Macros for the screen */
#include "../includes/macros.hpp"

/*  interpreter.tab.h contains the numeric values of the tokens produced by the parser */
#include "interpreter.tab.h"

#include "../error/error.hpp"


extern int lineNumber; //!< External line counter

/* uso de strdup */
#include <string.h>


%}

/* 
  Si se desea no distinguir mayúsculas de minúsculas: 
  1) Versiones anteriores a flex 2.6.4 
     (?i:texto) 
  2) Versión  flex 2.6.4 
    %option case-insensitive 
*/
%option case-insensitive 


/*! \name REGULAR DEFINITIONS  */

DIGIT  [0-9]
LETTER [a-zA-Z]

IDENTIFIER  {LETTER}({LETTER}|{DIGIT})*


/* STATE  */
%x ERROR

/*! \name REGULAR EXPRESSIONS  */
%%

[ \t] 	{ ; }    /* skip white space and tabular */

\n      { 
			/* Line counter */
           	lineNumber++; 
        }

","		{
			return COMMA;
		}	

":"		{
			return COLON;
		}

";"		{
			return SEMICOLON;
		}

entero 			{return ENTERO;}		

real			{return REAL;}		


{IDENTIFIER}   	{

						/* 
                          strdup() function returns a pointer to a new string 
                          which  is a duplicate of the string yytext
                        */
						  yylval.string =  strdup(yytext);

						/* The identifier is returned as VARIABLE */
						return VARIABLE;
				}



<<EOF>> { /* The interpreter finishes when finds the end of file character */
		//  PLACE(24,10);
	  	  std::cout <<  BICYAN;
	   	  std::cout <<  ">>>>>>> End of program <<<<<<<";
	 	  std::cout << std::endl;
	   	  std::cout << RESET;
		 // PLACE(25,1);

	  	  return 0;
	}

.								{ 	
									/* Any other character */
									/* MODIFIIED in example 3 */
									/* Change to error state */
									BEGIN(ERROR); 

									/* 
										The current value of yytext 
										will be concatenated with the next character
									*/
									yymore();  
								}

<ERROR>[^ \t\n\0-9a-zA-Z,;:]	{ 
								  /* 
									The current value of yytext 
									will be concatenated with the next character
								  */
									yymore(); 
								}

<ERROR>(.|\n)                { 
								/* Rewind one position */
								yyless(yyleng-1); 

								/* Display the error message */
								warning("Lexical error", yytext);

								/* Restore the initial state */
   								BEGIN(INITIAL);
							}
%%


