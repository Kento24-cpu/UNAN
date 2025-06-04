// Declarar una estructura, crear una variable de ese tipo, aignar y mostrar sus valores.
// Estudiantes, nombres, carnet, edad, sexo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ESTUDIANTES
{
    char nombre[99];
    char carnet[11];
    int edad;
    char sexo;
    float nota;
};

int main()
{
    int numero, i, carnetTemporal;

    struct ESTUDIANTES *cantidadEstudiantes;

    system("clear");

    printf("Cantidad de estudiantes a ingresar:\n");
    scanf("%d", &numero);

    cantidadEstudiantes = (struct ESTUDIANTES *)malloc(numero * sizeof(struct ESTUDIANTES));

    if (cantidadEstudiantes == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (i = 0; i < numero; i++)
    {
        printf("Ingrese los datos del estudiante %d (Nombre, carnet (8 digitos), edad, sexo (M/F) y nota (0 - 100)):\n", i + 1);
        scanf("%s", cantidadEstudiantes[i].nombre);
        scanf("%d", &carnetTemporal);
        sprintf(cantidadEstudiantes[i].carnet, "%02d-%05d-%01d",
                carnetTemporal / 1000000,
                (carnetTemporal / 10) % 100000,
                carnetTemporal % 10);
        scanf("%d", &cantidadEstudiantes[i].edad);
        scanf(" %c", &cantidadEstudiantes[i].sexo);
        scanf("%f", &cantidadEstudiantes[i].nota);
    }

    system("pause");
    system("clear");
    printf("Datos de los estudiantes\n\n");

    for (i = 0; i < numero; i++)
    {
        printf("Estudiante %d\n------------\n", i + 1);
        printf("Nombre: %s\n", cantidadEstudiantes[i].nombre);
        printf("Carnet: %s\n", cantidadEstudiantes[i].carnet);
        printf("Edad: %d\n", cantidadEstudiantes[i].edad);
        printf("Sexo: %c\n", cantidadEstudiantes[i].sexo);
        printf("Nota: %.2f\n", cantidadEstudiantes[i].nota);
        printf("\n");
    }

    free(cantidadEstudiantes);
    cantidadEstudiantes = NULL;

    return 0;
}