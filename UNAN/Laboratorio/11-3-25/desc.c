#include <stdio.h>

float desc = 0.15;
float precio, total, subtotal;

int main()
{
    printf("Precio total de la compra:\n");
    scanf("%f\n", &precio);

    subtotal = precio * desc;
    total = precio - subtotal;

    printf("El descuento aplicado es de: %f\nel total a pagar es de: %f", subtotal, total);

    return 0;
}