/*!	
	\file    ast.hpp
	\brief   Declaración de la clase AST
	\author  Alicia Muriel Fernández
	\author  Lucía Cañero Moslero
	\date    2026-05-24
	\version 1.0
*/

#ifndef _AST_HPP_
#define _AST_HPP_

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>


#define ERROR_BOUND 1.0e-6  //!< Margen de error para la comparación de números reales.

namespace lp
{
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/*!	
  \class   ExpNode
  \brief   Definición de atributos y métodos de la clase ExpNode
  \warning Clase abstracta
*/
 class ExpNode 
{
  public:
	/*!	
		\brief   Tipo de la expresión
		\warning Función virtual pura: debe redefinirse en las clases derivadas
		\return  int
		\sa		   printAST, evaluateNumber, evaluateBool
	*/
    virtual int getType() = 0;


	/*!	
		\brief   Imprime el AST de la expresión
		\warning Función virtual pura: debe redefinirse en las clases derivadas
		\sa		   getType, evaluateNumber, evaluateBool
	*/
    virtual void printAST() = 0;

	/*!	
		\brief   Evalúa la expresión como NUMBER
		\warning Función virtual: puede redefinirse en las clases derivadas
		\return  double
		\sa		   getType, printAST, evaluateBool
	*/
    virtual double evaluateNumber()
	{
		return 0.0;
	}		

	/*!	
		\brief   Evalúa la expresión como BOOL
		\warning Función virtual: puede redefinirse en las clases derivadas
		\return  bool
		\sa		   getType, printAST, evaluateNumber
	*/
    virtual bool evaluateBool()
	{
		return false;
	}

	/*! 
        \brief   Evalúa la expresión como STRING
        \warning Función virtual: puede redefinirse en las clases derivadas
        \return  std::string
        \sa      evaluateNumber, evaluateBool
    */
	virtual std::string evaluateString(){ return ""; }

};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class VariableNode
  \brief Definición de atributos y métodos de la clase VariableNode
  \note  La clase VariableNode hereda públicamente de ExpNode
*/
class VariableNode : public ExpNode 
{
	private:
	  std::string _id; //!< Nombre del VariableNode

	public:

	/*!		
		\brief Constructor de VariableNode
		\param value Valor numérico del parámetro
		\post  Se crea un nuevo NumericVariableNode con el nombre del parámetro
		\note Función en línea
	*/
	  VariableNode(std::string const & value)
		{
			this->_id = value; 
		}

	/*!	
		\brief   Tipo de la variable
		\return  int
		\sa		   printAST
	*/
	 int getType();

	/*!
		\brief   Imprime el AST de la variable
		\sa		   getType, evaluateNumber, evaluateBool
	*/
	  void printAST();

	/*!	
		\brief   Evalúa la variable como NUMBER
		\return  double
		\sa		   printAST
	*/
	  double evaluateNumber();

	/*!	
		\brief   Evalúa la variable como BOOL
		\return  bool
		\sa		   getType, printAST, evaluateNumber
	*/
	  bool evaluateBool();

	  /*! 
        \brief   Evalúa la variable como STRING
        \return  std::string
        \sa      getType, printAST, evaluateNumber, evaluateBool
    */
	  std::string evaluateString();

};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class ConstantNode
  \brief Definición de atributos y métodos de la clase ConstantNode
  \note  La clase ConstantNode hereda públicamente de ExpNode
*/
class ConstantNode : public ExpNode 
{
	private:
	  std::string _id; //!< Nombre del ConstantNode

	public:

	/*!		
		\brief Constructor de ConstantNode
		\param value Valor numérico del parámetro
		\post  Se crea un nuevo ConstantNode con el valor del parámetro
	*/
	  ConstantNode(std::string value)
		{
			this->_id = value; 
		}

	/*!	
		\brief   Tipo de la constante
		\return  int
		\sa		   printAST, evaluateNumber, evaluateBool
	*/
	 int getType();

	/*!
		\brief   Imprime el AST de la constante
		\sa		   getType, evaluateNumber, evaluateBool
	*/
	  void printAST();

	/*!	
		\brief   Evalúa la constante como NUMBER
		\return  double
		\sa		   getType, printAST, 
	*/
	  double evaluateNumber();

	/*!	
		\brief   Evalúa la constante como BOOL
		\return  bool
		\sa		   getType, printAST, evaluateNumber, evaluateBool
	*/
	  bool evaluateBool();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class NumberNode
  \brief Definición de atributos y métodos de la clase NumberNode
  \note  La clase NumberNode hereda públicamente de ExpNode
*/
class NumberNode : public ExpNode 
{
 private: 	
   double _number; //!< \brief número del NumberNode
 
 public:

/*!		
	\brief Constructor de NumberNode
	\param value Valor numérico del parámetro
	\post  Se crea un nuevo NumberNode con el valor del parámetro
	\note Función en línea
*/
  NumberNode(double value)
	{
	    this->_number = value;
	}

	/*!	
	\brief   Obtiene el tipo de la expresión: NUMBER
	\return  int
	\sa		   printAST, evaluateNumber
	*/
	int getType();

	/*!
		\brief   Imprime el AST de la expresión
		\sa		   getType, evaluateNumber
	*/
	void printAST();

	/*!	
		\brief   Evalúa la expresión
		\return  double
		\sa		   getType, printAST
	*/
	double evaluateNumber();

	/*! 
    \brief   Evalúa la expresión como STRING
    \return  std::string
    \sa      getType, printAST, evaluateNumber, evaluateBool
*/
	std::string evaluateString();
};

/*! 
  \class   StringNode
  \brief   Definición de atributos y métodos de la clase StringNode
  \note    La clase StringNode hereda públicamente de ExpNode
*/
class StringNode : public ExpNode 
{
  private:
    std::string _value; //!< \brief valor del StringNode

  public:
    /*!     
        \brief Constructor de StringNode
        \param value Cadena de texto
        \post  Se crea un nuevo StringNode con el valor del parámetro
    */
    StringNode(std::string value) { this->_value = value; }

