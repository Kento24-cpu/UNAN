#include <stdio.h>

int main()
{

    float eur = 0.95;
    float dol, cambio;
    printf("Cambio de dolar a euro\n");
    printf("Inserte la cantidad a cambiar:");
    scanf("%f", &dol);

    cambio = dol * eur;

    printf("Dolar a cambiar  = %f\ncambio en euro = %f\n", dol, cambio);

    return 0;
}