// Ciclo do while

#include <stdio.h>

int main()
{
    int suma = 0, i = 57;

    do
    {
        suma += i;
    } while (i <= 57);

    printf("suma: %i", suma);

    return 0;
}