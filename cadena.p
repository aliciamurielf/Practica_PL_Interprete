clear_screen;
print(bold_on || color_magenta || '--- TEST DE CADENAS (STRINGS) ---' || color_reset || '\n\n');

cadena1 := 'Hola';
cadena2 := 'Mundo';

print(color_yellow || '1. Concatenacion y Secuencias de escape (Tabulador y Saltos):' || color_reset || '\n');
saludo := cadena1 || ' \t ' || cadena2 || '\n';
print('Resultado:\n' || saludo);

print(color_yellow || '2. Uso de comillas simples escapadas:' || color_reset || '\n');
print('El profesor dijo: \'El interprete esta de matricula\' \n\n');

print(color_yellow || '3. Operadores Relacionales con Cadenas (Orden Alfabetico):' || color_reset || '\n');

if ('abeja' < 'zorro') then
    print('\t[OK] \'abeja\' es menor que \'zorro\'');
else
    print('\t[ERROR] Fallo en el operador < con cadenas');
end_if;

if ('Zaragoza' > 'Alicante') then
    print('\t[OK] \'Zaragoza\' es mayor que \'Alicante\'');
end_if;

if ('Lunes' <> 'Martes') then
    print('\t[OK] Las cadenas son distintas');
end_if;