// Dias de la semana

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dia;

    if (system("cls"))
    {
        system("clear");
    }

    printf("Escriba un numero:\n(1 - 7)\n");
    scanf("%d", &dia);

    switch (dia)
    {
    case 1:
        printf("El dia es Lunes.\n");
        break;
    case 2:
        printf("El dia es Martes.\n");
        break;
    case 3:
        printf("El dia es Miercoles.\n");
        break;
    case 4:
        printf("El dia es Jueves.\n");
        break;
    case 5:
        printf("El dia es Viernes.\n");
        break;
    case 6:
        printf("El dia es Sabado.\n");
        break;
    case 7:
        printf("El dia es Domingo.\n");
        break;

    default:
        printf("Fuera de rango.");
        break;
    }

    return 0;
}