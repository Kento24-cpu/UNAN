#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Generacion de numeros aleatorios.
    // srand(time(NULL));

    // for (int i = 0; i < 9; i++)
    // {
    //     int num = rand() % 8 + 1;
    //     printf("%d\n", num);
    // }

    // ----------------------------------------------------

    // Llenar un arreglo.
    int posicion[9];

    for (int i = 0; i < 9; i++)
    {
        printf("elemento %d:\n", i + 1);
        scanf("%d", &posicion[i]);
    }

    for (int i = 0; i < 9; i++)
    {
        printf("element %d: %d\n", i, posicion[i]);
    }

    return 0;
}