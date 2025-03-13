#include <stdio.h>

float per, area, lad, lad1, lad2, lad3, base, altura;

int main()
{
    printf("Calcular area y perimetro de un rectangulo\nIngrese el valor de los lados:\n");
    scanf("%f %f %f %f", &lad, &lad1, &lad2, &lad3);
    printf("Valor de la base y de la altura:\n");
    scanf("%f %f", &base, &altura);

    per = lad + lad1 + lad2 + lad3;
    area = base * altura;

    printf("El perimetro del rectangulo es: %.2f y el area es: %.2f", per, area);

    return 0;
}