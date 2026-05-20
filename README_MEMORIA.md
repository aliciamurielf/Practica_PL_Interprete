# Memoria de Prácticas - Procesadores de Lenguajes (2025-2026)

## 📋 Descripción

Se ha generado una **Memoria de Prácticas académica exhaustiva y formal** en formato LaTeX para documentar la implementación de un intérprete de lenguaje de pseudocódigo utilizando **Flex** (análisis léxico), **Bison** (análisis sintáctico) y **C++** (implementación).

## 📄 Archivos Generados

- **`Memoria_Practicas.tex`** (20 KB): Documento fuente LaTeX con 624 líneas
- **`Memoria_Practicas.pdf`** (159 KB): Documento compilado en PDF listo para imprimir

## 📚 Contenido de la Memoria

La memoria está estructurada en las siguientes secciones:

### 1. **Introducción** 
- Objetivos del proyecto
- Competencias desarrolladas
- Estructura de la memoria

### 2. **Arquitectura AST y Tabla de Símbolos**
- Jerarquía de clases polimórficas (ExpNode y Statement)
- Interacción con la tabla de símbolos global
- Reglas de Bison e instanciación de nodos
- Fragmentos de código real del proyecto

### 3. **Tipado Dinámico y Procesamiento de Cadenas**
- Sistema de tipado dinámico completo
- Método `AssignmentStmt::evaluate()` con conversión de tipos
- Procesamiento de secuencias de escape (`\n`, `\t`)
- Clase `StringNode` con ejemplos reales

### 4. **Robustez y Control de Errores Dinámicos**
- Estrategia general de manejo de errores
- Control exhaustivo de bucles FOR
- Prevención de bucles infinitos
- Validación de paso cero e intervalos nulos
- Conversión segura de tipos

### 5. **Ampliaciones Avanzadas** (Supera requisitos mínimos)
- **Blindaje de tipos en Switch**: Evita comparaciones erróneo-alfabéticas
- **Bucle Do-While**: Ejecución garantizada postcondición
- **Comandos ANSI de color**: ColorStmt como Statement puro sin saturar Bison
- **Operador Factorial**: Cálculo seguro de n! con validaciones
- **Operador Ternario**: Evaluación condicional compacta (cond ? exp1 : exp2)

### 6. **Pruebas y Validación**
- Prueba 1: Bucles FOR con validación de errores
- Prueba 2: Bucle DO-WHILE  
- Prueba 3: Operador SWITCH
- Prueba 4: Comandos de color ANSI
- Prueba 5: Tipado dinámico

Cada prueba incluye código de ejemplo real del proyecto (.p files)

### 7. **Conclusiones**
- Requisitos cumplidos: **100%**
- Ampliaciones implementadas: **100%+**
- Reflexión sobre calidad de código y competencias demostradas
- Posibles mejoras futuras

### Apéndice
- Guía de compilación
- Estructura de directorios del proyecto

## 🎯 Características Destacadas

✅ **Documento formal y académico** escrito en tono profesional pero accesible

✅ **Énfasis en superar requisitos**: Se documentan explícitamente las características implementadas más allá de los requisitos mínimos

✅ **Código real**: Fragmentos de C++ extraídos directamente del proyecto con explicaciones detalladas

✅ **Arquitectura sólida**: Documenta polimorfismo, tabla de símbolos, AST

✅ **Análisis exhaustivo de errores**: Sección dedicada al control robusto de errores

✅ **Ejemplos prácticos**: Programas de prueba (.p) incluidos con resultados esperados

✅ **Configuración LaTeX profesional**: Listings para código, índice de contenidos, encabezados/pies de página personalizados

## 📖 Estructura del Documento

```
1. Portada (título, autoras, fecha)
2. Resumen (abstract)
3. Tabla de contenidos
4. 7 secciones principales
5. Apéndice (guía de compilación)
```

## 🖨️ Uso del Documento

### Visualización
```bash
# Abrir el PDF
evince Memoria_Practicas.pdf
# o
xpdf Memoria_Practicas.pdf
```

### Edición
```bash
# Recompilar después de cambios en el .tex
pdflatex -interaction=batchmode Memoria_Practicas.tex
```

### Impresión
```bash
# Imprimir en blanco y negro (recomendado)
lpr Memoria_Practicas.pdf

# Imprimir a color
lpr -o ColorModel=RGB Memoria_Practicas.pdf
```

## 📊 Estadísticas del Documento

| Métrica | Valor |
|---------|-------|
| Líneas LaTeX | 624 |
| Páginas PDF | ~25 |
| Tamaño PDF | 159 KB |
| Fragmentos de código | 15+ |
| Secciones principales | 7 |
| Subsecciones | 20+ |

## 🔬 Cobertura de Temas

La memoria documenta satisfactoriamente:

- **100% de requisitos mínimos** del tribunal (análisis léxico, sintáctico, semántico, control de flujo)
- **Más del 100%** gracias a ampliaciones avanzadas:
  - Tipado dinámico completo
  - Operadores avanzados (factorial, ternario)
  - Sistema de colores ANSI
  - Do-while loop
  - Blindaje exhaustivo de tipos
  - Manejo robusto de errores en bucles

## 👥 Autoras Documentadas

- Alicia Muriel Fernández
- Lucía Cañero Moslero

## 📝 Notas

- El documento está completamente en español con términos técnicos en inglés donde es apropiado
- Se mantiene un tono formal pero accesible para estudiantes
- Cada sección incluye explicación teórica seguida de código real del proyecto
- Las pruebas demuestran la funcionalidad completa del intérprete

---

**Fecha de generación**: 20 de mayo de 2026  
**Estado**: ✅ Completado y compilado exitosamente