    /*! 
        \brief Obtiene el tipo de la expresión: STRING
        \return  int
    */
    int getType();

    /*!
        \brief Imprime el AST de StringNode    
    */
    void printAST();

    /*! 
        \brief   Evalúa la expresión como STRING
        \return  std::string
    */
    std::string evaluateString();

    /*! 
        \brief   Evalúa la expresión como NUMBER (returns 0.0)
        \return  double
    */
    double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   UnaryOperatorNode
  \brief   Definición de atributos y métodos de la clase UnaryOperatorNode
  \note    La clase UnaryOperatorNode hereda públicamente de ExpNode
  \warning Clase abstracta, porque no redefine el método printAST de ExpNode
*/
class UnaryOperatorNode : public ExpNode 
{
 protected:
  ExpNode *_exp;  //!< Expresión hija

 public:

/*!		
	\brief El constructor de UnaryOperatorNode enlaza el nodo con su hijo,
           and stores the character representation of the operator.
	\param expression Puntero a ExpNode
	\post  Se crea un nuevo OperatorNode con los parámetros
	\note Función en línea
*/
  UnaryOperatorNode(ExpNode *expression)
	{
		this->_exp = expression;
	}

	/*!	
	\brief   Obtiene el tipo de la expresión hija
	\return  int
	\sa		   printAST
	*/
	inline int getType()
	{
		return this->_exp->getType();
	}
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   NumericUnaryOperatorNode
  \brief   Definición de atributos y métodos de la clase UnaryOperatorNode
  \note La clase UnaryOperatorNode hereda públicamente de UnaryOperatorNode
  \warning Clase abstracta, porque no redefine el método printAST de ExpNode
*/
class NumericUnaryOperatorNode : public UnaryOperatorNode 
{
 public:

/*!		
	\brief El constructor de NumericUnaryOperatorNode usa el constructor de UnaryOperatorNode como inicializador de miembro
	\param expression Puntero a ExpNode
	\post Se crea un nuevo NumericUnaryOperatorNode con parámetros
	\note Función en línea
*/
  NumericUnaryOperatorNode(ExpNode *expression): UnaryOperatorNode(expression)
	{
		// Empty
	}

	/*!	
	\brief   Obtiene el tipo de la expresión hija
	\return  int
	\sa		   printAST
	*/
	int getType();

};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   LogicalUnaryOperatorNode
  \brief   Definición de atributos y métodos de la clase UnaryOperatorNode
  \note La clase UnaryOperatorNode hereda públicamente de UnaryOperatorNode
  \warning Clase abstracta, porque no redefine el método printAST de ExpNode
*/
class LogicalUnaryOperatorNode : public UnaryOperatorNode 
{
 public:

/*!		
	\brief El constructor de LogicalUnaryOperatorNode usa el constructor de UnaryOperatorNode como inicializador de miembro
	\param expression Puntero a ExpNode
	\post Se crea un nuevo NumericUnaryOperatorNode con parámetros
	\note Función en línea
*/
  LogicalUnaryOperatorNode(ExpNode *expression): UnaryOperatorNode(expression)
	{
		// Empty
	}

	/*!	
	\brief   Obtiene el tipo de la expresión hija
	\return  int
	\sa		   printAST
	*/
	int getType();

};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   UnaryMinusNode
  \brief   Definición de atributos y métodos de la clase UnaryMinusNode
  \note    La clase UnaryMinusNode hereda públicamente de NumericUnaryOperatorNode
*/
class UnaryMinusNode : public NumericUnaryOperatorNode 
{

 public:

/*!		
	\brief El constructor de UnaryMinusNode usa el constructor de NumericUnaryOperatorNode como inicializador de miembro.
	\param expression Puntero a ExpNode
	\post  Se crea un nuevo UnaryMinusNode con el parámetro
	\note: función en línea; el constructor de NumericUnaryOperatorNode se usa como inicializador de miembro
*/
  UnaryMinusNode(ExpNode *expression): NumericUnaryOperatorNode(expression) 
	{
		// empty
	} 

/*!
	\brief   Imprime el AST de la expresión	
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evalúa la expresión
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*!	
  \class   UnaryPlusNode
  \brief   Definición de atributos y métodos de la clase UnaryPlusNode
  \note    La clase UnaryPlusNode hereda públicamente de NumericUnaryOperatorNode
*/
class UnaryPlusNode : public NumericUnaryOperatorNode 
{

 public:

/*!		
	\brief El constructor de UnaryPlusNode usa el constructor de NumericUnaryOperatorNode como inicializador de miembro
	\param expression Puntero a ExpNode
	\post  Se crea un nuevo UnaryPlusNode con el parámetro
*/
  UnaryPlusNode(ExpNode *expression): NumericUnaryOperatorNode(expression) 
	{
		// empty
	} 

/*!
	\brief   Imprime el AST de la expresión
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evalúa la expresión
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   OperatorNode
  \brief   Definición de atributos y métodos de la clase OperatorNode
  \note    La clase OperatorNode hereda públicamente de ExpNode
  \warning Clase abstracta, porque no redefine los métodos printAST y getType de ExpNode
*/
class OperatorNode : public ExpNode 
{
	protected:
		ExpNode *_left;    //!< Expresión izquierda
		ExpNode *_right;   //!< Expresión derecha

	public:
	/*!		
		\brief El constructor de OperatorNode enlaza el nodo con sus hijos,
		\param L Puntero a ExpNode
		\param R Puntero a ExpNode
		\post  Se crea un nuevo OperatorNode con los parámetros
	*/
    OperatorNode(ExpNode *L, ExpNode *R)
	{
	    this->_left  = L;
    	this->_right = R;
	}

};



//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   NumericOperatorNode
  \brief   Definición de atributos y métodos de la clase NumericOperatorNode
  \note La clase NumericOperatorNode hereda públicamente de OperatorNode
  \warning Clase abstracta, porque no redefine el método printAST de ExpNode
*/
class NumericOperatorNode : public OperatorNode 
{
	public:

