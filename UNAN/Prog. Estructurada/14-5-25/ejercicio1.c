#include <stdio.h>
#include <stdlib.h>

int main()
{
    int filas, numeros;

    for (filas = 1; filas <= 5; filas++)
    {
        for (numeros = 1; numeros <= filas; numeros++)
        {
            printf("%d", numeros);
        }

        printf("\n");
    }

    return 0;
}