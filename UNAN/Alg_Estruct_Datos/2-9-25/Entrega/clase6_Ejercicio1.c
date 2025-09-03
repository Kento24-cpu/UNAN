// Un programa necesita almacenar las longitudes de varios ríos de un país. La
// cantidad de ríos se conoce solo en tiempo de ejecución. (Malloc)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
        int i, numRios;
        float *longitud;

        system("clear");

        printf("Cantidad de rios:\n");
        scanf("%d", &numRios);

        longitud = malloc(numRios * sizeof(float));

        if (longitud == NULL)
        {
                printf("Error al asignar memoria.\n");
                return 1;
        }

        for (i = 0; i < numRios; i++)
        {
                printf("Longitud del rio %d:\n", i + 1);
                scanf("%f", &longitud[i]);
        }

        system("clear");

        printf("Longitud de los rios:\n\n");
        for (i = 0; i < numRios; i++)
                printf("Longitud del rio %d: %.2f\n", i + 1, longitud[i]);

        free(longitud);

        getch();

        return 0;
}