	/*!		
		\brief El constructor de NumericOperatorNode usa el constructor de OperatorNode como inicializador de miembro
		\param L Puntero a ExpNode
		\param R Puntero a ExpNode
		\post Se crea un nuevo NumericOperatorNode con parámetros
	*/
    NumericOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R) 
	{
		//	Empty
	}

	/*!	
	\brief Obtiene el tipo de las expresiones hijas
	\return  int
	*/
	int getType();
};



//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   RelationalOperatorNode
  \brief   Definición de atributos y métodos de la clase RelationalOperatorNode
  \note La clase RelationalOperatorNode hereda públicamente de OperatorNode
  \warning Clase abstracta, porque no redefine el método printAST de ExpNode
*/
class RelationalOperatorNode : public OperatorNode 
{
public:
/*!		
	\brief El constructor de RelationalOperatorNode usa el constructor de OperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo RelationalOperatorNode con parámetros
*/
    RelationalOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R) 
	{
		//	Empty
	}

	/*!	
	\brief Obtiene el tipo de las expresiones hijas
	\return  int
	*/
	int getType();

};


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   LogicalOperatorNode
  \brief   Definición de atributos y métodos de la clase LogicalOperatorNode
  \note La clase NumericOperatorNode hereda públicamente de OperatorNode
  \warning Clase abstracta, porque no redefine el método printAST de ExpNode
*/
class LogicalOperatorNode : public OperatorNode 
{
	public:

	/*!		
		\brief El constructor de LogicalOperatorNode usa el constructor de OperatorNode como inicializador de miembro
		\param L Puntero a ExpNode
		\param R Puntero a ExpNode
		\post Se crea un nuevo NumericOperatorNode con parámetros
	*/
    LogicalOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R) 
	{
		//	Empty
	}

	/*!	
	\brief Obtiene el tipo de las expresiones hijas
	\return  int
	*/
	int getType();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   PlusNode
  \brief   Definición de atributos y métodos de la clase PlusNode
  \note La clase PlusNode hereda públicamente de NumericOperatorNode 
		   y añade sus propios métodos printAST y evaluate
*/
class PlusNode : public NumericOperatorNode 
{
  public:
/*!		
	\brief El constructor de PlusNode usa el constructor de NumericOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo PlusNode con el parámetro
*/
  PlusNode(ExpNode *L, ExpNode *R) : NumericOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief Imprime el AST de PlusNode	
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evalúa PlusNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

/*! 
  \class   ConcatenationNode
  \brief   Definición de atributos y métodos de la clase ConcatenationNode
  \note    ConcatenationNode hereda públicamente de OperatorNode
*/
class ConcatenationNode : public OperatorNode 
{
  public:
    /*!     
        \brief El constructor de ConcatenationNode usa el constructor de OperatorNode como inicializador de miembro
        \param L Puntero a ExpNode
        \param R Puntero a ExpNode
        \post Se crea un nuevo ConcatenationNode con parámetros
    */
    ConcatenationNode(ExpNode *L, ExpNode *R) : OperatorNode(L,R) {}

    /*! 
        \brief   Obtiene el tipo de la concatenación: STRING
        \return  int
    */
    int getType();

    /*!
        \brief Imprime el AST de ConcatenationNode     
    */
    void printAST();

    /*! 
        \brief   Evalúa ConcatenationNode as STRING
        \return  std::string
    */
    std::string evaluateString();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   MinusNode
  \brief   Definición de atributos y métodos de la clase MinusNode
  \note La clase MinusNode hereda públicamente de NumericOperatorNode 
		       y añade sus propios métodos printAST y evaluate
*/
class MinusNode : public NumericOperatorNode 
{
  public:

/*!		
	\brief El constructor de MinusNode usa el constructor de NumericOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo MinusNode con el parámetro
*/
  MinusNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief   Imprime el AST de MinusNode
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evalúa MinusNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   MultiplicationNode
  \brief   Definición de atributos y métodos de la clase MultiplicationNode
  \note La clase MultiplicationNode hereda públicamente de NumericOperatorNode 
		   y añade sus propios métodos printAST y evaluate
*/
class MultiplicationNode : public NumericOperatorNode 
{
  public:

/*!		
	\brief El constructor de MultiplicationNode usa el constructor de NumericOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo MultiplicationNode con el parámetro
*/
  MultiplicationNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief   Imprime el AST de MultiplicationNode
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evalúa MultiplicationNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   DivisionNode
  \brief   Definición de atributos y métodos de la clase DivisionNode
  \note La clase DivisionNode hereda públicamente de NumericOperatorNode 
		   y añade sus propios métodos printAST y evaluate
*/
class DivisionNode : public NumericOperatorNode 
{
  public:
/*!		
	\brief El constructor de DivisionNode usa el constructor de NumericOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo DivisionNode con el parámetro
*/
  DivisionNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief   Imprime el AST de DivisionNode
	\sa		   evaluateNumber
*/
  void printAST();

/*! 
    \brief   Obtiene el tipo del DivisionNode: NUMBER
    \return  int
 */
	int getType();

/*!	
	\brief   Evalúa DivisionNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();

  
};

/*!	
  \class   IntegerDivisionNode
  \brief   Definición de atributos y métodos de la clase IntegerDivisionNode
  \note    IntegerDivisionNode hereda públicamente de NumericOperatorNode
*/
class IntegerDivisionNode : public NumericOperatorNode 
{
  public:
  /*! 
      \brief Constructor de IntegerDivisionNode 
      \param L Expresión izquierda
      \param R Expresión derecha
  */
  IntegerDivisionNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) {}
  
