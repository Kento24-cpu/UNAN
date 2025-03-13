#include <stdio.h>

int edad;
char nombre[30];

int main()
{
    printf("Nombre y edad:\n");
    scanf("%s %i", &nombre, &edad);

    printf("Tu nombre es: %s\ntu edad es: %i", nombre, edad);

    return 0;
}
