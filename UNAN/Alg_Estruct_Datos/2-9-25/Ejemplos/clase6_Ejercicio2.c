// Un laboratorio clínico quiere almacenar resultados de análisis sanguíneos (enteros que
// representan niveles medidos). Se deben inicializar en cero antes de registrar resultados.

#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n, i;
        int *resultados;

        printf("Ingrese el numero de analisis realizados: ");
        scanf("%d", &n);

        // Asignación dinámica con calloc (inicializa en 0)
        resultados = (int *)calloc(n, sizeof(int));

        if (resultados == NULL)
        {
                printf("Error al asignar memoria\n");
                return 1;
        }

        for (i = 0; i < n; i++)
        {
                printf("Resultado del analisis %d: ", i + 1);
                scanf("%d", &resultados[i]);
        }

        printf("\nResultados registrados:\n");

        for (i = 0; i < n; i++)
        {
                printf("Analisis %d: %d\n", i + 1, resultados[i]);
        }

        free(resultados);

        return 0;
}
