#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cat, cat1, hip;

    system("clear");

    printf("Calcular la hipotenusa de un triangulo\nIngrese el valor de los dos lados:\n");
    scanf("%i %i", &cat, &cat1);

    system("clear");

    hip = (cat * cat) + (cat1 * cat1);

    printf("La suma de los lados del triangulo es: %i", hip);
}
