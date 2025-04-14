// Imprimir el nombre de un producto, su precio y su descuento con clave
// Clave 1: 25%     Clave 2: 40%

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombreProducto[99];
    int precio, clave;
    float subtotal, total;

    system("clear");

    printf("Escriba el nombre, clave y precio del producto:\n");
    scanf("%s %i %i", nombreProducto, &clave, &precio);

    if (clave == 1)
    {
        subtotal = precio * 0.25;
    }
    else if (clave == 2)
    {
        subtotal = precio * 0.4;
    }
    else
    {
        printf("Clave incorrecta");
    }

    total = subtotal + precio;

    system("clear");

    printf("El producto es: %s\nClave: %i\nPrecio: %i\nSubtotal: %.2f\nTotal a pagar: %.2f", nombreProducto, clave, precio, subtotal, total);

    return 0;
}
