/*! 
  \file   stringVariable.cpp
  \brief  Code of StringVariable class
  \author  Alicia Muriel Fernández
  \author  Lucía Cañero Moslero
  \date    2026-05-24
  \version 1.0
*/
#include "stringVariable.hpp"

// Constructor
lp::StringVariable::StringVariable(std::string name, int token, int type, std::string value)
    : Variable(name, token, type) 
{
    this->_value = value;
}

// Obtener valor
std::string lp::StringVariable::getValue() const 
{
    return this->_value;
}

// Asignar nuevo valor
void lp::StringVariable::setValue(std::string value) 
{
    this->_value = value;
}