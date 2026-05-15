# ==========================================
# TEST DE AMPLIACIÓN DEL LENGUAJE
# ==========================================
clear_screen;

print(color_cyan);
print(bold_on);
print('--- 1. Operadores de asignacion y unarios ---\n');
print(color_reset);

a := 10;
a += 5;   # Prueba de PLUS_ASSIGN
print('a tras a += 5 es: ' || a);

a++;      # Prueba de INC
print('a tras a++ es: ' || a);

a -= 2;   # Prueba de MINUS_ASSIGN
a--;      # Prueba de DEC
print('a tras a -= 2 y a-- es: ' || a);


print(color_yellow);
print(bold_on);
print('\n--- 2. Operador Factorial ---\n');
print(color_reset);

print('El factorial de 5 usando el operador (!) es: ' || 5!);
# print('El factorial de 5 usando la funcion es: ' || factorial(5)); # Descomentar si implementaste la funcion


print(color_green);
print(bold_on);
print('\n--- 3. Operador Ternario ---\n');
print(color_reset);

b := -25;
# El PDF especifica el uso de la coma en el ternario: condicion ? verdad , falso
absoluto := (b >= 0) ? b , -b;
print('El valor absoluto de -25 usando el ternario es: ' || absoluto);


print(color_magenta);
print(bold_on);
print('\n--- 4. Bucle do { ... } while ---\n');
print(color_reset);

iteracion := 0;
do {
    print('Ejecutando iteracion numero: ' || iteracion);
    iteracion++;
} while (iteracion < 3);

print('\nFin de las pruebas de ampliacion.\n');