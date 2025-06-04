// Ejercicio 1.
// Realice un programa en C Que cree un array de N elementos enteros, cuyos valores “numéricos” se ingresarán
// por teclado, y luego obtenga la suma y el promedio de los elementos ubicados en las posiciones pares del
// array.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int *arr;
    int i;
    int suma_pares = 0;
    int contador_pares = 0;
    float promedio_pares = 0.0;

    printf("Ingrese el numero de elementos del array: ");
    scanf("%d", &N);

    if (N <= 0)
    {
        printf("El numero de elementos debe ser mayor que 0.\n");
        return 1;
    }

    arr = (int *)malloc(N * sizeof(int));

    if (arr == NULL)
    {
        printf("Error: No se pudo asignar memoria para el array.\n");
        return 1;
    }

    printf("Ingrese los valores de los elementos del array:\n");
    for (i = 0; i < N; i++)
    {
        printf("Elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            suma_pares += arr[i];
            contador_pares++;
        }
    }

    if (contador_pares > 0)
    {
        promedio_pares = (float)suma_pares / contador_pares;
    }
    else
    {
        printf("No hay elementos en posiciones pares para calcular el promedio.\n");
    }

    printf("\n--- Resultados ---\n");
    printf("Suma de los elementos en posiciones pares: %d\n", suma_pares);
    if (contador_pares > 0)
    {
        printf("Promedio de los elementos en posiciones pares: %.2f\n", promedio_pares);
    }

    free(arr);
    arr = NULL;

    return 0;
}