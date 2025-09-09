#include <stdio.h>
#include <stdlib.h>

int main()
{
        int cantEstudiantes, *estudiantes, i, auxiliar, pasada;

        printf("Cantidad de estudiantes a ingresar:\n");
        scanf("%d", &cantEstudiantes);

        estudiantes = (int *)calloc(cantEstudiantes, sizeof(int));

        if (estudiantes == NULL)
        {
                printf("Error al asignar memoria.\n");
                return 1;
        }

        for (i = 0; i < cantEstudiantes; i++)
        {
                printf("Calificacion del estudiante %d:\n", i + 1);
                scanf("%d", &estudiantes[i]);
        }

        printf("Calificaciones antes de ordenar:\n");

        for (i = 0; i < cantEstudiantes; i++)
                printf("%d\n", estudiantes[i]);

        for (pasada = 1; pasada < cantEstudiantes; pasada++)
        {
                for (i = 0; i < cantEstudiantes - 1; i++)
                {
                        if (estudiantes[i] > estudiantes[i + 1])
                        {
                                auxiliar = estudiantes[i];
                                estudiantes[i] = estudiantes[i + 1];
                                estudiantes[i + 1] = auxiliar;
                        }
                }
        }

        printf("Calificaciones despues de ordenar:\n");

        for (i = 0; i < cantEstudiantes; i++)
                printf("%d\n", estudiantes[i]);

        free(estudiantes);
        estudiantes = NULL;

        return 0;
}