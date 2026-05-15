# =================================================================
# BATERÍA DE PRUEBAS DE RESILIENCIA ANTE ERRORES SEMÁNTICOS Y RUNTIME
# =================================================================
clear_screen;
print(bold_on);
print('=== INICIANDO SIMULACION CONTROLADA DE ERRORES ===\n');
print(color_reset);

# 1. Intento de modificar una constante matemática predefinida (Semántico)
print('# Intentando reasignar el valor de la constante pi...');
pi := 3.14; 

# 2. Operación aritmética incompatible entre tipos heterogéneos (Semántico)
print('\n# Intentando sumar un numero con una cadena de texto...');
error_tipos := 45 + 'Texto no valido';

# 3. Operación de división por cero matemática (Ejecución)
print('\n# Intentando ejecutar una division aritmetica por cero...');
division_invalida := 100 / 0;

# 4. Operación de división entera por cero (Ejecución)
print('\n# Intentando ejecutar una division entera por cero...');
division_entera_invalida := 50 // 0;

# 5. Factorial matemático inválido de un dígito negativo (Ejecución)
print('\n# Intentando procesar el factorial de un numero negativo...');
factorial_negativo := (-5)!;

print('\n=== FIN DE LA SIMULACION: INTÉRPRETE RESILIENTE ===\n');