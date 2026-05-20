/*!	
	\file    stringVariable.hpp
	\brief   Declaration of StringVariable class
	\author  Alicia Muriel Fernández
	\author  Lucía Cañero Moslero
	\date    2026-05-24
	\version 1.0
*/
#ifndef _STRINGVARIABLE_HPP_
#define _STRINGVARIABLE_HPP_

#include <string>
#include "variable.hpp"

namespace lp {

    /*! 
      \class   StringVariable
      \brief   Definition of atributes and methods of StringVariable class
      \note    StringVariable Class publicly inherits from Variable class
    */
    class StringVariable : public Variable {
        private:
            std::string _value; //!< \brief String value of the variable

        public:
            /*! 
              \brief Constructor of StringVariable
              \param name: name of the variable
              \param token: token of the variable
              \param type: type of the variable (STRING)
              \param value: string value
            */
            StringVariable(std::string name, int token, int type, std::string value);

            /*! 
              \brief  Get the value of the StringVariable
              \return std::string
            */
            std::string getValue() const;

            /*! 
              \brief  Set the value of the StringVariable
              \param  value: new string value
            */
            void setValue(std::string value);
    };
}

#endif