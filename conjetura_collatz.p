# =================================================================
# TEST DE COMPLEJIDAD ORIGINAL: CONJETURA DE COLLATZ
# =================================================================
clear_screen;
print(color_cyan);
print('=== ALGORITMO INTEGRAL: CONJETURA DE COLLATZ ===\n');
print(color_reset);

print('Introduce un numero entero positivo para iniciar: ');
read(n);

# Conservamos el valor original para el informe final
numero_inicial := n;
iteraciones := 0;
maximo := n;

print('\nProcesando secuencia de pasos...\n');

do {
    # Guardamos el pico máximo alcanzado usando tu operador ternario (? ,)
    maximo := (n > maximo) ? n , maximo;

    # Imprimimos el estado actual formateado 
    print('\tValor actual de n = ' || n);

    # Aplicamos las reglas de Collatz
    if (n mod 2 = 0) then
        n := n // 2;       # Corregido: usando asignación estándar y división entera
    else
        n := n * 3 + 1;
    end_if;

    iteraciones++;     # Incremento unario de ampliación
} while (n > 1);

# Informe final decorado con colores de pantalla
print(color_green);
print(bold_on);
print('\n=== INFORME DE COMPLEJIDAD SEMÁNTICA ===');
print(color_reset);
print('Numero inicial analizado: ' || numero_inicial);
print('Total de iteraciones calculadas: ' || iteraciones);
print('Pico maximo alcanzado en la orbita: ' || maximo);
print('Factorial de las iteraciones por diversion: ' || (iteraciones!));