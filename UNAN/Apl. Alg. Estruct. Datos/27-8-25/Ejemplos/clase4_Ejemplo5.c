#include <stdio.h>

int main()
{
        FILE *fp;
        char buffer[100];

        fp = fopen("fichero.txt", "r");

        fscanf(fp, "%s", buffer);
        printf("%s", buffer);

        fclose(fp);

        return 0;
}