// Suponga que tiene usted una tienda y desea registrar las ventas en su computadora.
// Diseñe un algoritmo que lea por cada cliente, el monto total de su compra. Al final del día que
// escriba ia cantidad total de ventas y el numero de clientes atendidos.
// do while

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float montoCompra;
    float totalVentas = 0;
    int cantidadClientes = 0;
    char respuesta;

    system("clear");

    do
    {
        printf("Ingrese la compra total del cliente: ");
        scanf("%f", &montoCompra);

        totalVentas += montoCompra;
        cantidadClientes++;

        printf("\nAtendio a otro cliente hoy? (s/n): ");

        scanf(" %c", &respuesta);
    } while (respuesta == 's' || respuesta == 'S');

    printf("Cantidad total de ventas: %.2f\n", totalVentas);
    printf("Numero de clientes atendidos: %d\n", cantidadClientes);

    return 0;

    return 0;
}