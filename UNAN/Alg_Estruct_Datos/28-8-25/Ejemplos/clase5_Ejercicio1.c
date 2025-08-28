// Se tienen almacenados en la memoria dos vectores dinámicos p y pp de N elementos cada uno.
// Hacer un programa en Lenguaje C que escriba la palabra “Iguales” si ambos vectores dinámicos
// son iguales y “Diferentes” si no lo son. Serán iguales cuando en la misma posición de ambos
// vectores dinámicos se tenga el mismo valor para todos los elementos. Recuerde liberar
// memoria.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        int *p = NULL, *pp = NULL, i, conta = 0, num;

        printf("\nIntroduzca el tamaño del arreglo:");
        scanf("%d", &num);

        printf("\n\nAsignando memoria para el primer vector...\n");

        p = (int *)malloc(num * sizeof(int));

        printf("Asignando memoria para el segundo vector...\n\n");

        pp = (int *)malloc(num * sizeof(int));

        for (i = 0; i < num; i++)
        {
                printf("\nIngrese el valor %d del array 1:\n", i);
                scanf("%d", p + i);
        }

        printf("\n\n");

        for (i = 0; i < num; i++)
        {
                printf("Ingrese el valor %d del array 2:\n", i);
                scanf("%d", pp + i);
        }

        for (i = 0; i < num; i++)
        {
                if (*(p + i) == *(pp + i))
                        conta++;
        }

        if (conta == num)
                puts("\nAMBOS VECTORES SON IGUALES");
        else
                puts("\nLOS VECTORES SON DIFERENTES");

        printf("\nLiberando memoria ocupada por el arreglo 1\n");

        free(p);

        printf("Liberando memoria ocupada por el arreglo 2\n");

        free(pp);

        return 0;
}
