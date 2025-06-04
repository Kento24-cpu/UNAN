// Ejercicio 3.
// Realice un programa en C que, al recibir como dato una cadena de texto, escriba esa línea en forma inversa.
// Por ejemplo, si la línea de texto dice: 	Hola México

// El programa debe escribir: 	ocixéM aloH

#include <stdio.h>
#include <string.h>

int main()
{
    char cadena[1000];
    int longitud;
    int i;

    printf("Ingrese una cadena de texto: ");
    fgets(cadena, sizeof(cadena), stdin);

    cadena[strcspn(cadena, "\n")] = '\0';

    longitud = strlen(cadena);

    printf("La cadena invertida es: ");
    for (i = longitud - 1; i >= 0; i--)
    {
        printf("%c", cadena[i]);
    }
    printf("\n");

    return 0;
}
