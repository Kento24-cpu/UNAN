#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO_ARREGLO 20

void bubble_sort_mejorado(int arr[], int n)
{
        int i, j, temp;
        int intercambiado;
        for (i = 0; i < n - 1; i++)
        {
                intercambiado = 0;
                for (j = 0; j < n - i - 1; j++)
                {
                        if (arr[j] > arr[j + 1])
                        {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                                intercambiado = 1;
                        }
                }
                if (intercambiado == 0)
                {
                        break;
                }
        }
}

void imprimir_arreglo(int arr[], int n)
{
        for (int i = 0; i < n; i++)
        {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

int main()
{
        int numeros[TAMANIO_ARREGLO];
        int i;

        srand(time(NULL));

        for (i = 0; i < TAMANIO_ARREGLO; i++)
        {
                numeros[i] = rand() % 100 + 1;
        }

        printf("Arreglo original (sin ordenar):\n");
        imprimir_arreglo(numeros, TAMANIO_ARREGLO);

        bubble_sort_mejorado(numeros, TAMANIO_ARREGLO);

        printf("\nArreglo ordenado (con burbuja mejorada):\n");
        imprimir_arreglo(numeros, TAMANIO_ARREGLO);

        return 0;
}