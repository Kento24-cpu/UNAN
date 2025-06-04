// 2. *Filtrar clientes potenciales*
//    Usa un ciclo while para procesar una lista de clientes potenciales.
//    El programa debe imprimir solo aquellos cuyo correo electrónico incluye "gmail.com" y cuyo país no sea
//    "Nicaragua".

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int numClientes, count = 0;
    char nameClientes[numClientes][99];
    char emailClientes[numClientes][99];
    char paisClientes[numClientes][99];
    char clientes[numClientes];

    printf("Seleccione el numero de clientes");
    scanf("%i", &numClientes);

    while (count < numClientes)
    {
        printf("Nombre del cliente:\n");
        scanf("%");
        printf("Correo del cliente:\n");
        printf("Pais del cliente:\n");

        clientes[count++];
    }

    return 0;
}