  /*! \brief Imprime el AST de la división entera */
  void printAST();
  /*! \brief Obtiene el tipo de resultado */
  int getType();
  /*! \brief Evalúa la división entera */
  double evaluateNumber();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   ModuloNode
  \brief   Definición de atributos y métodos de la clase ModuloNode
  \note La clase ModuloNode hereda públicamente de NumericOperatorNode 
		   y añade sus propios métodos printAST y evaluate
*/
class ModuloNode : public NumericOperatorNode 
{
  public:
/*!		
	\brief El constructor de ModuloNode usa el constructor de NumericOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo ModuloNode con el parámetro
*/
  ModuloNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief   Imprime el AST de ModuloNode	
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evalúa ModuloNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   PowerNode
  \brief   Definición de atributos y métodos de la clase PowerNode
  \note La clase PowerNode hereda públicamente de NumericOperatorNode 
		   y añade sus propios métodos printAST y evaluate
*/
class PowerNode : public NumericOperatorNode 
{
  public:
/*!		
	\brief El constructor de PowerNode usa el constructor de NumericOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo PowerNode con el parámetro
*/
  PowerNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief Imprime el AST de PowerNode
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evalúa PowerNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   BuiltinFunctionNode
  \brief   Definición de atributos y métodos de la clase BuiltinFunctionNode
  \note La clase BuiltinFunctionNode hereda públicamente de ExpNode 
*/
class BuiltinFunctionNode : public ExpNode 
{
  protected: 
	std::string _id; //!< Nombre del BuiltinFunctionNode
	
  public:
/*!		
	\brief Constructor de BuiltinFunctionNode
	\param id Cadena con el nombre de la función builtin
	\post Se crea un nuevo BuiltinFunctionNode con el parámetro
*/
  BuiltinFunctionNode(std::string id)
	{
		this->_id = id;
	}

};




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   BuiltinFunctionNode_0
  \brief   Definición de atributos y métodos de la clase BuiltinFunctionNode_0
  \note La clase BuiltinFunctionNode_0 hereda públicamente de BuiltinFunctionNode 
		   y añade sus propios métodos printAST y evaluate
*/
class BuiltinFunctionNode_0 : public BuiltinFunctionNode 
{
  public:
/*!		
	\brief El constructor de BuiltinFunctionNode_0 usa el constructor de BuiltinFunctionNode como inicializador de miembro
	\param id Cadena con el nombre de la función builtin
	\post Se crea un nuevo BuiltinFunctionNode_2 con el parámetro
*/
  BuiltinFunctionNode_0(std::string id): BuiltinFunctionNode(id)
	{
		// 
	}

	/*!	
		\brief   Obtiene el tipo de la expresión hija:
		\return  int
		\sa		   printAST, evaluateNumber
	*/
	int getType();



	/*!
		\brief Imprime el AST de BuiltinFunctionNode_0		
		\sa		   getType, evaluateNumber
	*/
	  void printAST();

	/*!	
		\brief   Evalúa BuiltinFunctionNode_0
		\return  double
		\sa		   getType, printAST
	*/
	  double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   BuiltinFunctionNode_1
  \brief   Definición de atributos y métodos de la clase BuiltinFunctionNode_1
  \note La clase BuiltinFunctionNode_1 hereda públicamente de BuiltinFunctionNode 
		   y añade sus propios métodos printAST y evaluate
*/
class BuiltinFunctionNode_1: public BuiltinFunctionNode 
{
  private:
	ExpNode *_exp;  //!< Argumento de BuiltinFunctionNode_1

  public:
/*!		
	\brief El constructor de BuiltinFunctionNode_1 usa el constructor de BuiltinFunctionNode como inicializador de miembro
	\param id Cadena con el nombre de la función builtin
	\param expression Puntero a ExpNode, argumento de BuiltinFunctionNode_1
	\post Se crea un nuevo BuiltinFunctionNode_1 con parámetros
*/
  BuiltinFunctionNode_1(std::string id, ExpNode *expression): BuiltinFunctionNode(id)
	{
		this->_exp = expression;
	}

	/*!	
		\brief   Obtiene el tipo de la expresión hija:
		\return  int
		\sa		   printAST, evaluateNumber
	*/
	int getType();

	/*!
		\brief Imprime el AST de BuiltinFunctionNode_1
		\sa		   getType, evaluateNumber
	*/
	  void printAST();

	/*!	
		\brief   Evalúa BuiltinFunctionNode_1
		\return  double
		\sa		   getType, printAST
	*/
	  double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   BuiltinFunctionNode_2
  \brief   Definición de atributos y métodos de la clase BuiltinFunctionNode_2 
  \note La clase BuiltinFunctionNode_2 hereda públicamente de BuiltinFunctionNode 
		   y añade sus propios métodos printAST y evaluate
*/
class BuiltinFunctionNode_2 : public BuiltinFunctionNode 
{
	private:
		ExpNode *_exp1; //!< Primer argumento de BuiltinFunction_2
		ExpNode *_exp2; //!< Segundo argumento de BuiltinFunction_2

	public:
	/*!		
		\brief El constructor de BuiltinFunctionNode_2 usa el constructor de BuiltinFunctionNode como inicializador de miembro
		\param id Cadena con el nombre de la función builtin_2
		\param expression1 Puntero a ExpNode, primer argumento de BuiltinFunctionNode_2
		\param expression2 Puntero a ExpNode, segundo argumento de BuiltinFunctionNode_2
		\post Se crea un nuevo BuiltinFunctionNode_2 con parámetros
	*/
	  BuiltinFunctionNode_2(std::string id,ExpNode *expression1,ExpNode *expression2): BuiltinFunctionNode(id)
	{
		this->_exp1 = expression1;
		this->_exp2 = expression2;
	}

	/*!	
	\brief Obtiene el tipo de las expresiones hijas
	\return  int
	\sa		   printAST. evaluateNumber
	*/
	int getType();



	/*!
		\brief Imprime el AST de BuiltinFunctionNode_2	
		\sa		   getType, evaluateNumber
	*/
	  void printAST();

