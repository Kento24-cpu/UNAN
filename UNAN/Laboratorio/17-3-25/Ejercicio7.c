// 7. Si un dólar equivale a 3,27 soles. Hacer un algoritmo que imprima
// en dólares una cantidad X de soles.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float dol, camb, sol = 3.27;

    system("clear");

    printf("Escriba la cantidad de dolares:");
    scanf("%f", &dol);

    camb = dol * sol;

    system("clear");

    printf("La cantidad de %.2f dolares en soles es: %.2f", dol, camb);
}