## Author

* **Alicia Muriel Fernández** — *Computer Engineering Student, University of Córdoba*

# Pseudocode Interpreter - Language Processors

![C++](https://img.shields.io/badge/C++-11%2B-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)
![Flex](https://img.shields.io/badge/Lexer-Flex-orange?style=flat-square)
![Bison](https://img.shields.io/badge/Parser-Bison-blue?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)

Development of a **pseudocode interpreter with English syntax** designed and implemented for the **Language Processors** course at the University of Córdoba (UCO).

The project features a lexical analyzer (**Flex**), a syntactic/semantic parser (**Bison**), and the dynamic construction of an **Abstract Syntax Tree (AST)** in C++ for expression evaluation and statement execution.

> **Spanish Version:** A Spanish syntax version is also available at [Practica_PL_Interprete_ESP](https://github.com/aliciamurielf/Practica_PL_Interprete_ESP).

---

## Key Features

- **Lexical & Syntactic Analysis:** Formal grammar definition using regular expressions in Flex and LALR parsing rules in Bison.
- **Abstract Syntax Tree (AST):** Object-oriented C++ architecture to represent expression nodes, control flow statements, assignment operations, and logical/arithmetic operators.
- **Symbol Table:** Scope-aware management of variables and constants (numeric, boolean, string) with runtime type checking.
- **Control Structures:**
  - Conditionals: `if ... then ... else ... end_if`
  - Loops: `while ... do`, `repeat ... until`, `for ... from ... to`
- **Operations:** Full support for arithmetic, relational, logical expressions, and string manipulation.
- **Built-in Functions:** Math utilities and standard I/O primitives (`print`, `read`, `clear`, etc.).

---

## Prerequisites & Setup

Ensure you have the following tools installed on your GNU/Linux system:

- `g++` (C++11 support or higher)
- `flex`
- `bison`
- `make`

### Building the Project

Clone the repository and run the build script:

```bash
git clone https://github.com/aliciamurielf/Practica_PL_Interprete.git
cd Practica_PL_Interprete
make
```

---

## Usage

Once compiled, you can run the interpreter interactively or pass a source file as an argument:

```bash
# Interactive mode
./interpreter.exe

# Execute a test program
./interpreter.exe examples/test.ipe
```

---

## Project Structure

```text
├── ast/            # C++ classes for AST nodes (ExpNode, VariableNode, StmtNode, etc.)
├── parser/         # Syntactic specification (Bison .y file)
├── lexer/          # Lexical specification (Flex .l file)
├── table/          # Symbol table implementation and scope handling
├── examples/       # Test scripts written in English pseudocódigo (.ipe)
└── Makefile        # Build automation script
```

---

