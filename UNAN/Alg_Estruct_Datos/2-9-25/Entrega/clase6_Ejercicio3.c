// Registrar dinámico de alturas de montañas, donde el usuario puede ir agregando
// más montañas y la memoria se ajusta automáticamente. (Realloc)

#include <stdio.h>
#include <stdlib.h>

int main()
{
        float *alturas = NULL;
        int capacidad = 0;
        int num_montanas = 0;
        char respuesta;

        printf("Registro de Alturas de Montanas.\n");

        do
        {
                capacidad++;

                float *temp = (float *)realloc(alturas, capacidad * sizeof(float));

                if (temp == NULL)
                {
                        printf("Error: No se pudo reasignar la memoria.\n");
                        free(alturas);
                        return 1;
                }

                alturas = temp;

                printf("\nIngrese la altura de la montana %d (en metros): ", num_montanas + 1);
                scanf("%f", &alturas[num_montanas]);

                num_montanas++;

                printf("Desea agregar otra montana? (s/n): ");
                scanf(" %c", &respuesta);

        } while (respuesta == 's' || respuesta == 'S');

        // Mostrar las alturas registradas
        printf("\nAlturas de Montanas Registradas.\n");
        if (num_montanas > 0)
        {
                for (int i = 0; i < num_montanas; i++)
                        printf("Montana %d: %.2f metros\n", i + 1, alturas[i]);
        }
        else
                printf("No se registraron montanas.\n");

        free(alturas);

        return 0;
}