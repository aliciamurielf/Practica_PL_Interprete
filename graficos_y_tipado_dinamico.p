# =================================================================
# TEST DE INTERFAZ GRÁFICA Y MUTABILIDAD DINÁMICA DE TIPOS
# =================================================================
clear_screen;

# Dibujamos un marco visual usando coordenadas de pantalla
place(5, 10); print(color_blue); print('****************************************');
place(6, 10); print('* *');
place(7, 10); print('* SISTEMA DE VERIFICACION DINAMICA  *');
place(8, 10); print('* *');
place(9, 10); print('****************************************');
print(color_reset);

# Demostración empírica de Tipado Dinámico exigido en el guion
elemento := 100.50; 
place(11, 12);
print('1. Elemento inicializado como NUMBER: ' || elemento);

# Mutación descarada a cadena alfanumérica
elemento := 'Estado Operativo: [OK]'; 
place(12, 12);
print(color_green);
print('2. Mismo elemento mutado a STRING: ' || elemento);
print(color_reset);

# Entrada interactiva que fuerza cambio de tipo por lectura
place(14, 12);
print('Introduce un nuevo valor alfanumerico para el elemento: ');
read_string(elemento);

place(16, 12);
print(bold_on);
print(color_yellow);
print('3. Elemento tras lectura interactiva: ' || elemento);
print(color_reset);