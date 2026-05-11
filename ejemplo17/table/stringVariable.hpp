/*!	
	\file    stringVariable.cpp
	\brief   Code of some functions of StringVariable class
	\author  Alicia Muriel Fernández
	\author  Lucía Cañero Moslero
	\date    2026-05-24
	\version 1.0
*/




#ifndef _STRINGVARIABLE_HPP_
#define _STRINGVARIABLE_HPP_

#include <string>
#include <iostream>
#include "variable.hpp"

namespace lp {

class StringVariable : public lp::Variable
{
    private:
        std::string _value; 

    public:
        inline StringVariable(std::string name="", int token = 0, int type = 0, std::string value=""): 
        Variable(name, token, type)
        {
            this->setValue(value);
        }

        inline std::string getValue() const
        {
            return this->_value;
        }

        inline void setValue(const std::string & value)
        {
            this->_value = value;
        }

        void read() {
            std::cin >> std::ws;
            std::getline(std::cin, _value);
        }

        void write() const {
            std::cout << _value;
        }
};

}

#endif