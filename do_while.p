clear_screen;
print(bold_on || color_cyan || '--- TEST DEL BUCLE DO-WHILE ---' || color_reset || '\n\n');

# Prueba 1: Bucle funcional clásico
print(color_yellow || 'Prueba 1: Bucle normal (Iterando de 0 a 2)' || color_reset || '\n');
iteracion := 0;
do {
    print('\tEjecutando iteracion: ' || iteracion);
    iteracion++;
} while (iteracion < 3);

print('\n');

print(color_yellow || 'Prueba 2: Ejecucion garantizada con condicion falsa' || color_reset || '\n');
falso := 10;
do {
    print('\t¡Exito! El bucle se ha ejecutado una vez a pesar de que 10 no es menor que 5.');
} while (falso < 5);

print('\n' || color_green || 'Fin de las pruebas del bucle do-while.' || color_reset || '\n');