// Hacer un programa que llene una matriz dinámica de N * N y determine la posición [renglón
// ,columna] del número mayor almacenado en la matriz. Los números son diferentes.
// Recuerde liberar memoria.

#include <stdio.h>
#include <stdlib.h>

int main()
{
        int **p = NULL;
        int nFila = 0, nCol = 0, f = 0, c = 0, mayor = 0, j, i;

        do
        {
                printf("Numero de filas de la Matriz:");
                scanf("%d", &nFila);
        } while (nFila < 1);

        nCol = nFila;

        printf("\nAsignando memoria para el puntero a puntero...\n");

        if ((p = (int **)malloc(nFila * sizeof(int *))) == NULL)
        {
                printf("\n\nInsuficiente Espacio De Memoria\n\n");
                exit(0);
        }

        printf("\nAsignando memoria para el arreglo de punteros...\n");

        for (f = 0; f < nFila; f++)
        {
                if ((p[f] = (int *)malloc(nCol * sizeof(int *))) == NULL)
                {
                        printf("\n\nInsuficiente Espacio De Memoria\n\n");
                        exit(0);
                }
        }

        printf("\n\n");

        for (f = 0; f < nFila; f++)
        {
                for (c = 0; c < nCol; c++)
                {
                        printf("Ingrese el valor del elemento[%d][%d]: ", f, c);
                        scanf("%d", &p[f][c]);
                        if (p[f][c] > mayor)
                        {
                                mayor = p[f][c];
                                i = f;
                                j = c;
                        }
                }
        }

        printf("\n\n***La Matriz***\n");

        for (f = 0; f < nFila; f++)
        {
                for (c = 0; c < nCol; c++)
                {
                        printf("%5d", *(*(p + f) + c));
                }
                printf("\n");
        }

        printf("\nEl numeromayor es %d y esta en la posicion [%d][%d]\n", mayor, i, j);
        printf("\nLiberando memoria para el arreglo de punteros...\n");

        for (f = 0; f < nFila; f++)
                free(p[f]);

        printf("\nLiberando memoria para el puntero a puntero...\n");

        free(p);

        printf("\n\n");

        return 0;
}
