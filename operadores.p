clear_screen;
print(bold_on || color_blue || '--- TEST DE OPERADORES DE AMPLIACION ---' || color_reset || '\n\n');

print(color_yellow || '1. Operadores Unarios (++ y --):' || color_reset || '\n');
a := 5;
a++;
print('\tEl valor 5 tras hacer a++ es: ' || a);
a--;
print('\tEl valor tras hacer a-- vuelve a ser: ' || a || '\n\n');

print(color_yellow || '2. Asignaciones Compuestas (+=, -=, *=, /=):' || color_reset || '\n');
b := 10;
b += 5;
print('\t10 += 5 es: ' || b);
b /= 3;
print('\t15 /= 3 es: ' || b || '\n\n');

print(color_yellow || '3. Operador Factorial Posfijo (!):' || color_reset || '\n');
print('\tEl factorial de 6! es: ' || 6! || '\n\n');

print(color_yellow || '4. Operador Ternario (? ,):' || color_reset || '\n');
edad := 20;
# condicion ? verdad , falso
estado := (edad >= 18) ? 'Mayor de edad' , 'Menor de edad';
print('\tCon 20 anos el estado es: ' || estado);

edad2 := 15;
estado2 := (edad2 >= 18) ? 'Mayor de edad' , 'Menor de edad';
print('\tCon 15 anos el estado es: ' || estado2 || '\n');