#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int posicion[8], turno = 0;

void getTable()
{
    int filas, columnas;

    for (filas = 0; filas < 3; filas++)
    {
        for (columnas = 0; columnas < 3; columnas++)
        {
            printf("[]");
        }
        printf("\n");
    }
}

void getMenu()
{
    int opcionMenu;

    while (opcionMenu != 0)
    {
        printf("Bienvenido a Tres en raya!\n--------------------------\nElija una opcion:\n");
        printf("(1)Contra Jugador\n(2)Contra Computadora\n(0)Salir\n");
        scanf("%d", &opcionMenu);

        switch (opcionMenu)
        {
        case 0:
            printf("Gracias por jugar!");
            break;

        case 1:
            getTable();
            break;

        case 2:
            getTable();
            break;

        default:
            printf("Opcion invalida, seleccione una opcion del menu\n");
            break;
        }
    }
}

int main()
{
    getMenu();

    return 0;
}