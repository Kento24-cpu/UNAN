// soluciones para calcular el monto a pagar con descuentos, usando if...else y switch...case:
// 1. Cálculo del Monto con if...else
#include <stdio.h>

int main()
{
    float monto, descuento = 0, monto_final;

    // Pedir al usuario que ingrese el monto de la factura
    printf("Ingrese el monto de la factura: ");
    scanf("%f", &monto);

    // Calcular el descuento usando if...else
    if (monto > 999)
    {
        descuento = monto * 0.10; // 10% de descuento
    }
    else if (monto >= 800 && monto <= 999)
    {
        descuento = monto * 0.05; // 5% de descuento
    }
    else if (monto >= 501 && monto <= 799)
    {
        descuento = monto * 0.03; // 3% de descuento
    }

    // Calcular el monto final
    monto_final = monto - descuento;

    // Mostrar el resultado
    printf("Monto original: %.2f\n", monto);
    printf("Descuento aplicado: %.2f\n", descuento);
    printf("Monto final a pagar: %.2f\n", monto_final);

    return 0;
}
