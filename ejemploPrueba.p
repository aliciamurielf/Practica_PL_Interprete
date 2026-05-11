clear_screen;
place(2, 10);
print('--- SISTEMA DE GESTIÓN DE USUARIO --- \n');

# 1. Demostración de read_string y print
place(4, 5);
print('Introduzca su nombre de estudiante: ');
read_string(nombre);

place(5, 5);
print('Bienvenido/a, ');
print(nombre);
print('\n');

# 2. Demostración de repeat y if (validación de entrada)
repeat
    place(7, 5);
    print('Introduzca su edad (debe ser mayor de 17 para la EPS): ');
    read(edad);
    
    if (edad < 18) then
        place(8, 5);
        print('Error: Edad no válida para grado universitario.\n');
    else
        place(8, 5);
        print('Edad aceptada correctamente.\n');
    end_if;
until (edad >= 18)

# 3. Demostración de for (generación de una clave de acceso simple)
print('\n Generando su código de acceso temporal: ');
for i from 1 to 5 step 1 do
    print(i * 2);
    print('-');
end_for;
print('OK\n');

# 4. Demostración de switch y while
opcion := -1;

while (opcion <> 0) do
    print('\n Menú de especialidad: \n');
    print(' 1. Computación \n');
    print(' 2. Sistemas \n');
    print(' 3. Software \n');
    print(' 0. Salir \n');
    print(' Elija su opción: ');
    read(opcion);

    switch (opcion)
        case 1: 
            print('\n Especialidad: Computación. \n');
            print(' Preparando entorno Fedora para PL... \n');
        case 2: 
            print('\n Especialidad: Sistemas. \n');
        case 3: 
            print('\n Especialidad: Software. \n');
        default: 
            if (opcion <> 0) then
                print('\n Opción no reconocida. \n');
            end_if;
    end_switch;
end_while;

print('\n Gracias por usar el sistema, ');
print(nombre);
print('. Fin del programa.\n');