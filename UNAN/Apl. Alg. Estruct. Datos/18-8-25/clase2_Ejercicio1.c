#include <stdio.h>
#include <stdlib.h>

struct ESTUDIANTES
{
        char nombre[99];
        int edad;
        char correo[99];
};

int main()
{
        int numero, i;

        struct ESTUDIANTES *cantidadEstudiantes;

        system("clear");

        printf("Estudiantes a ingresar:\n");
        scanf("%d", &numero);

        cantidadEstudiantes = (struct ESTUDIANTES *)malloc(numero * sizeof(struct ESTUDIANTES));

        if (cantidadEstudiantes == NULL)
        {
                printf("Error al asignar memoria.\n");
                return 1;
        }

        for (i = 0; i < numero; i++)
        {
                printf("Ingrese los datos del estudiante %d:\n", i + 1);
                printf("Nombre:\n");
                scanf("%s", cantidadEstudiantes[i].nombre);
                printf("Edad:\n");
                scanf("%d", &cantidadEstudiantes[i].edad);
                printf("Correo:\n");
                scanf("%s", cantidadEstudiantes[i].correo);
        }

        system("pause");
        system("clear");

        printf("Datos de los estudiantes:\n\n");

        for (i = 0; i < numero; i++)
        {
                printf("Estudiante %d\n------------\n", i + 1);
                printf("Nombre: %s\n", cantidadEstudiantes[i].nombre);
                printf("Edad: %d\n", cantidadEstudiantes[i].edad);
                printf("Correo: %s\n", cantidadEstudiantes[i].correo);

                if (cantidadEstudiantes[i].edad < 18)
                        printf("El estudiante es menor de edad.\n");
                else
                        printf("El estudiante es mayor de edad.\n");

                printf("\n");
        }

        free(cantidadEstudiantes);
        cantidadEstudiantes = NULL;

        return 0;
}