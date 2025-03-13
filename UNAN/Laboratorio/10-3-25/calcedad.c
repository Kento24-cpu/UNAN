#include <stdio.h>

int anac, edad;

int main()
{
    printf("Calcular su edad.\nintroduce tu fecha de nacimiento:\n ");
    scanf("%i\n", &anac);

    edad = 2025 - anac;

    printf("Tu edad actual es: %i", edad);

    return 0;
}
