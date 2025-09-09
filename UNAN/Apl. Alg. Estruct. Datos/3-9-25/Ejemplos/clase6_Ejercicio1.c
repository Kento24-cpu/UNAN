#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM 10

void imprimirArray(int *a)
{
        int i;

        for (i = 0; i < TAM - 1; i++)
                printf("%d, ", a[i]);

        printf("%d\n", a[i]);
}

void generarArray(int *a)
{
        int i;

        for (i = 0; i < TAM; i++)
                a[i] = (int)(rand() % 1000);
}

void ordenarBurbuja(int *a)
{
        int aux, pasada, i;

        for (pasada = 1; pasada < TAM; pasada++)
        {
                for (i = 0; i < TAM - 1; i++)
                {
                        if (a[i] > a[i + 1])
                        {
                                aux = a[i];
                                a[i] = a[i + 1];
                                a[i + 1] = aux;
                        }
                }
        }
}

int main()
{
        int array[TAM];

        srand((unsigned int)time(NULL));

        generarArray(array);

        printf("Antes de ordenar\n---------------------\n");

        imprimirArray(array);

        ordenarBurbuja(array);

        printf("\nDespués de ordenar\n------------------\n");

        imprimirArray(array);

        return 0;
}