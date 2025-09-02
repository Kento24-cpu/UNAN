// La función fscanf presenta un problema cuando leemos cadenas: sólo lee una ((palabra)), es decir, se
// detiene al llegar a un blanco. Aprendimos a usar entonces una función, gets, que leía una línea
// completa. Hay una función equivalente para ficheros de texto Ejemplo de fgets,:

// char *fgets(char cadena[], int max_tam, FILE *fichero);

#include <stdio.h>
#include <string.h>

int main()
{
        FILE *p;
        char st[80];
        char file[80];

        printf("Archivo a leer: ");
        gets(file);

        p = fopen(file, "r");

        if (p)
        {
                fgets(st, 60, p);
                st[strlen(st)] = 0;
                printf("Contenido del archivo: %s\n", st);
                fclose(p);
        }
        else
                printf("Archivo no existe.\n");

        return 0;
}
