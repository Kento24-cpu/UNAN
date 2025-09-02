// Realizar un programa que cree en memoria un array dinámico unidimensional de datos de tipo double.
// El programa pedirá inicialmente por teclado el número deseado de elementos de tal array, luego lo
// creará mediante asignación dinámica de memoria, a continuación, pedirá por teclado los datos a
// almacenar en dichos elementos del array, luego calculará la media aritmética de dichos datos, la
// presentará en pantalla y finalmente eliminará el array, liberando la memoria utilizada por el mismo.

#include <stdio.h>
#include <stdlib.h>

int main()
{
        double *p, media = 0;
        int numelem = 0, i;

        system("clear"); // Limpiar consola.

        do
        {
                printf("Dime Nº de elementos del array a crear:\n");
                scanf("%d", &numelem);
        } while (numelem < 1);

        // Crear array dinámico
        p = (double *)malloc(numelem * sizeof(double));

        if (p == NULL)
        {
                printf("Error al asignar memoria\n.");
                return 1;
        }

        system("clear"); // Limpiar consola.

        printf("Introduzca los datos del array:\n");

        for (i = 0; i < numelem; i++)
        {
                printf("Elemento %d:\n", i + 1);
                scanf("%lf", &p[i]); // Leer datos del array
        }

        for (i = 0; i < numelem; i++)
                media += p[i]; // Calcular la media media = media/numelem;

        media = media / numelem; // Calcula la media aritmetica.

        printf("\nLa media aritmética es: %lg\n", media);

        free(p); // Liberar memoria

        return 0;
}