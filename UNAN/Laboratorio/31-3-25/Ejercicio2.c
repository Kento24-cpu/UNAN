#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Seleccion;
    char Seleccion1[99];

    system("clear");

    printf("Pizzeria Bella Valenty\nDesea ordenar una pizza vegetariana?\n(1)Si\n(0)No\n");
    scanf("%i", &Seleccion);

    switch (Seleccion)
    {
    case 0:
        system("clear");

        printf("Esta bien, la opcion no vegetariana es la siguiente:\n");
        printf("Pizza no vegetariana:\n-Peperoni\n-Jamon\n-Salmon\nEscriba su ingrediente:\n");
        scanf("%s", &Seleccion1);

        printf("Pizza no vegetariana con:\n");
        printf("-%s.\n-Mozzarella.\n-Tomate.", Seleccion1);

        break;

    case 1:
        system("clear");

        printf("Esta bien, la opcion vegetariana es la siguiente:\n");
        printf("Pizza vegetariana:\n-Pimiento\n-Tofu\nEscriba su ingrediente:\n");
        scanf("%s", &Seleccion1);

        printf("Pizza vegetariana con:\n");
        printf("-%s.\n-Mozzarella.\n-Tomate.", Seleccion1);
        break;

    default:
        printf("Opcion invalida.");
        break;
    }

    return 0;
}