// Elaborar un programa que utiliza la función fopen para crear un archivo de texto llamada
// SALIDA.TXT, que almacene desde la consola todo el texto que se digite y finalice con la orden
// CTRL + Z.

#include <stdio.h>
#include <stdlib.h>

int main()
{
        FILE *pArchivo;
        int caracter;

        // 1. Abrir el archivo en modo de escritura ("w")
        pArchivo = fopen("SALIDA.TXT", "w");

        // 2. Verificar si el archivo se abrió correctamente
        if (pArchivo == NULL)
        {
                perror("Error al abrir o crear el archivo SALIDA.TXT");
                return 1;
        }

        printf("Escribe el texto que deseas guardar en SALIDA.TXT.\n");
        printf("Para finalizar, presiona CTRL+Z y luego Enter.\n\n");

        // 3. Leer caracteres de la consola y escribirlos en el archivo
        // El bucle se detiene cuando se detecta el fin de archivo (EOF)
        while ((caracter = getchar()) != EOF)
        {
                fputc(caracter, pArchivo);
        }

        // 4. Cerrar el archivo
        fclose(pArchivo);

        printf("\nTexto guardado correctamente en SALIDA.TXT.\n");

        return 0;
}