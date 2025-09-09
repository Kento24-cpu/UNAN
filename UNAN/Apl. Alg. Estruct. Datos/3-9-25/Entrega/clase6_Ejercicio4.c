#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_NOMBRES 8

void ordenar_por_longitud(char **nombres, int n)
{
        int i, j, min_idx;
        char *temp;
        for (i = 0; i < n - 1; i++)
        {
                min_idx = i;
                for (j = i + 1; j < n; j++)
                {
                        if (strlen(nombres[j]) < strlen(nombres[min_idx]))
                        {
                                min_idx = j;
                        }
                }

                temp = nombres[min_idx];
                nombres[min_idx] = nombres[i];
                nombres[i] = temp;
        }
}

void imprimir_nombres(char **nombres, int n)
{
        for (int i = 0; i < n; i++)
        {
                printf("%s\n", nombres[i]);
        }
}

int main()
{
        char **nombres;
        char buffer[100];
        int i;

        nombres = (char **)malloc(NUM_NOMBRES * sizeof(char *));
        if (nombres == NULL)
        {
                printf("Error: No se pudo asignar memoria.\n");
                return 1;
        }

        printf("Ingrese 8 nombres de personas:\n");
        for (i = 0; i < NUM_NOMBRES; i++)
        {
                printf("Nombre %d: ", i + 1);
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                nombres[i] = (char *)malloc(strlen(buffer) + 1);
                if (nombres[i] == NULL)
                {
                        printf("Error: No se pudo asignar memoria.\n");
                        return 1;
                }
                strcpy(nombres[i], buffer);
        }

        printf("\nLista de nombres original:\n");
        imprimir_nombres(nombres, NUM_NOMBRES);

        ordenar_por_longitud(nombres, NUM_NOMBRES);

        printf("\nLista de nombres ordenada por longitud (de más corto a más largo):\n");
        imprimir_nombres(nombres, NUM_NOMBRES);

        for (i = 0; i < NUM_NOMBRES; i++)
        {
                free(nombres[i]);
        }
        free(nombres);

        return 0;
}