#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;

    system("clear");

    printf("Validacion de edad\nEscriba su edad:\n");
    scanf("%i", &edad);

    if (edad >= 17)
    {
        printf("Excelente!, puede entrar a nuestro club.");
    }
    else if (edad <= 16)
    {
        printf("Necesita a un adulto para ingresar.");
    }

    return 0;
}