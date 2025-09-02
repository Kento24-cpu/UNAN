// El siguiente programa debe pedir las temperaturas en diferentes días, el programa debe pedir la
// cantidad de días y la cantidad de horas que se registrara las temperaturas, se debe asignar memoria
// tanto para los días como para las temperaturas, completar el siguiente programa para que pida todas
// las temperaturas y luego muestre el promedio de temperatura por día.

#include <stdio.h>
#include <stdlib.h>

int main()
{
        float **temperaturas = NULL;
        int tamano_filas, tamano_columnas;
        float promedio_dia; // Nueva variable.

        printf("Ingrese cantidad de dias en que se registraran temperaturas : ");
        scanf("%d", &tamano_filas);

        printf("Ingrese cada cuantas horas se registraran temperaturas al dia : ");
        scanf("%d", &tamano_columnas);

        tamano_columnas = 24 / tamano_columnas;

        // Se dimensiona la matriz en 2 pasos:
        // 1) Se reserva espacio para un 'vector de punteros a float*'
        // Este vector de punteros, corresponde a un vector de vectores dinámicos
        // que aún no han sido dimensionados. En total se necesitan 'tamano_filas * sizeof(float *)'
        // bytes, ya que la matriz tiene 'tamano_filas' filas.
        temperaturas = (float **)malloc(tamano_filas * sizeof(float *));

        // Validacion de asignacion.
        if (temperaturas == NULL)
        {
                printf("Error al asignar memoria para los dias.\n");
                return 1;
        }

        // 2 ) Luego cada fila, que es un vector dinámico sin dimensionar,
        // se dimensiona de la manera que vimos ya para los vectores dinámicos.
        // Para cada fila se usan 'tamano_columnas * sizeof(float)' bytes.
        for (int i = 0; i < tamano_filas; i = i + 1)
        {
                temperaturas[i] = (float *)malloc(tamano_columnas * sizeof(float));

                // Validacion al asignar memoria.
                if (temperaturas[i] == NULL)
                {
                        printf("Error al asignar memoria del dia %d.\n", i + 1);

                        // Liberar memoria previamente asignada.
                        for (int j = 0; j < i; j++)
                                free(temperaturas[j]);
                }

                free(temperaturas);
                return 1;
        }

        // Pedir y guardar las temperaturas
        for (int i = 0; i < tamano_filas; i++)
        {
                printf("\n--- Dia %d ---\n", i + 1);
                for (int j = 0; j < tamano_columnas; j++)
                {
                        printf("Ingrese temperatura %d: ", j + 1);
                        scanf("%f", &temperaturas[i][j]);
                }
        }

        // Calcular y mostrar el promedio por dia
        printf("\n--- Promedio de temperaturas por dia ---\n");
        for (int i = 0; i < tamano_filas; i++)
        {
                float suma = 0;
                for (int j = 0; j < tamano_columnas; j++)
                {
                        suma += temperaturas[i][j];
                }
                promedio_dia = suma / tamano_columnas;
                printf("Promedio del Dia %d: %.2f\n", i + 1, promedio_dia);
        }

        // Liberar la memoria asignada
        for (int i = 0; i < tamano_filas; i++)
        {
                free(temperaturas[i]);
        }

        free(temperaturas);

        return 0;
}