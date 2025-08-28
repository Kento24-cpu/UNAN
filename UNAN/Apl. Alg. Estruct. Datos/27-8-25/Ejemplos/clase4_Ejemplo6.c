#include <stdio.h>

int main()
{
        FILE *fp;
        char buffer[100] = "Esto es un texto dentro del fichero.\n";

        fp = fopen("fichero.txt", "r+");

        fprintf(fp, buffer);
        fprintf(fp, "%s", "\nEsto es otro texto dentro del fichero.");

        fclose(fp);

        return 0;
}