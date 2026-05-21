clear_screen;

# ==========================================
# TEST 1: COLORES EN TERMINAL
# ==========================================
red_text;
print('--- 1. TEST DE COLORES ---');
print('Este texto saldra completamente en ROJO');
blue_text;
print('Y este texto cambia a AZUL');
reset_text;
print('Y aqui volvemos al color por defecto del sistema.\n');

# ==========================================
# TEST 2: CADENAS (STRINGS)
# ==========================================
yellow_text;
print('--- 2. TEST DE CADENAS (STRINGS) ---');
reset_text;

cadena1 := 'Hola';
cadena2 := 'Mundo';

blue_text;
print('Concatenacion y Secuencias de escape:');
reset_text;
saludo := cadena1 || ' \t ' || cadena2 || '\n';
print('Resultado:\n' || saludo);

blue_text;
print('Uso de comillas simples escapadas:');
reset_text;
print('El profesor dijo: \'El interprete esta de matricula\' \n');

blue_text;
print('Operadores Relacionales con Cadenas:');
reset_text;
if ('abeja' < 'zorro') then
    print('\t[OK] \'abeja\' es menor que \'zorro\'');
else
    print('\t[ERROR] Fallo en el operador < con cadenas');
end_if;

if ('Zaragoza' > 'Alicante') then
    print('\t[OK] \'Zaragoza\' es mayor que \'Alicante\'');
end_if;

if ('Lunes' <> 'Martes') then
    print('\t[OK] Las cadenas son distintas\n');
end_if;

# ==========================================
# TEST 3: OPERADORES DE AMPLIACION
# ==========================================
yellow_text;
print('--- 3. TEST DE OPERADORES DE AMPLIACION ---');
reset_text;

blue_text;
print('Unarios (++ y --):');
reset_text;
a := 5;
a++;
print('El valor 5 tras hacer a++ es: ');
print(a);
a--;
print('El valor tras hacer a-- vuelve a ser: ');
print(a);

blue_text;
print('\nAsignaciones Compuestas (+=, -=, *=, /=):');
reset_text;
b := 10;
b += 5;
print('10 += 5 es: ');
print(b);
b /= 3;
print('15 /= 3 es: ');
print(b);

blue_text;
print('\nOperador Factorial Posfijo (!):');
reset_text;
print('El factorial de 6! es: ');
print(6!);

blue_text;
print('\nOperador Ternario (? ,):');
reset_text;
edad := 20;
estado := (edad >= 18) ? 'Mayor de edad' , 'Menor de edad';
print('Con 20 anos el estado es: ');
print(estado);

edad2 := 15;
estado2 := (edad2 >= 18) ? 'Mayor de edad' , 'Menor de edad';
print('Con 15 anos el estado es: ');
print(estado2);
print('');

# ==========================================
# TEST 4: BUCLE DO-WHILE
# ==========================================
yellow_text;
print('--- 4. TEST DEL BUCLE DO-WHILE ---');
reset_text;

blue_text;
print('Bucle normal (Iterando de 0 a 2)');
reset_text;
iteracion := 0;
do {
    print('\tEjecutando iteracion: ');
    print(iteracion);
    iteracion++;
} while (iteracion < 3);

blue_text;
print('\nEjecucion garantizada con condicion falsa');
reset_text;
falso := 10;
do {
    print('\t[OK] El bucle se ha ejecutado una vez a pesar de que 10 no es menor que 5.');
} while (falso < 5);

green_text;
print('\n==========================================');
print('Bateria de pruebas completada con exito.');
print('==========================================');
reset_text;