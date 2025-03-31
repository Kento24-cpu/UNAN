// Suponga que un individuo desea invertir su capital en un banco
// y desea saber cuánto dinero ganara después de un mes si el banco
// paga a razón de 2% mensual.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float capital, raz = 0.02, dinG;

    system("clear");

    printf("Capital a invertir:\n");
    scanf("%f", &capital);

    dinG = (capital * raz) + capital;

    system("clear");

    printf("La ganancia sera de: %.2f", dinG);

    return 0;
}
