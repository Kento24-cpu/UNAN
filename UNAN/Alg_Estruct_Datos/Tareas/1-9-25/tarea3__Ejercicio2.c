// Actividad 2: El ejercicio guarda la información de un producto, realice una modificación
// al ejercicio para que pregunte al usuario cuantos productos desea guardar y lea e imprima los datos
// de todos los productos.

// Se tiene la siguiente declaración de registro:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h> // Para la funcion getch().

struct producto
{
        int codigo;
        char descripcion[41];
        float precio;
};

int main()
{
        struct producto *prod;
        int cantidad, i; // Nueva declaracion de variables tipo entero.

        system("clear"); // Limpiar consola.

        // Preguntar al usuario la cantidad de productos.
        printf("Cantidad de productos a ingresar:\n");
        scanf("%d", &cantidad);

        prod = (struct producto *)malloc(cantidad * sizeof(struct producto)); // Reescritura de codigo.

        // Validacion de aignacion.
        if (prod == NULL)
        {
                printf("Error al asignar memoria\n");
                return 1;
        }

        // Leer los productos.
        for (i = 0; i < cantidad; i++)
        {
                printf("|---Producto %d---|\n", i + 1);
                printf("Codigo de producto:\n");
                scanf("%d", &prod[i].codigo);
                printf("Descripcion del producto:\n");
                // Limpiar el buffer antes de leer la cadena.
                while ((getchar()) != '\n')
                        ;
                fgets(prod[i].descripcion, 41, stdin);

                // Remover el salto de linea que añade fgets.
                prod[i].descripcion[strcspn(prod[i].descripcion, "\n")] = 0;
                printf("Precio del producto:\n");
                scanf("%f", &prod[i].precio);
        }

        system("clear"); // Limpiar consola.

        // Escribir los productos.
        printf("|--- Productos ---|\n\n");
        for (i = 0; i < cantidad; i++)
        {
                printf("|--- Producto %d ---|\n", i + 1);
                printf("Codigo: %i\n", prod[i].codigo);
                printf("Descripcion: %s\n", prod[i].descripcion);
                printf("Precio: %.2f\n", prod[i].precio);
        }

        free(prod);

        getch();

        return 0;
}