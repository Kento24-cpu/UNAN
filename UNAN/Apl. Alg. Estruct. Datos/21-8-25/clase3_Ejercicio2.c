// Escribir un programa que ponga en mayusculas el primer caracter de una cadena de caracteres
// y todo aquel caracter que siga a un punto, utilizando un puntero a dicha cadena.

#include <stdio.h>
#include <ctype.h>  // Para la funcion toupper()
#include <string.h> // Para la funcion fgets()

void capitalize_string(char *str);

int main()
{
        char cadena[256];

        printf("Ingrese una cadena de texto: \n");

        fgets(cadena, sizeof(cadena), stdin);

        printf("Cadena original: %s", cadena);

        capitalize_string(cadena);

        printf("Cadena modificada: %s", cadena);

        return 0;
}

void capitalize_string(char *str)
{
        if (*str != '\0')
                *str = toupper(*str);

        for (int i = 0; str[i] != '\0'; i++)
        {
                if (str[i] == '.')
                {
                        int j = i + 1;
                        while (str[j] != '\0' && isspace(str[j]))
                        {
                                j++;
                        }

                        if (str[j] != '\0')
                        {
                                str[j] = toupper(str[j]);
                        }
                }
        }
}