	/*!	
		\brief   Evalúa BuiltinFunctionNode_2
		\return  double
		\sa		   getType, printAST
	*/
	  double evaluateNumber();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   GreaterThanNode
  \brief   Definición de atributos y métodos de la clase GreaterThanNode
  \note La clase GreaterThanNode hereda públicamente de RelationalOperatorNode 
		   y añade sus propios métodos printAST y evaluate
*/
class GreaterThanNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief El constructor de GreaterThanNode usa el constructor de RelationalOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo GreaterThanNode con el parámetro
*/
  GreaterThanNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }


/*!
	\brief Imprime el AST de GreaterThanNode	
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evalúa GreaterThanNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   GreaterOrEqualNode
  \brief   Definición de atributos y métodos de la clase GreaterOrEqualNode
  \note La clase GreaterOrEqualNode hereda públicamente de RelationalOperatorNode 
		       y añade sus propios métodos printAST y evaluate
*/
class GreaterOrEqualNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief El constructor de GreaterOrEqualNode usa el constructor de RelationalOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo GreaterOrEqualNode con el parámetro
*/
  GreaterOrEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief Imprime el AST de GreaterOrEqualNode	
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evalúa GreaterOrEqualNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   LessThanNode
  \brief   Definición de atributos y métodos de la clase LessThanNode
  \note La clase LessThanNode hereda públicamente de RelationalOperatorNode 
		   y añade sus propios métodos printAST y evaluate
*/
class LessThanNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief El constructor de LessThanNode usa el constructor de RelationalOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo LessThanNode con el parámetro
*/
  LessThanNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief Imprime el AST de LessThanNode
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evalúa LessThanNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   LessOrEqualNode
  \brief   Definición de atributos y métodos de la clase LessOrEqualNode
  \note La clase LessThanNode hereda públicamente de RelationalOperatorNode 
		       y añade sus propios métodos printAST y evaluate
*/
class LessOrEqualNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief El constructor de LessOrEqualNode usa el constructor de RelationalOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo LessOrEqualNode con el parámetro
*/
  LessOrEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief Imprime el AST de LessOrEqualNode	
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evalúa LessOrEqualNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   EqualNode
  \brief   Definición de atributos y métodos de la clase EqualNode
  \note La clase EqualNode hereda públicamente de RelationalOperatorNode 
		   y añade sus propios métodos printAST y evaluate
*/
class EqualNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief El constructor de EqualNode usa el constructor de RelationalOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo EqualNode con el parámetro
*/
  EqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief Imprime el AST de EqualNode
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evalúa EqualNode
	\return  bool
	\sa		  printAST
*/
  bool evaluateBool();;
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   NotEqualNode
  \brief   Definición de atributos y métodos de la clase NotEqualNode
  \note La clase NotEqualNode hereda públicamente de RelationalOperatorNode 
		   y añade sus propios métodos printAST y evaluate
*/
class NotEqualNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief El constructor de NotEqualNode usa el constructor de RelationalOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo NotEqualNode con el parámetro
*/
  NotEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief Imprime el AST de NotEqualNode
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evalúa NotEqualNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   AndNode
  \brief   Definición de atributos y métodos de la clase AndNode
  \note La clase AndNode hereda públicamente de LogicalOperatorNode 
		       y añade sus propios métodos printAST y evaluate
*/
class AndNode : public LogicalOperatorNode 
{
  public:

/*!		
	\brief El constructor de AndNode usa el constructor de LogicalOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo AndNode con el parámetro
*/
  AndNode(ExpNode *L, ExpNode *R): LogicalOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief Imprime el AST de AndNode
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evalúa AndNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   OrNode
  \brief   Definición de atributos y métodos de la clase OrNode
  \note La clase OrNode hereda públicamente de LogicalOperatorNode 
		       y añade sus propios métodos printAST y evaluate
*/
class OrNode : public LogicalOperatorNode 
{
  public:

/*!		
	\brief El constructor de AndNode usa el constructor de LogicalOperatorNode como inicializador de miembro
	\param L Puntero a ExpNode
	\param R Puntero a ExpNode
	\post Se crea un nuevo AndNode con el parámetro
*/
  OrNode(ExpNode *L, ExpNode *R): LogicalOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief Imprime el AST de OrNode	
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evalúa OrNode
	\return  bool
	\sa		 printAST()
*/
  bool evaluateBool();
};



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*!	
  \class   NotNode
  \brief   Definición de atributos y métodos de la clase UnaryPlusNode
  \note La clase NotNode hereda públicamente de LogicalUnaryOperatorNode
*/
class NotNode : public LogicalUnaryOperatorNode 
{

 public:

/*!		
	\brief El constructor de NotNode usa el constructor de LogicalUnaryOperatorNode como inicializador de miembro
	\param expression Puntero a ExpNode
	\post Se crea un nuevo NotNode con el parámetro
*/
  NotNode(ExpNode *expression): LogicalUnaryOperatorNode(expression) 
	{
		// empty
	} 

/*!
	\brief Imprime el AST de NotNode
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evalúa NotNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   Statement
  \brief   Definición de atributos y métodos de la clase Statement
  \warning Clase abstracta
*/

class Statement {
 public:

/*!	
	\brief Imprime el AST de Statement
	\note    Virtual function: can be redefined in the heir classes
	\sa		   evaluate
*/

  virtual void printAST() {}

/*!	
	\brief   Evalúa Statement
	\warning Función virtual pura: debe redefinirse en las clases derivadas
	\sa		   printAST
*/
  virtual void evaluate() = 0;
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   AssignmentStmt
  \brief   Definición de atributos y métodos de la clase AssignmentStmt
  \note La clase AssignmentStmt hereda públicamente de Statement 
		   y añade sus propios métodos printAST y evaluate
*/
class AssignmentStmt : public Statement 
{
 private:
  std::string _id; //!< Nombre de la variable de la sentencia de asignación
  ExpNode *_exp; 	 //!< Expresión de la sentencia de asignación

  AssignmentStmt *_asgn;  //!< Permite asignaciones múltiples -> a = b = 2 

