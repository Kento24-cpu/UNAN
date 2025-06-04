// Mostrar los cuadrados de los numeros del 1 al 10.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, cuadrado, numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    system("clear");

    for (i = 0; i <= 10; i++)
    {
        printf("Numeros al cuadrado del 1 al 10\n");
        printf("%i\n", cuadrado);

        cuadrado = numeros[i] *= numeros[i];
    }

    return 0;
}