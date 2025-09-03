// Elaborar un programa que lea archivo creado en el enunciado anterior llamado SALIDA.TXT, y
// muestre como resultado el número de líneas del archivo.

#include <stdio.h>
#include <stdlib.h>

int main()
{
        FILE *pArchivo;
        int caracter;
        int contador_lineas = 0;

        // 1. Abrir el archivo SALIDA.TXT en modo de lectura ("r")
        pArchivo = fopen("SALIDA.TXT", "r");

        // 2. Manejo de errores: verificar si el archivo existe y se pudo abrir
        if (pArchivo == NULL)
        {
                perror("Error al abrir el archivo SALIDA.TXT. Asegúrate de que existe.");
                return 1;
        }

        // 3. Leer el archivo carácter por carácter hasta el final
        while ((caracter = fgetc(pArchivo)) != EOF)
        {
                // Contar los saltos de línea para determinar el número de líneas
                if (caracter == '\n')
                        contador_lineas++;
        }

        // 4. Asegurar que se cuente la última línea si no termina en '\n'
        // y el archivo no está vacío
        if (contador_lineas > 0 || (caracter != EOF && ftell(pArchivo) > 0))
                contador_lineas++;

        // 5. Cerrar el archivo
        fclose(pArchivo);

        printf("El archivo SALIDA.TXT tiene %d linea(s).\n", contador_lineas);

        return 0;
}