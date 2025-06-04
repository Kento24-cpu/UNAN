#include <stdio.h>
#include <string.h>

int main()
{
    // strncpy. Escoger los ultimos caracteres de un string.
    // char str[] = "Este es un ejemplo";
    // char last9[10]; // Necesitas espacio para 9 caracteres + el terminador nulo
    // int len = strlen(str);

    // if (len >= 9)
    // {
    //     strncpy(last9, str + len - 9, 9); // Copia los últimos 9 caracteres
    //     last9[9] = '\0';                  // Asegura que la cadena esté terminada
    // }
    // else
    // {
    //     strncpy(last9, str, len); // Si es más corta, copia todos los caracteres
    //     last9[len] = '\0';
    // }

    // printf("Los ultimos 9 caracteres son: %s\n", last9);

    // bucle de strncpy.
    char str[] = "Este es un ejemplo";
    char last9[10];
    int len = strlen(str);
    int i;

    if (len < 9)
    {
        strcpy(last9, str);
        last9[len] = '\0';
    }
    else
    {
        for (i = 0; i < 9; i++)
        {
            last9[i] = str[len - 9 + i];
        }
        last9[9] = '\0';
    }

    printf("Los ultimos 9 caracteres son: %s\n", last9);
    return 0;
}