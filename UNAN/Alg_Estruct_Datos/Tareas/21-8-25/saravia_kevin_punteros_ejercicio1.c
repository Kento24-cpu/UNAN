// Ejercicio 1: Manipulación de Variables con Punteros.
// Crear un programa que:
// Declare dos variables
// a y b
// de tipo entero.
// Use un puntero para:
// Leer los valores de ambas variables.
// Modificar sus contenidos.
// Mostrar las direcciones de memoria y contenidos antes y después de las modificaciones.

#include <stdio.h>
#include <stdlib.h> // Para funciones como system().

int main()
{
        // Declaracion de variables.
        int a = 5, b = 10, *ptr;

        system("clear"); // Limpia la consola.

        // Inicializacion de puntero a NULL.
        ptr = NULL;

        // Valores antes de su modificacion
        printf("Antes de modificar:\n");
        printf("Variable a: valor = %d, direccion = %p\nVariable b: valor = %d, direccion = %p\n\n", a, &a, b, &b);

        // Modificacion de valores
        /*
                Se accede a la direccion de memoria mediante el operador de direccion "&", luego se usa el operador
                de desreferencia "*" para cambiar el valor de dicha variable.
        */
        ptr = &a;  // Referencia a la variable.
        *ptr = 15; // Reasignacion de valor.

        ptr = &b;  // Referencia a la variable.
        *ptr = 20; // Reasignacion de valor.

        // Valores despues de su modificacion
        printf("Despues de modificar:\n");
        printf("Variable a: valor = %d, direccion = %p\nVariable b: valor = %d, direccion = %p\n\n", a, &a, b, &b);

        system("pause"); // Pausa el programa.
        system("clear"); // Limpia la consola.

        // Liberacion de memoria.
        free(ptr);
        ptr = NULL;

        return 0;
}

// NOTA TECNICA
/*
                Un error al usar punteros.
                La desreferenciación de un puntero no inicializado en C:
        Ocurre cuando se intenta acceder o modificar el valor al que apunta un puntero que no ha sido asignado a ninguna
        dirección de memoria válida. Esto puede llevar a errores graves en tiempo de ejecución, como bloqueos del programa,
        ya que se intenta acceder a una zona de memoria inaccesible o inexistente.

                Ejemplo del error:
        int *ptr; --Puntero no inicializado
        *ptr = 10; --Error: Desreferenciación de un puntero no inicializado

                ¿Cómo evitar la desreferenciación de punteros no inicializados?
        Inicializar los punteros:
        Siempre que declares un puntero, asígnale una dirección de memoria válida antes de usarlo. Si aún no tienes la dirección,
        puedes inicializarlo a NULL para indicar que no apunta a nada.
        Verificar la validez del puntero:
        Antes de desreferenciar un puntero, asegúrate de que no sea NULL y que apunte a una dirección de memoria válida.

                Ejemplo:
        int *ptr; --Puntero no inicializado.
        if (ptr != NULL) {  --Verificar si el puntero es válido.
        *ptr = 10;          --Desreferenciación segura.
        } else {
                --Manejo del caso NULL.
        }
*/
