/*!	
	\file   init.hpp
	\brief   Prototype of the function for the initialization of table of symbols
	\author  Alicia Muriel Fernández
	\author  Lucía Cañero Moslero
	\date    2026-05-24
	\version 1.0
*/

#ifndef _INIT_HPP_
#define _INIT_HPP_

// sin, cos, atan, fabs, ...
#include <math.h>

#include "table.hpp"

// IMPORTANT: This file must be before y.tab.h
#include "../ast/ast.hpp"
///////////////////////////////////////

//  interpreter.tab.h contains the number values of the tokens produced by the parser
#include "../parser/interpreter.tab.h"

///////////////////////////////////////
// NEW in example 13
#include "mathFunction.hpp"
#include "builtinParameter1.hpp"
///////////////////////////////////////

///////////////////////////////////////
// NEW in example 14
#include "builtinParameter0.hpp"
#include "builtinParameter2.hpp"
///////////////////////////////////////

/*!
  \ brief Predefined numeric constants
*/
static struct {
          std::string name ;
	      double value;
	      } numericConstant[] = {
	                    {"pi",    3.14159265358979323846},
	                    {"e",     2.71828182845904523536},
	                    {"gamma", 0.57721566490153286060},
	                    {"deg",  57.29577951308232087680},
	                    {"phi",   1.61803398874989484820},
	                    {"",      0}
	                   };

/*!
  \ brief Predefined logical constants
*/
static struct {
          std::string name ;
	      bool value;
	      } logicalConstant[] = { 
	                    {"true", true},
	                    {"false", false},
	                    {"",      0}
	                   };


/*!
  \ brief Predefined keywords
*/
static struct {
          std::string name ;
	      int token;
	      } keyword[] = { 
	                    {"if", IF},
                		{"then", THEN},
                		{"else", ELSE},
                		{"end_if", END_IF},
                		{"while", WHILE},
                		{"do", DO},
                		{"end_while", END_WHILE},
                		{"for", FOR},
                		{"from", FROM},
                		{"to", TO},
                		{"step", STEP},
                		{"end_for", END_FOR},
                		{"repeat", REPEAT},
                		{"until", UNTIL},
						{"mod", MODULO},
						{"and", AND},
						{"or", OR},
						{"not", NOT},
                		{"read", READ},
                		{"print", PRINT},
                		{"read_string", READ_STRING},      
                		{"clear_screen", CLEAR_SCREEN_CMD}, 
                		{"place", PLACE_CMD},  
						{"switch", SWITCH},
                		{"case", CASE},
                		{"default", DEFAULT},
                		{"end_switch", END_SWITCH},
						{ "red_text", RED_TEXT },
						{ "green_text", GREEN_TEXT },
						{ "blue_text", BLUE_TEXT },
						{ "yellow_text", YELLOW_TEXT },
						{ "reset_text", RESET_TEXT },
						{"factorial", FACTORIAL_KW},
                		{"", 0} 
	                   };

/*! \var function_1 
	\brief Predefined functions with 1 parameter 
*/
static struct {    /* Predefined functions names */ 
                std::string name ;
				lp::TypePointerDoubleFunction_1 function;
              } function_1 [] = {
	                   {"sin",     sin},
		               {"cos",     cos},
		               {"atan",    atan},
		               {"log",     Log},
		               {"log10",   Log10},
		               {"exp",     Exp},
		               {"sqrt",    Sqrt},
		               {"integer", integer},
		               {"abs",     fabs},  
		               {"",       0}
		              };

/*! \var function_0 
	\brief Predefined functions with 0 parameters 
*/
static struct {   
                std::string name ;
				lp::TypePointerDoubleFunction_0 function;
              } function_0 [] = {
						{"random", Random},
		                {"",       0}
		              };


/*! \var function_2 
	\brief Predefined functions with 2 parameters
*/
static struct {    /* Nombres predefinidos de funciones con 2 argumentos */ 
                std::string name ;
				lp::TypePointerDoubleFunction_2 function;
              } function_2 [] = {
	                   {"atan2",   Atan2},
		               {"",       0}
		              };
/*!		
	\brief   Initialize the table of symbols
	\param   t: Reference to the table of symbols
*/
void init(lp::Table &t);

// End of _INIT_HPP_
#endif
