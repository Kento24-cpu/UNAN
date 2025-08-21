// Ejercicio 2: Funciones para Manejo de Cadenas.
//      Implementar las siguientes funciones:
//              longitud_cad(char *cadena)
//              Calcula la longitud de una cadena sin usar
//              strlen()
//              copia_cadena(char *destino, char *origen)
//              : Copia una cadena sin usar
//              strcpy()
//      Requisitos importantes:
//              NO usar
//                      gets()
//              - usar
//                      fgets()
//              para entrada segura
//              Incluir un programa
//                      main()
//              que pruebe ambas funciones
//              Validar punteros NULL antes de usarlos

#include <stdio.h>
#include <stdlib.h> // Para funciones como system().
#include <string.h> // Para funcion strcspn().

// Declaracion de funciones.
int longitud_cad(char *cadena);
void copia_cadena(char *destino, char *origen);

// Funcion principal.
int main()
{
        // Declaracion de variables.
        char cadena1[99], cadena2[99];

        system("clear"); // Limpia la consola.

        // Introduccion de cadena.
        printf("Cadena a introducir:\n");
        fgets(cadena1, 99, stdin);

        // Eliminar salto de linea de fgets().
        cadena1[strcspn(cadena1, "\n")] = 0;

        // Mostrar cadena.
        printf("Cadena introducida: %s\n", cadena1);

        // Mostrar longitud de cadenas.
        longitud_cad(cadena1);
        printf("Longitud de cadena: %d\n", longitud_cad(cadena1));

        // Mostrar copia de cadena.
        copia_cadena(cadena2, cadena1);
        printf("Cadena copiada: %s\n", cadena2);

        system("pause"); // Pausa el programa.
        system("clear"); // Limpiar consola.

        return 0;
}

// Funciones.
int longitud_cad(char *cadena)
{
        if (cadena == NULL)
                return 0; // Validacion de punteros.

        char *ptr = cadena;  // Inicializacion de puntero.
        while (*ptr != '\0') // Bucle que se ejecuta mientras el caracter actual que apunta "ptr" no sea terminador nulo.
                ptr++;       // Se avanza al siguiente caracter.

        return ptr - cadena; // Obtencion de longitud mediante diferencia de direcciones.
}

void copia_cadena(char *destino, char *origen)
{
        if (destino == NULL || origen == NULL)
                return; // Validacion de punteros.

        while (*origen != '\0') // Bucle que se ejecuta mientras el caracter actual que apunta "origen" no sea terminador nulo.
        {
                *destino = *origen; // Punteros bajo el mismo valor;
                destino++;          // Incremento de caracter.
                origen++;           // Incremento de caracter.
        }
        *destino = '\0'; // Asegurar que la cadena termine con '\0'.
}

// NOTA TECNICA
/*
                ¿Por que se verifica NULL en validacion de punteros?
        Se verifica la nulidad de un puntero para prevenir errores de segmentación y comportamiento indefinido al acceder a una
        dirección de memoria inválida. Un puntero nulo, representado por la constante NULL, indica que el puntero no apunta a ninguna
        ubicación de memoria válida. Comprobar si un puntero es nulo antes de usarlo evita que el programa intente acceder a datos
        inexistentes o modificar áreas de memoria protegidas, lo que podría causar un fallo o un comportamiento inesperado.
*/
