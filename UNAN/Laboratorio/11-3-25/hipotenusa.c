#include <stdio.h>

int cat, cat1, hip;

int main()
{
    printf("Calcular la hipotenusa de un triangulo\nIngrese el valor de los dos lados:\n");
    scanf("%i %i", &cat, &cat1);

    hip = (cat ^ 2) + (cat1 ^ 2);

    printf("La suma de los lados del triangulo es: %i", hip);
}
