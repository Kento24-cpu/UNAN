#include <stdio.h>
#include <stdlib.h>

int main()
{
    float suelB, ven1, ven2, ven3, comi, pagF;

    system("clear");

    printf("Ingrese el sueldo base: ");
    scanf("%f", &suelB);

    printf("Ingrese la venta 1: ");
    scanf("%f", &ven1);

    printf("Ingrese la venta 2: ");
    scanf("%f", &ven2);

    printf("Ingrese la venta 3: ");
    scanf("%f", &ven3);

    comi = (ven1 * 0.1) + (ven2 * 0.1) + (ven3 * 0.1);

    pagF = suelB + comi;

    system("clear");

    printf("El pago total del sueldo base mas las comisiones es de: %.2f \n", pagF);

    return 0;
}