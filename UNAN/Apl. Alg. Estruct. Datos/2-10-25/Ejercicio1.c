#include <stdio.h>
#include <stdlib.h>

void mostrarArreglo(int *arreglo, int tamano);
void bubbleSort(int *arreglo, int tamano);

int main()
{
        int *calificaciones, cantidadCalificaciones;

        system("clear");

        printf("Cantidad de calificaciones:\n");
        scanf("%d", &cantidadCalificaciones);

        calificaciones = (int *)malloc(cantidadCalificaciones * sizeof(int));

        if (calificaciones == NULL)
        {
                printf("Error al asignar memoria.");
                return 1;
        }

        for (int i = 0; i < cantidadCalificaciones; i++)
        {
                printf("Calificacion %d:\n", i + 1);
                scanf("%d", &calificaciones[i]);
        }

        printf("Arreglo antes de ordenar:\n");

        mostrarArreglo(calificaciones, cantidadCalificaciones);

        bubbleSort(calificaciones, cantidadCalificaciones);

        printf("\nArreglo despues de ordenar:\n");

        mostrarArreglo(calificaciones, cantidadCalificaciones);

        free(calificaciones);
        calificaciones = NULL;

        return 0;
}

void mostrarArreglo(int *arreglo, int tamano)
{
        for (int i = 0; i < tamano; i++)
        {
                printf("%d", arreglo[i]);
                if (i < tamano - 1)
                {
                        printf(", ");
                }
        }
}

void bubbleSort(int *arreglo, int tamano)
{
        int i, j, temp;

        for (i = 0; i < tamano - 1; i++)
        {
                for (j = 0; j < tamano - 1 - i; j++)
                {
                        if (arreglo[j] > arreglo[j + 1])
                        {
                                temp = arreglo[j];
                                arreglo[j] = arreglo[j + 1];
                                arreglo[j + 1] = temp;
                        }
                }
        }
}
