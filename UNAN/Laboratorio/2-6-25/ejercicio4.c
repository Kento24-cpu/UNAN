// Ejercicio 4.
// Hacer un programa en C, que forme un arreglo de 10 elementos. Calcule el promedio de los elementos y
// forme dos nuevos arreglos, uno con los elementos menores o iguales al promedio y otro con los superiores.
// Imprima los dos nuevos arreglos.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10];
    int i;
    int suma = 0;
    float promedio;

    int *menores_iguales = NULL;
    int *superiores = NULL;

    int contador_menores_iguales = 0;
    int contador_superiores = 0;

    printf("Ingrese 10 numeros enteros para el arreglo:\n");
    for (i = 0; i < 10; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
        suma += arr[i];
    }

    promedio = (float)suma / 10;
    printf("\nEl promedio de los elementos es: %.2f\n", promedio);

    for (i = 0; i < 10; i++)
    {
        if (arr[i] <= promedio)
        {
            contador_menores_iguales++;
        }
        else
        {
            contador_superiores++;
        }
    }

    if (contador_menores_iguales > 0)
    {
        menores_iguales = (int *)malloc(contador_menores_iguales * sizeof(int));
        if (menores_iguales == NULL)
        {
            printf("Error: No se pudo asignar memoria para el arreglo de menores/iguales.\n");
            return 1;
        }
    }

    if (contador_superiores > 0)
    {
        superiores = (int *)malloc(contador_superiores * sizeof(int));
        if (superiores == NULL)
        {
            printf("Error: No se pudo asignar memoria para el arreglo de superiores.\n");
            free(menores_iguales);
            return 1;
        }
    }

    int indice_menores = 0;
    int indice_superiores = 0;
    for (i = 0; i < 10; i++)
    {
        if (arr[i] <= promedio)
        {
            menores_iguales[indice_menores] = arr[i];
            indice_menores++;
        }
        else
        {
            superiores[indice_superiores] = arr[i];
            indice_superiores++;
        }
    }

    printf("\n--- Arreglo de elementos menores o iguales al promedio ---\n");
    if (contador_menores_iguales > 0)
    {
        for (i = 0; i < contador_menores_iguales; i++)
        {
            printf("%d ", menores_iguales[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No hay elementos menores o iguales al promedio.\n");
    }

    printf("\n--- Arreglo de elementos superiores al promedio ---\n");
    if (contador_superiores > 0)
    {
        for (i = 0; i < contador_superiores; i++)
        {
            printf("%d ", superiores[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No hay elementos superiores al promedio.\n");
    }

    free(menores_iguales);
    free(superiores);
    menores_iguales = NULL;
    superiores = NULL;

    return 0;
}
