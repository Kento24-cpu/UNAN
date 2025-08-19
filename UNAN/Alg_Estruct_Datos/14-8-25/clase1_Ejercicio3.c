// Desarrolle un arreglo de estructura para un programa que lea una lista de alumnos y las
// notas correspondientes a una determinada asignatura; el resultado será el tanto por ciento
// (porcentaje) de los alumnos aprobados y reprobados.

#include <stdio.h>
#include <stdlib.h>

struct ESTUDIANTES
{
        char name[99];
        int nota, nota1, nota2;
};

int main()
{
        int numEst, i;
        char asignatura[99];

        struct ESTUDIANTES *cantEst;

        system("clear");

        printf("Estudiantes a ingresar:\n");
        scanf("%d", &numEst);

        cantEst = (struct ESTUDIANTES *)malloc(numEst * sizeof(struct ESTUDIANTES));

        if (cantEst == NULL)
        {
                printf("Error al asignar memoria.\n");
                return 1;
        }

        printf("Asignatura:\n");
        scanf("%s", asignatura);

        for (i = 0; i < numEst; i++)
        {
                printf("Nombre del estudiante: %d\n", i + 1);
                scanf("%s", cantEst[i].name);
                printf("Nota del primer parcial: (0 - 100)\n");
                scanf("%d", &cantEst[i].nota);
                printf("Nota del segundo parcial: (0 - 100)\n");
                scanf("%d", &cantEst[i].nota1);
                printf("Nota del tercer parcial parcial: (0 - 100)\n");
                scanf("%d", &cantEst[i].nota2);
        }

        system("clear");

        printf("Datos de los estudiantes.\nAsignatura: %s\n\n", asignatura);

        for (i = 0; i < numEst; i++)
        {
                float promedio = (float)(cantEst[i].nota + cantEst[i].nota1 + cantEst[i].nota2) / 3.0;

                printf("Estudiante %d\n------------\n", i + 1);
                printf("Nombre: %s\n", cantEst[i].name);
                printf("Nota del primer Parcial: %d\n", cantEst[i].nota);
                printf("Nota del segundo Parcial: %d\n", cantEst[i].nota1);
                printf("Nota del tercer Parcial: %d\n", cantEst[i].nota2);
                printf("Promedio del estudiante: %.2f\n", promedio);

                if (promedio < 60)
                        printf("El estudiante reprobo la materia.\n");
                else
                        printf("El estudiante aprobo la materia.\n");

                printf("\n");
        }

        free(cantEst);
        cantEst = NULL;

        return 0;
}
