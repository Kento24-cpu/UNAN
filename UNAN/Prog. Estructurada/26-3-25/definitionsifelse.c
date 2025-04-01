#include <stdio.h>
#include <stdlib.h>

int main()
{
    int selection, selection1;

    system("clear");

    printf("Definiciones sobre Keywords en C\nSeleccione una palabra para su definicion:\n");
    printf("Menu:\n(1)float\n(2)double\n(3)short\n(4)long\n(5)unsigned\n(6)signed\n(7)clear\n(8)stdlib.h\n(9)switch\n(10)case\n");
    scanf("%i", &selection);

    if (selection == 1)
    {
        printf("Definicion de Keyword: (1)float\n");
        printf("Devuelve una representación de coma flotante de un número.\n");
    }
    else if (selection == 2)
    {
        printf("Definicion de Keyword: (2)double\n");
        printf("Proporciona las magnitudes más grandes y pequeñas posibles para un número.\n");
    }
    else if (selection == 3)
    {
        printf("Definicion de Keyword: (3)short\n");
        printf("Se usa para modificar el rango de valores de los tipos de datos 'int' y 'char'.\n");
    }
    else if (selection == 4)
    {
        printf("Definicion de Keyword: (4)long\n");
        printf("Es un modificador de tipo de dato que se puede aplicar a los tipos de datos básicos para aumentar el rango y el tamaño de los valores que sus variables pueden almacenar.\n");
    }
    else if (selection == 5)
    {
        printf("Definicion de Keyword: (5)unsigned\n");
        printf("Le indica a la variable que no va a llevar signo (sin valores negativos).\n");
    }
    else if (selection == 6)
    {
        printf("Definicion de Keyword: (6)signed\n");
        printf("Define que el valor de una variable numérica puede ser positivo o negativo.\n");
    }
    else if (selection == 7)
    {
        printf("Definicion de Keyword: (7)clear\n");
        printf("Borra la pantalla de la consola. Se encuentra en el archivo de encabezado de la biblioteca estándar <stdlib.h>.\n");
    }
    else if (selection == 8)
    {
        printf("Definicion de Keyword: (8)stdlib.h\n");
        printf("Es el archivo de cabecera de la biblioteca estándar de propósito general del lenguaje de programación C. Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras.\n");
    }
    else if (selection == 9)
    {
        printf("Definicion de Keyword: (9)switch\n");
        printf("Hace que el control se transfiera a una instrucción labeled-statement en el cuerpo de la instrucción, en función del valor de expression.\n");
    }
    else if (selection == 10)
    {
        printf("Definicion de Keyword: (10)case\n");
        printf("Evalúa cada cláusula WHEN sucesiva y muestra el primer resultado en el que la condición sea verdadera.\n");
    }
    else if (selection > 10)
    {
        printf("Opcion invalida.");
    }

    printf("Desea otra definicion?\n(1)Si.\n(0)No.\n");
    scanf("%i", &selection1);

    while (selection1 != 0)
    {
        system("clear");

        printf("Definiciones sobre Keywords en C\nSeleccione una palabra para su definicion:\n");
        printf("Menu:\n(1)float\n(2)double\n(3)short\n(4)long\n(5)unsigned\n(6)signed\n(7)clear\n(8)stdlib.h\n(9)switch\n(10)case\n");
        scanf("%i", &selection);

        if (selection == 1)
        {
            printf("Definicion de Keyword: (1)float\n");
            printf("Devuelve una representación de coma flotante de un número.\n");
        }
        else if (selection == 2)
        {
            printf("Definicion de Keyword: (2)double\n");
            printf("Proporciona las magnitudes más grandes y pequeñas posibles para un número.\n");
        }
        else if (selection == 3)
        {
            printf("Definicion de Keyword: (3)short\n");
            printf("Se usa para modificar el rango de valores de los tipos de datos 'int' y 'char'.\n");
        }
        else if (selection == 4)
        {
            printf("Definicion de Keyword: (4)long\n");
            printf("Es un modificador de tipo de dato que se puede aplicar a los tipos de datos básicos para aumentar el rango y el tamaño de los valores que sus variables pueden almacenar.\n");
        }
        else if (selection == 5)
        {
            printf("Definicion de Keyword: (5)unsigned\n");
            printf("Le indica a la variable que no va a llevar signo (sin valores negativos).\n");
        }
        else if (selection == 6)
        {
            printf("Definicion de Keyword: (6)signed\n");
            printf("Define que el valor de una variable numérica puede ser positivo o negativo.\n");
        }
        else if (selection == 7)
        {
            printf("Definicion de Keyword: (7)clear\n");
            printf("Borra la pantalla de la consola. Se encuentra en el archivo de encabezado de la biblioteca estándar <stdlib.h>.\n");
        }
        else if (selection == 8)
        {
            printf("Definicion de Keyword: (8)stdlib.h\n");
            printf("Es el archivo de cabecera de la biblioteca estándar de propósito general del lenguaje de programación C. Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras.\n");
        }
        else if (selection == 9)
        {
            printf("Definicion de Keyword: (9)switch\n");
            printf("Hace que el control se transfiera a una instrucción labeled-statement en el cuerpo de la instrucción, en función del valor de expression.\n");
        }
        else if (selection == 10)
        {
            printf("Definicion de Keyword: (10)case\n");
            printf("Evalúa cada cláusula WHEN sucesiva y muestra el primer resultado en el que la condición sea verdadera.\n");
        }
        else if (selection > 10)
        {
            printf("Opcion invalida.");
        }

        printf("Desea otra definicion?\n(1)Si.\n(0)No.\n");
        scanf("%i", &selection1);
    }

    if (selection1 == 0)
    {
        printf("Tenga buen dia!");
    }

    return 0;
}