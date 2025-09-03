// Un programa meteorológico necesita almacenar las temperaturas diarias de una ciudad
// durante un número de días definido por el usuario.

#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n, i;
        float *temperaturas;

        printf("Ingrese el numero de dias a registrar: ");
        scanf("%d", &n);

        // Asignación dinámica con malloc
        temperaturas = (float *)malloc(n * sizeof(float));

        if (temperaturas == NULL)
        {
                printf("Error: no se pudo asignar memoria\n");
                return 1;
        }

        for (i = 0; i < n; i++)
        {
                printf("Temperatura del dia %d: ", i + 1);
                scanf("%f", &temperaturas[i]);
        }

        printf("\nTemperaturas registradas:\n");

        for (i = 0; i < n; i++)
        {
                printf("Dia %d: %.2f grado C\n", i + 1, temperaturas[i]);
        }

        free(temperaturas);

        return 0;
}