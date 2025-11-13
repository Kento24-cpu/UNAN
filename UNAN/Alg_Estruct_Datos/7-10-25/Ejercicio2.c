#include <stdio.h>
#include <stdlib.h> // Necesario para malloc y free

// Función para intercambiar dos elementos
void intercambiar(int *a, int *b)
{
        int t = *a;
        *a = *b;
        *b = t;
}

int particion(int arr[], int bajo, int alto)
{
        int pivote = arr[alto]; // Elegimos el último elemento como pivote
        int i = (bajo - 1);     // Índice del elemento más pequeño

        for (int j = bajo; j <= alto - 1; j++)
        {
                // Si el elemento actual es menor o igual al pivote
                if (arr[j] <= pivote)
                {
                        i++; // Incrementamos el índice del elemento más pequeño
                        intercambiar(&arr[i], &arr[j]);
                }
        }
        intercambiar(&arr[i + 1], &arr[alto]);
        return (i + 1); // Devolvemos la posición del pivote
}

void quickSort(int arr[], int bajo, int alto)
{
        if (bajo < alto)
        {
                // pi es el índice de partición, arr[pi] está ahora en el lugar correcto
                int pi = particion(arr, bajo, alto);

                // Llamadas recursivas separadas para los subarreglos antes y después de la partición
                quickSort(arr, bajo, pi - 1);
                quickSort(arr, pi + 1, alto);
        }
}

// Función para imprimir el arreglo
void imprimirArreglo(int arr[], int tamano)
{
        for (int i = 0; i < tamano; i++)
        {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

// Función Principal
int main()
{
        int n;
        int *arreglo;

        // 1. Solicitar el tamaño del arreglo al usuario
        printf("Ingrese la cantidad de elementos del arreglo: ");
        if (scanf("%d", &n) != 1 || n <= 0)
        {
                printf("Entrada invalida. Debe ingresar un numero entero positivo.\n");
                return 1;
        }

        // 2. Asignar memoria dinámicamente
        arreglo = (int *)malloc(n * sizeof(int));
        if (arreglo == NULL)
        {
                printf("Error: No se pudo asignar memoria.\n");
                return 1;
        }

        // 3. Solicitar los elementos del arreglo al usuario
        printf("Ingrese los %d elementos:\n", n);
        for (int i = 0; i < n; i++)
        {
                printf("Elemento %d: ", i + 1);
                if (scanf("%d", &arreglo[i]) != 1)
                {
                        printf("Error: Entrada invalida. Solo se aceptan numeros enteros.\n");
                        free(arreglo);
                        return 1;
                }
        }

        // 4. Imprimir el arreglo original
        printf("\nArreglo original: ");
        imprimirArreglo(arreglo, n);

        // 5. Ordenar el arreglo con Quicksort
        quickSort(arreglo, 0, n - 1);

        // 6. Imprimir el arreglo ordenado
        printf("Arreglo ordenado por Quicksort: ");
        imprimirArreglo(arreglo, n);

        // 7. Liberar la memoria asignada
        free(arreglo);

        return 0;
}