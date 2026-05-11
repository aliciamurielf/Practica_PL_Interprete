/*! 
  \file interpreter.cpp
  \brief Main program
*/

/*!
 \mainpage Flex and Bison: ejemplo de declaraciones de variables de tipo entero y real
 \author   
 \date     2026 - 04 - 17
 \version  1.0
 \note 
	+ New sentences: print and read 
 
*/

#include <stdio.h>
#include <string>
//

#include "./parser/interpreter.tab.h"

int lineNumber = 1; //!< Line counter


extern FILE * yyin; //!< Standard input device for yylex() 
std::string progname; //!<  Program name
//


// Use for recovery of runtime errors 
#include <setjmp.h>
#include <signal.h>

// Error recovery functions 
#include "error/error.hpp"


//////////////////////////////////////////////

//! \name Main program

/*! 
	\brief  Main function
	\param  argc: number of command line parameters
	\param  argv: values of command line parameters
	\return int
	\note   C++ requires that main returns an int value
	\sa     yyparse, yylex
*/
int main(int argc, char *argv[])
{
	/* Option -t needed to debug */
    /* 1, on; 0, off */
	yydebug = 0; 
 
	/*****************************************/
	/* 
		If the input file exists 
	      then 
    	       it is set as input device for yylex();
		otherwise
            the input device is the keyboard (stdin)
	*/
	if (argc == 2) 
    	 yyin = fopen(argv[1],"r");

	/* Copy the name of the interpreter */
	progname = argv[0];

	/* Parser function */
	yyparse();

	/* End of program */
	return 0;
}


