// Se desea registrar los niveles de agua medidos diariamente en un embalse
// durante varios días, inicializando todos los valores en cero.(Calloc)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
        int i, dias;
        float *nivelAgua;

        printf("Cantidad de dias a registrar:\n");
        scanf("%d", &dias);

        nivelAgua = (float *)calloc(dias, sizeof(float));

        if (nivelAgua == NULL)
        {
                printf("Error al asignar memoria.\n");
                return 1;
        }

        for (i = 0; i < dias; i++)
        {
                printf("Nivel de agua del dia %d:\n", i + 1);
                scanf("%f", &nivelAgua[i]);
        }

        printf("Registros del nivel del agua por dia.\n");

        for (i = 0; i < dias; i++)
                printf("Dia %d: %.2f\n", i + 1, nivelAgua[i]);

        free(nivelAgua);

        getch();

        return 0;
}