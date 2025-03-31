// Elabore un programa que calcule la raíz cuadrada de un numero
// ingresado por teclado.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double num;
    double raizC;

    system("clear");

    printf("Escriba un numero:\n");
    scanf("%lf", &num);

    raizC = sqrt(num);

    system("clear");

    printf("La raiz del numero %.2lf es igual a: %.2lf", num, raizC);

    return 0;
}
