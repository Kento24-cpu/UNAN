#include <stdio.h>

int busquedaBinaria(int arr[], int bajo, int alto, int objetivo)
{
        while (bajo <= alto)
        {
                // Calcular el índice medio
                // Usamos (bajo + alto) / 2 para evitar desbordamiento en enteros grandes
                int medio = bajo + (alto - bajo) / 2;

                // Caso 1: El elemento está en el medio
                if (arr[medio] == objetivo)
                {
                        return medio; // Retornar el índice.
                }

                // Caso 2: El objetivo es mayor, ignorar la mitad izquierda
                if (arr[medio] < objetivo)
                {
                        bajo = medio + 1;
                }

                // Caso 3: El objetivo es menor, ignorar la mitad derecha
                else
                {
                        alto = medio - 1;
                }
        }

        // Si salimos del bucle, el elemento no está presente en el arreglo
        return -1;
}

// Función Principal
int main()
{
        // IMPORTANTE: El arreglo debe estar ordenado para que la Búsqueda Binaria funcione
        int arreglo[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
        int n = sizeof(arreglo) / sizeof(arreglo[0]); // Tamaño del arreglo
        int objetivo;
        int resultado;

        printf("Arreglo ordenado disponible: ");
        for (int i = 0; i < n; i++)
        {
                printf("%d ", arreglo[i]);
        }
        printf("\n");

        // Solicitar el número a buscar
        printf("Ingrese el numero que desea buscar: ");
        if (scanf("%d", &objetivo) != 1)
        {
                printf("Error: Entrada invalida.\n");
                return 1;
        }

        // Llamar a la función de Búsqueda Binaria
        resultado = busquedaBinaria(arreglo, 0, n - 1, objetivo);

        // Imprimir el resultado
        if (resultado != -1)
        {
                printf("\nEl numero %d fue encontrado en el indice %d del arreglo.\n", objetivo, resultado);
        }
        else
        {
                printf("\nEl numero %d no se encuentra en el arreglo.\n", objetivo);
        }

        return 0;
}