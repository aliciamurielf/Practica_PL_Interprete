/*!	
	\file error.hpp
  	\brief Prototypes of error recovery functions 
	\author  Alicia Muriel Fernández
	\author  Lucía Cañero Moslero
	\date    2026-05-24
	\version 1.0
*/

#ifndef _ERROR_HPP_
#define _ERROR_HPP_

#include <string>

/*! 
	\brief  Parser error recovery function
	\param  errorMessage: Parser error message
	\sa     warning
*/
void yyerror(std::string errorMessage);

/*! 
	\brief  Show the error messages
	\param  errorMessage1: first error message
	\param  errorMessage2: second error message
	\sa     yyerror, execerror
*/
void warning(std::string errorMessage1,std::string errorMessage2);


/*! 
	\brief  Run time error recovery function
	\param  errorMessage1: first error message
	\param  errorMessage2: second error message
	\sa     warning, longjmp
*/
void execerror(std::string errorMessage1,std::string errorMessage2);


/*! 
	\brief  Run time error recovery function
	\param  p: integer parameter identifying the floating point exception
	\sa     warning
*/
void fpecatch(int p);

// NEW in example 13

/*! 
	\brief  Control EDOM or ERANGE errors
	\param  d: double value to check
	\param  s: name of the mathematical function
	\return If an EDOM or ERANGE error has occurred, an error message is displayed; otherwise it returns the value "d"
	\sa     execerror
*/
double errcheck(double d, std::string s);

#endif