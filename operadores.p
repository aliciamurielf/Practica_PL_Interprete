clear_screen;

blue_text;
print('--- TEST DE OPERADORES DE AMPLIACION ---');
reset_text;
print('');

yellow_text;
print('1. Operadores Unarios (++ y --):');
reset_text;
a := 5;
a++;
print('El valor 5 tras hacer a++ es: ');
print(a);
a--;
print('El valor tras hacer a-- vuelve a ser: ');
print(a);
print('');

yellow_text;
print('2. Asignaciones Compuestas (+=, -=, *=, /=):');
reset_text;
b := 10;
b += 5;
print('10 += 5 es: ');
print(b);
b /= 3;
print('15 /= 3 es: ');
print(b);
print('');

yellow_text;
print('3. Operador Factorial Posfijo (!):');
reset_text;
print('El factorial de 6! es: ');
print(6!);
print('');

yellow_text;
print('4. Operador Ternario (? ,):');
reset_text;
edad := 20;
# condicion ? verdad , falso
estado := (edad >= 18) ? 'Mayor de edad' , 'Menor de edad';
print('Con 20 anos el estado es: ');
print(estado);
print('');

edad2 := 15;
estado2 := (edad2 >= 18) ? 'Mayor de edad' , 'Menor de edad';
print('Con 15 anos el estado es: ');
print(estado2);
print('');