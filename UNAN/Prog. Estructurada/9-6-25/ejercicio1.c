#include <stdio.h>
#include <stdlib.h>

int main()
{
        FILE *archivo;

        archivo = fopen("miArchivo.txt", "w");

        if (archivo == NULL)
                printf("archivo no cargado");
        else
        {
                printf(archivo, "mi texto de prueba\n");
                fclose(archivo);
                printf("archivo creado y guardado con exito\n");
        }

        return 0;
}