#include <stdio.h>

int main()
{
        FILE *fp;
        char cadena[] = "Mostrando el uso de fputs en un fichero.\n";

        fp = fopen("fichero.txt", "r+");

        fputs(cadena, fp);

        fclose(fp);

        return 0;
}