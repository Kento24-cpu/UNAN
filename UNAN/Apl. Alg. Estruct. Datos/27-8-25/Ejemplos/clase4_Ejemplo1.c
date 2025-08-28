// FICHEROS EN C.
#include <stdio.h>

int main()
{
        FILE *fp;

        fp = fopen("fichero.txt", "r");

        if (fp == NULL)
                printf("Error en la apertura, es posible que el fichero no exista.\n");

        fclose(fp);

        return 0;
}