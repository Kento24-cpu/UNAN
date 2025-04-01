// Factorial de un numero.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, fact = 1;

    system("clear");

    printf("Escribe un numero:\n");
    scanf("%i", &num);

    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }

    printf("El factorial de %i es: %i\n", num, fact);

    return 0;
}