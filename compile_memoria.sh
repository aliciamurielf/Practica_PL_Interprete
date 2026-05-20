#!/bin/bash
# Script to compile the LaTeX Memory document

echo "Compiling Memoria_Practicas.tex..."
echo "===================================="

# First pass
pdflatex -interaction=batchmode Memoria_Practicas.tex > /dev/null 2>&1
echo "[1/2] First compilation pass... done"

# Second pass (for TOC and references)
pdflatex -interaction=batchmode Memoria_Practicas.tex > /dev/null 2>&1
echo "[2/2] Second compilation pass... done"

# Check if PDF was created
if [ -f "Memoria_Practicas.pdf" ]; then
    size=$(ls -lh Memoria_Practicas.pdf | awk '{print $5}')
    echo ""
    echo "===================================="
    echo "SUCCESS! Memoria_Practicas.pdf created"
    echo "File size: $size"
    echo "===================================="
    exit 0
else
    echo ""
    echo "ERROR: PDF file was not created"
    echo "Check Memoria_Practicas.log for details"
    exit 1
fi
