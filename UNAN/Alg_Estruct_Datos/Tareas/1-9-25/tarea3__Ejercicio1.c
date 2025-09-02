// Ingresar por teclado un entero que represente la cantidad de elementos que debe crearse para un arreglo.
// Crear el arreglo en forma dinámica, cargar e imprimir sus datos. Hacer todo en el main.

// Actividad 1: Realizar una modificación al programa para que cree otro arreglo de forma dinámica con el
// mismo tamaño, y que almacene en este nuevo puntero todos los datos de “*pe” invertidos.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
        int *pe;
        int *pe_inverted; // Nuevo arreglo.
        int tam;
        int f;

        system("clear"); // Limpiar consola.

        printf("Cuantos elementos tendra el arreglo:\n");
        scanf("%i", &tam);

        pe = malloc(tam * sizeof(int));

        // Validacion de asignacion.
        if (pe == NULL)
        {
                printf("Error al asignar memoria.\n");
                return 1;
        }

        // Asignacion dinamica del nuevo arreglo.
        pe_inverted = malloc(tam * sizeof(int));

        // Validacion de asignacion.
        if (pe_inverted == NULL)
        {
                printf("Error al asignar memoria.\n");
                return 1;
        }

        for (f = 0; f < tam; f++)
        {
                printf("Ingrese elemento %i:\n", f + 1);
                scanf("%i", &pe[f]);
        }

        system("clear"); // Limpiar consola.

        printf("Contenido del vector dinamico original:\n");

        for (f = 0; f < tam; f++)
        {
                printf("%i ", pe[f]);
        }

        // Cargar elementos para el array invertido.
        for (f = 0; f < tam; f++)
        {
                pe_inverted[f] = pe[tam - 1 - f];
        }

        // Imprimir arreglo invertido.
        printf("\nContenido del vector dinamico invertido:\n");
        for (f = 0; f < tam; f++)
        {
                printf("%i ", pe_inverted[f]);
        }

        free(pe);
        free(pe_inverted); // Liberacion de memoria del nuevo arreglo.

        getch();

        return 0;
}
