// Sumar los primeros 100 numeros naturales.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, suma;

    system("clear");

    printf("Numeros del 1 al 100:\n");

    for (i = 1; i <= 100; i++)
    {
        suma += i;

        printf("%i - ", i);
    }

    printf("\nLa suma de todos los numeros es: %i", suma);

    return 0;
}