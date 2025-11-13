#include <stdio.h>

// Función para imprimir el arreglo.
void imprimirArreglo(int arr[], int n)
{
        for (int i = 0; i < n; i++)
        {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

// Función para ordenar el arreglo usando Inserción.
void insertionSort(int arr[], int n)
{
        int i, clave, j;
        // Iteramos desde el segundo elemento (índice 1) hasta el final del arreglo.
        for (i = 1; i < n; i++)
        {
                // 'clave' es el elemento que queremos insertar en la parte ordenada.
                clave = arr[i];
                j = i - 1;

                /* Movemos los elementos del sub-arreglo arr[0..i-1] que son
                   mayores que 'clave' una posición adelante de su posición actual. */
                while (j >= 0 && arr[j] > clave)
                {
                        arr[j + 1] = arr[j];
                        j = j - 1;
                }
                // Insertamos la 'clave' en su posición correcta.
                arr[j + 1] = clave;
        }
}

// --- Función Principal ---
int main()
{
        int arreglo[] = {12, 11, 13, 5, 6};
        int n = sizeof(arreglo) / sizeof(arreglo[0]); // Calcular el tamaño del arreglo

        printf("Arreglo original: ");
        imprimirArreglo(arreglo, n);

        // Llamar a la función de ordenamiento
        insertionSort(arreglo, n);

        printf("Arreglo ordenado por Insercion: ");
        imprimirArreglo(arreglo, n);

        return 0;
}