// Suma los primeros 10 numeros a partir de 57.
// Ciclo for

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int suma = 0;

    system("clear");

    for (int i = 57; i <= 67; i++)
    {
        suma += i;

        printf("suma: %i\n", suma);
    }

    return 0;
}