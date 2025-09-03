// Diseñe programa que lea el fichero primos.txt generado por el programa anterior y muestre por
// pantalla su contenido

#include <stdio.h>
#include <stdlib.h>

int main()
{
        FILE *pArchivo;
        int numero;

        // Abrir el archivo primos.txt en modo de lectura ("r")
        pArchivo = fopen("primo.txt", "r");

        // Verificar si el archivo se abrió correctamente
        if (pArchivo == NULL)
        {
                perror("Error al abrir el archivo primos.txt. Asegúrate de que existe.");
                return 1;
        }

        printf("Contenido del archivo primos.txt:\n");
        printf("----------------------------------\n");

        // Leer cada número del archivo y mostrarlo en la pantalla
        while (fscanf(pArchivo, "%d", &numero) == 1)
                printf("%d\n", numero);

        // Cerrar el archivo
        fclose(pArchivo);

        return 0;
}