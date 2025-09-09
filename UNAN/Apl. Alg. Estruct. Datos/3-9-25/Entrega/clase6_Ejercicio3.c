#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ESTUDIANTES 10

void ordenar_nombres(char **nombres, int n)
{
        int i, j;
        char *temp;
        for (i = 0; i < n - 1; i++)
        {
                for (j = 0; j < n - i - 1; j++)
                {
                        if (strcmp(nombres[j], nombres[j + 1]) > 0)
                        {
                                temp = nombres[j];
                                nombres[j] = nombres[j + 1];
                                nombres[j + 1] = temp;
                        }
                }
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

        nombres = (char **)malloc(NUM_ESTUDIANTES * sizeof(char *));
        if (nombres == NULL)
        {
                printf("Error al asignar memoria.\n");
                return 1;
        }

        printf("Ingrese 10 nombres de estudiantes:\n");
        for (i = 0; i < NUM_ESTUDIANTES; i++)
        {
                printf("Estudiante %d: ", i + 1);
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                nombres[i] = (char *)malloc(strlen(buffer) + 1);
                if (nombres[i] == NULL)
                {
                        printf("Error al asignar memoria.\n");
                        return 1;
                }
                strcpy(nombres[i], buffer);
        }

        printf("\nLista de nombres sin ordenar:\n");
        imprimir_nombres(nombres, NUM_ESTUDIANTES);

        ordenar_nombres(nombres, NUM_ESTUDIANTES);

        printf("\nLista de nombres ordenada (método de burbuja):\n");
        imprimir_nombres(nombres, NUM_ESTUDIANTES);

        for (i = 0; i < NUM_ESTUDIANTES; i++)
        {
                free(nombres[i]);
        }
        free(nombres);

        return 0;
}