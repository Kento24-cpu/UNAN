#include <stdio.h>
#include <stdlib.h>

int main()
{
    int selection, selection1;

    system("clear");

    printf("Definiciones sobre Keywords en C\nSeleccione una palabra para su definicion:\n");
    printf("Menu:\n(1)float\n(2)double\n(3)short\n(4)long\n(5)unsigned\n(6)signed\n");
    scanf("%i", &selection);

    switch (selection)
    {
    case 1:
        printf("Definicion de Keyword: (1)float\n");
        printf("Devuelve una representación de coma flotante de un número.\n");
        break;

    case 2:
        printf("Definicion de Keyword: (2)double\n");
        printf("Proporciona las magnitudes más grandes y pequeñas posibles para un número.\n");
        break;

    case 3:
        printf("Definicion de Keyword: (3)short\n");
        printf("Se usa para modificar el rango de valores de los tipos de datos 'int' y 'char'.\n");
        break;

    case 4:
        printf("Definicion de Keyword: (4)long\n");
        printf("Es un modificador de tipo de dato que se puede aplicar a los tipos de datos básicos para aumentar el rango y el tamaño de los valores que sus variables pueden almacenar.\n");
        break;

    case 5:
        printf("Definicion de Keyword: (5)unsigned\n");
        printf("Le indica a la variable que no va a llevar signo (sin valores negativos).\n");
        break;

    case 6:
        printf("Definicion de Keyword: (6)signed\n");
        printf("Define que el valor de una variable numérica puede ser positivo o negativo.\n");
        break;

    default:
        printf("Opcion incorrecta");
        break;
    }

    printf("Desea otra definicion?\n(1)Si.\n(0)No.\n");
    scanf("%i", &selection1);

    while (selection1 != 0)
    {
        system("clear");

        printf("Definiciones sobre Keywords en C\nSeleccione una palabra para su definicion:\n");
        printf("Menu:\n(1)float\n(2)double\n(3)short\n(4)long\n(5)unsigned\n(6)signed\n");
        scanf("%i", &selection);

        switch (selection)
        {
        case 1:
            printf("Definicion de Keyword: (1)float\n");
            printf("Devuelve una representación de coma flotante de un número.\n");
            break;

        case 2:
            printf("Definicion de Keyword: (2)double\n");
            printf("Proporciona las magnitudes más grandes y pequeñas posibles para un número.\n");
            break;

        case 3:
            printf("Definicion de Keyword: (3)short\n");
            printf("Se usa para modificar el rango de valores de los tipos de datos 'int' y 'char'.\n");
            break;

        case 4:
            printf("Definicion de Keyword: (4)long\n");
            printf("Es un modificador de tipo de dato que se puede aplicar a los tipos de datos básicos para aumentar el rango y el tamaño de los valores que sus variables pueden almacenar.\n");
            break;

        case 5:
            printf("Definicion de Keyword: (5)unsigned\n");
            printf("Le indica a la variable que no va a llevar signo (sin valores negativos).\n");
            break;

        case 6:
            printf("Definicion de Keyword: (6)signed\n");
            printf("Define que el valor de una variable numérica puede ser positivo o negativo.\n");
            break;

        default:
            printf("Opcion incorrecta.\n");
            break;
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