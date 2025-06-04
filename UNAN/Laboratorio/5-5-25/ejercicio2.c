// Tabla de multiplicar de un numero.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroTabla, i, multiplicacion;

    system("clear");

    printf("Ingrese el numero de la tabla:\n");
    scanf("%i", &numeroTabla);

    system("clear");

    printf("Tabla de multiplicar del numero: %i\n", numeroTabla);

    for (i = 1; i <= 12; i++)
    {
        multiplicacion += numeroTabla;

        printf("%i x %i = %i\n", numeroTabla, i, multiplicacion);
    }

    return 0;
}