 public:

/*!		
	\brief Constructor de AssignmentStmt 
	\param id Cadena con el nombre de la variable de AssignmentStmt
	\param expression Puntero a ExpNode
	\post Se crea un nuevo AssignmentStmt con parámetros
*/
  AssignmentStmt(std::string id, ExpNode *expression): _id(id), _exp(expression)
	{
		this->_asgn = NULL; 
	}

/*!		
	\brief Constructor de AssignmentStmt 
	\param id Cadena con el nombre de la variable de AssignmentStmt
	\param asgn Puntero a AssignmentStmt
	\post Se crea un nuevo AssignmentStmt con parámetros
	\note  Allow multiple assigment -> a = b = 2 
*/

  AssignmentStmt(std::string id, AssignmentStmt *asgn): _id(id), _asgn(asgn)
	{
		this->_exp = NULL;
	}


/*!
	\brief Imprime el AST de AssignmentStmt
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evalúa AssignmentStmt
	\sa		   printAST
*/
    void evaluate();

};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   PrintStmt
  \brief   Definición de atributos y métodos de la clase PrintStmt
  \note La clase PrintStmt hereda públicamente de Statement 
		   y añade sus propios métodos print y evaluate
  \warning  En esta clase, printAST y evaluate tienen el mismo significado.
*/
class PrintStmt: public Statement 
{
 private:
  ExpNode *_exp; //!< Expresión de la sentencia print

 public:
/*!		
	\brief Constructor de PrintStmt 
	\param expression Puntero a ExpNode
	\post Se crea un nuevo PrintStmt con el parámetro
*/
  PrintStmt(ExpNode *expression)
	{
		this->_exp = expression;
	}

/*!
	\brief Imprime el AST de PrintStmt
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evalúa PrintStmt
	\sa		   printAST
*/
  void evaluate();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   ReadStmt
  \brief   Definición de atributos y métodos de la clase ReadStmt
  \note La clase ReadStmt hereda públicamente de Statement 
		   y añade sus propios métodos printAST y evaluate
*/
class ReadStmt : public Statement 
{
  private:
	std::string _id; //!< Nombre del ReadStmt
	

  public:
/*!		
	\brief Constructor de ReadStmt
	\param id Cadena con el nombre de la variable de ReadStmt
	\post Se crea un nuevo ReadStmt con el parámetro
*/
  ReadStmt(std::string id)
	{
		this->_id = id;
	}

/*!
	\brief Imprime el AST de ReadStmt
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evalúa ReadStmt
	\sa		   printAST
*/
  void evaluate();
};

/*!	
  \class   ReadStringStmt
  \brief   Definición de atributos y métodos de la clase ReadStringStmt
  \note    Hereda públicamente de Statement
*/
class ReadStringStmt : public Statement 
{
  private:
    std::string _id;  /*!< Nombre de la variable donde se lee la cadena */

  public:
    /*! 
        \brief Constructor de ReadStringStmt
        \param id Nombre de la variable
    */
    ReadStringStmt(std::string id) { this->_id = id; }

    /*! \brief Imprime el AST de lectura de cadena */
    void printAST();
    /*! \brief Ejecuta la lectura por teclado de la cadena */
    void evaluate();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   EmptyStmt
  \brief   Definición de atributos y métodos de la clase EmptyStmt
  \note La clase EmptyStmt hereda públicamente de Statement 
		   y añade sus propios métodos printAST y evaluate
*/
class EmptyStmt : public Statement 
{
  // No attributes

  public:
/*!		
	\brief Constructor de WhileStmt
	\post  A new EmptyStmt is created 
*/
  EmptyStmt()
	{
		// Empty
	}


/*!
	\brief Imprime el AST de EmptyStmt
	
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evalúa EmptyStmt	
	\sa		   printAST
*/
  void evaluate();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

/*!	
  \class   IfStmt
  \brief   Definición de atributos y métodos de la clase IfStmt
  \note La clase IfStmt hereda públicamente de Statement 
		       y añade sus propios métodos printAST y evaluate
*/
class IfStmt : public Statement 
{
 private:
  ExpNode *_cond;    //!< Condición de la sentencia if
  Statement *_stmt1; //!< Sentencia del consecuente
  Statement *_stmt2; //!< Sentencia de la alternativa

  public:
/*!		
	\brief Constructor de Single IfStmt (without alternative)
	\param condition ExpNode de la condición
	\param statement1 Sentencia del consecuente
	\post Se crea un nuevo IfStmt con parámetros
*/
  IfStmt(ExpNode *condition, Statement *statement1)
	{
		this->_cond = condition;
		this->_stmt1 = statement1;
		this->_stmt2 = NULL;
	}


/*!		
	\brief Constructor de Compound IfStmt (with alternative)
	\param condition ExpNode de la condición
	\param statement1 Sentencia del consecuente
	\param statement2 Sentencia de la alternativa
	\post Se crea un nuevo IfStmt con parámetros
*/
  IfStmt(ExpNode *condition, Statement *statement1, Statement *statement2)
	{
		this->_cond = condition;
		this->_stmt1 = statement1;
		this->_stmt2 = statement2;
	}


/*!
	\brief Imprime el AST de IfStmt
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evalúa IfStmt
	\sa	   	 printAST
*/
  void evaluate();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

/*!	
  \class   WhileStmt
  \brief   Definición de atributos y métodos de la clase WhileStmt
  \note La clase WhileStmt hereda públicamente de Statement 
		       y añade sus propios métodos printAST y evaluate
*/
class WhileStmt : public Statement 
{
 private:
  ExpNode *_cond; //!< Condición de la sentencia while
  Statement *_stmt; //!< Sentencia del cuerpo del bucle while

