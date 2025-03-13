#include <stdio.h>

float desc = 0.5;
float precio, total, subtotal;

int main()
{
    printf("Precio del producto:\n");
    scanf("%f\n", &precio);

    subtotal = precio * desc;
    total = precio - subtotal;

    printf("El descuento aplicado es de: %f\nel total a pagar es de: %f", subtotal, total);

    return 0;
}