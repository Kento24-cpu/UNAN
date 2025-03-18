#include <stdio.h>
#include <stdlib.h>

int main()
{
    float per, area, base, altura;

    system("clear");

    printf("Valor de la base y de la altura:\n");
    scanf("%f %f", &base, &altura);

    area = base * altura;
    per = 2 * (base + altura);

    system("clear");

    printf("El perimetro del rectangulo es: %.2f y el area es: %.2f", per, area);

    return 0;
}