  public:
/*!		
	\brief Constructor de WhileStmt
	\param condition ExpNode de la condición
	\param statement Sentencia del cuerpo del bucle
	\post Se crea un nuevo WhileStmt con parámetros
*/
  WhileStmt(ExpNode *condition, Statement *statement)
	{
		this->_cond = condition;
		this->_stmt = statement;
	}

/*!
	\brief Imprime el AST de WhileStmt
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evalúa WhileStmt	
	\sa	   	 printAST
*/
  void evaluate();
};


///////////////////////////////////////////////////////////////////////////////////////////////
// NUEVO: REPEAT UNTIL STMT

/*!	
  \class   RepeatStmt
  \brief   Definición de atributos y métodos de la clase RepeatStmt
  \note La clase RepeatStmt hereda públicamente de Statement 
*/
class RepeatStmt : public Statement 
{
 private:
   std::list<Statement *> *_stmts; /*!< Sentencias del cuerpo del bucle repeat */
   ExpNode *_cond;                 /*!< Condición de la sentencia repeat */

  public:
  /*! 
      \brief Constructor de RepeatStmt
      \param stmtList Lista de sentencias
      \param condition Condición de parada
  */
  RepeatStmt(std::list<Statement *> *stmtList, ExpNode *condition)
	{
		this->_stmts = stmtList;
        this->_cond = condition;
	}

  /*! \brief Imprime el AST del bucle repeat */
  void printAST();
  /*! \brief Ejecuta el bucle repeat-until */
  void evaluate();
};

///////////////////////////////////////////////////////////////////////////////////////////////
// FOR STMT

/*!	
  \class   ForStmt
  \brief   Definición de atributos y métodos de la clase ForStmt
*/
class ForStmt : public Statement 
{
 private:
   std::string _id;                 /*!< Nombre de la variable de control */
   ExpNode *_from;                  /*!< Valor inicial */
   ExpNode *_to;                    /*!< Valor final */
   ExpNode *_step;                  /*!< Valor de paso */
   std::list<Statement *> *_body;   /*!< Cuerpo del bucle */

  public:
  /*! 
      \brief Constructor de ForStmt
      \param id Variable de control
      \param from Expresión inicial
      \param to Expresión final
      \param step Expresión del paso
      \param body Sentencias del bucle
  */
  ForStmt(std::string id, ExpNode *from, ExpNode *to, ExpNode *step, std::list<Statement *> *body)
	{
        this->_id = id;
		this->_from = from;
        this->_to = to;
        this->_step = step;
        this->_body = body;
	}

  /*! \brief Imprime el AST del bucle for */
  void printAST();
  /*! \brief Ejecuta el bucle for */
  void evaluate();
};

/*!
  \class   CaseStmt
  \brief   Nodo para representar un caso individual dentro de un bloque switch.
  \note    CaseStmt hereda públicamente de Statement.
*/
class CaseStmt : public Statement 
{
 private:
   ExpNode *_exp;      //!< Expresión constante del caso (valor a comparar).
   Statement *_stmt;   //!< Sentencia o bloque de sentencias a ejecutar.

 public:
  /**
   * @brief Constructor de CaseStmt.
   * @param exp Puntero a la expresión del caso.
   * @param stmt Puntero a la sentencia asociada.
   */
  CaseStmt(ExpNode *exp, Statement *stmt) : _exp(exp), _stmt(stmt) {}

  void printAST();
  void evaluate();

  /**
   * @brief Obtiene la expresión del caso para su comparación.
   * @return Puntero al ExpNode del caso.
   */
  ExpNode* getExp() { return _exp; }
};

/*!
  \class   SwitchStmt
  \brief   Nodo para representar la estructura de control de flujo múltiple switch/case/default.
  \note    SwitchStmt hereda públicamente de Statement.
*/
class SwitchStmt : public Statement 
{
 private:
   ExpNode *_cond;                 //!< Expresión de control del switch.
   std::list<CaseStmt *> *_cases;  //!< Lista de ramas "case".
   Statement *_defaultStmt;        //!< Rama "default" opcional (puede ser NULL).

 public:
  /**
   * @brief Constructor de SwitchStmt.
   * @param cond Expresión que se evalúa.
   * @param cases Lista de casos posibles.
   * @param defaultStmt Sentencia para el caso por defecto.
   */
  SwitchStmt(ExpNode *cond, std::list<CaseStmt *> *cases, Statement *defaultStmt = NULL)
	{
        this->_cond = cond;
        this->_cases = cases;
        this->_defaultStmt = defaultStmt;
	}

  void printAST();
  void evaluate();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Class BlockStmt

/*!	
  \class   BlockStmt
  \brief   Definición de atributos y métodos de la clase BlockStmt
  \note La clase BlockStmt hereda públicamente de Statement 
		       y añade sus propios métodos printAST y evaluate
*/
class BlockStmt : public Statement 
{
 private:
   std::list<Statement *> *_stmts;  //!< Lista de sentencias

  public:
/*!		
	\brief Constructor de WhileStmt
	\param stmtList Lista de Statement
	\post Se crea un nuevo BlockStmt con parámetros
*/
  BlockStmt(std::list<Statement *> *stmtList): _stmts(stmtList)
	{
		// Empty
	}


/*!
	\brief Imprime el AST de BlockStmt
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evalúa BlockStmt
	\sa	   	 printAST
*/
  void evaluate();
};

/*!	
  \class   ClearScreenStmt
  \brief   Definición de atributos y métodos de la clase ClearScreenStmt
  \note    Hereda de Statement. Limpia la pantalla de la consola.
*/
class ClearScreenStmt : public Statement 
{
  public:
    /*! \brief Imprime el AST de la limpieza de pantalla */
    void printAST();
    /*! \brief Ejecuta el comando clear_screen */
    void evaluate();
};

/*!	
  \class   PlaceStmt
  \brief   Definición de atributos y métodos de la clase PlaceStmt
  \note    Hereda de Statement. Posiciona el cursor en las coordenadas indicadas.
*/
class PlaceStmt : public Statement 
{
  private:
    ExpNode *_line;   /*!< Línea de la consola */
    ExpNode *_column; /*!< Columna de la consola */

