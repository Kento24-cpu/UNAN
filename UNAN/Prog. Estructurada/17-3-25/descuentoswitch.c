// 2. Cálculo del Monto con switch...case (Usando Rangos)
#include <stdio.h>

int main()
{
    float monto, descuento = 0, monto_final;
    int rango;

    // Pedir al usuario que ingrese el monto de la factura
    printf("Ingrese el monto de la factura: ");
    scanf("%f", &monto);

    // Determinar el rango para usar switch...case
    if (monto > 999)
    {
        rango = 4;
    }
    else if (monto >= 800 && monto <= 999)
    {
        rango = 3;
    }
    else if (monto >= 501 && monto <= 799)
    {
        rango = 2;
    }
    else
    {
        rango = 1;
    }

    // Calcular el descuento usando switch...case
    switch (rango)
    {
    case 4:
        descuento = monto * 0.10; // 10% de descuento
        break;
    case 3:
        descuento = monto * 0.05; // 5% de descuento
        break;
    case 2:
        descuento = monto * 0.03; // 3% de descuento
        break;
    default:
        descuento = 0; // No hay descuento
    }

    // Calcular el monto final
    monto_final = monto - descuento;

    // Mostrar el resultado
    printf("Monto original: %.2f\n", monto);
    printf("Descuento aplicado: %.2f\n", descuento);
    printf("Monto final a pagar: %.2f\n", monto_final);

    return 0;
}
