// En un supermercado un cajero captura los precios de los artículos que los clientes compran e indica a cada cliente
// cual es el monto de lo que deben pagar. al final del día le indica a su supervisor cuanto fue lo que cobro en total a
// los clientes que pasaron por la caja.
// While

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ventaDia, ventaClientes = 0, clientes, precio;
    char nameCliente[99], nameProducto[99];

    system("clear");

    printf("Clientes por atender:\n");
    scanf("%d", &clientes);

    system("clear");

    while (clientes != 0)
    {
        printf("Nombre del cliente: ");
        scanf("%s", nameCliente);
        printf("Nombre del producto: ");
        scanf("%s\n", nameProducto);
        printf("Precio del producto: ");
        scanf("%i\n", &precio);

        ventaClientes += precio;

        clientes--;
    }

    ventaDia = ventaClientes;

    printf("La venta del dia fue de: %d en total", ventaDia);

    return 0;
}