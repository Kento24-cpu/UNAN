#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Seleccion;
    float iva = 0.15, total, subtotal;

    system("clear");

    printf("Tienda 'Las Kbras'\nSeleccione un producto:\n");
    printf("(1)Agua de 500ml - C$20\n(2)Gaseosa de 500ml - C$25\n(3)Pan con queso - C$20\n(4)Pudines - C$10\n");
    scanf("%i", &Seleccion);

    switch (Seleccion)
    {
    case 1:
        subtotal = (20 * iva);
        total = subtotal + 20;

        printf("Factura");
        printf("Producto: (1)Agua de 500ml\nPrecio: C$20\nIVA: %.2f\nTotal a pagar: %.2f", subtotal, total);
        break;

    case 2:
        subtotal = (25 * iva);
        total = subtotal + 25;

        printf("Factura");
        printf("Producto: (2)Gaseosa de 500ml\nPrecio: C$25\nIVA: %.2f\nTotal a pagar: %.2f", subtotal, total);
        break;

    case 3:
        subtotal = (20 * iva);
        total = subtotal + 20;

        printf("Factura");
        printf("Producto: (3)Pan con queso\nPrecio: C$20\nIVA: %.2f\nTotal a pagar: %.2f", subtotal, total);
        break;

    case 4:
        subtotal = (10 * iva);
        total = subtotal + 10;

        printf("Factura");
        printf("Producto: (4)Pudines\nPrecio: C$10\nIVA: %.2f\nTotal a pagar: %.2f", subtotal, total);
        break;

    default:
        printf("Opcion invalida.");
        break;
    }

    return 0;
}