  public:
    /*! 
        \brief Constructor de PlaceStmt
        \param line Expresión de la línea
        \param column Expresión de la columna
    */
    PlaceStmt(ExpNode *line, ExpNode *column)
    {
        this->_line = line;
        this->_column = column;
    }

    /*! \brief Imprime el AST del comando place */
    void printAST();
    /*! \brief Ejecuta el reposicionamiento del cursor */
    void evaluate();
};
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   AST
  \brief   Definición de atributos y métodos de la clase AST
*/
class AST {
 private:
  std::list<Statement *> *stmts;  //!< Lista de sentencias

 public:

/*!		
	\brief Constructor de PrintStmt 
	\param stmtList Puntero a lista de punteros a Statement
	\post Se crea un nuevo PrintStmt con el parámetro
*/
  AST(std::list<Statement *> *stmtList): stmts(stmtList)
	{
		// Empty
	}

/*!
	\brief Imprime el AST
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief Evalúa el AST
	\sa	   	 printAST
*/
  void evaluate();
};

/*! 
  \class   FactorialNode
  \brief   Definición de atributos y métodos de la clase FactorialNode
  \note    Publicly inherits from ExpNode class
*/
class FactorialNode : public ExpNode {
  private:
    ExpNode *_exp; //!< Expresión para calcular el factorial

  public:
    /*!     
        \brief Constructor de FactorialNode
        \param   exp Puntero a la expresión
        \post    A new FactorialNode is created
    */
    FactorialNode(ExpNode *exp) : _exp(exp) {}

    /*! 
        \brief   Obtiene el tipo de la expresión
        \return  int (NUMBER)
        \sa      printAST, evaluateNumber
    */
    int getType();

    /*! 
        \brief Imprime el AST node for the factorial operator
        
        \sa      getType, evaluateNumber
    */
    void printAST() {}

    /*! 
        \brief   Evalúa el factorial de la expresión
        \return  double
        \sa      getType, printAST
    */
    double evaluateNumber();

	/*!
	 \brief   Evalúa el factorial de la expresión as a string
	 \return  std::string
	 \sa      getType, printAST
	*/
	std::string evaluateString();
};

/*! 
  \class   TernaryNode
  \brief   Definición de atributos y métodos de la clase TernaryNode
  \note    Publicly inherits from ExpNode class
*/
class TernaryNode : public ExpNode {
  private:
    ExpNode *_cond; //!< Expresión de condición
    ExpNode *_exp1; //!< Expresión evaluada si la condición es verdadera
    ExpNode *_exp2; //!< Expresión evaluada si la condición es falsa

  public:
    /*!     
        \brief Constructor de TernaryNode
        \param   cond Puntero a la expresión de condición
        \param   e1 Puntero a la expresión verdadera
        \param   e2 Puntero a la expresión falsa
        \post    A new TernaryNode is created
    */
    TernaryNode(ExpNode *cond, ExpNode *e1, ExpNode *e2) : _cond(cond), _exp1(e1), _exp2(e2) {}

    /*! 
        \brief   Obtiene el tipo de la expresión ternaria
        \return  int (Type of the true expression branch)
        \sa      printAST, evaluateNumber, evaluateBool, evaluateString
    */
    int getType() { return this->_exp1->getType(); }

    /*! 
        \brief Imprime el AST node for the ternary operator
        
        \sa      getType
    */
    void printAST() {}

    /*! 
        \brief   Evalúa la expresión ternaria como NUMBER
        \return  double
        \sa      getType, printAST, evaluateBool, evaluateString
    */
    double evaluateNumber() {
        return this->_cond->evaluateBool() ? this->_exp1->evaluateNumber() : this->_exp2->evaluateNumber();
    }

    /*! 
        \brief   Evalúa la expresión ternaria como BOOL
        \return  bool
        \sa      getType, printAST, evaluateNumber, evaluateString
    */
    bool evaluateBool() {
        return this->_cond->evaluateBool() ? this->_exp1->evaluateBool() : this->_exp2->evaluateBool();
    }

    /*! 
        \brief   Evalúa la expresión ternaria como STRING
        \return  std::string
        \sa      getType, printAST, evaluateNumber, evaluateBool
    */
    std::string evaluateString() {
        return this->_cond->evaluateBool() ? this->_exp1->evaluateString() : this->_exp2->evaluateString();
    }
};

/*! 
  \class   DoWhileStmt
  \brief   Definición de atributos y métodos de la clase DoWhileStmt
  \note    Publicly inherits from Statement class
*/
class DoWhileStmt : public Statement {
  private:
    Statement *_stmt; //!< Bloque de sentencia a ejecutar
    ExpNode *_cond;   //!< Condición de continuación del bucle

  public:
    /*!     
        \brief Constructor de DoWhileStmt
        \param   statement Puntero al bloque de la sentencia
        \param   condition Puntero a la expresión de condición del bucle
        \post    A new DoWhileStmt is created
    */
    DoWhileStmt(Statement *statement, ExpNode *condition) : _stmt(statement), _cond(condition) {}

    /*! 
        \brief Imprime el AST node for the do-while statement   
        \sa      evaluatea
    */
    void printAST();

    /*! 
        \brief   Ejecuta el bloque de la sentencia do-while
        \sa      printAST
    */
    void evaluate();
};

/*! 
  \class   ColorStmt
  \brief   Sentencia para cambiar el color del texto de la terminal
  \note    Hereda de Statement porque es una accion pura (void)
*/
class ColorStmt : public Statement {
  private:
    std::string _ansiCode; /*!< Codigo ANSI del color correspondiente */

  public:
    /*!     
        \brief Constructor de ColorStmt
        \param ansiCode Codigo en formato std::string
        \post Se crea un nuevo ColorStmt con el color indicado
    */
    ColorStmt(std::string ansiCode) : _ansiCode(ansiCode) {}

    /*! \brief Imprime el AST de ColorStmt */
    void printAST();
    
    /*! \brief Ejecuta el cambio de color en terminal */
    void evaluate(); 
};


// End of name space lp
}



// End of _AST_HPP_
#endif




