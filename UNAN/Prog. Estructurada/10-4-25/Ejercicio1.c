#include <stdio.h>
#include <stdlib.h>

int opcmenu;

void getMenu()
{
    int num, num1, rangomin, rangomax;
    char sexo;

    system("clear");

    printf("Seleccione uno de los programas:\n");
    printf("(1)Verficacion de numeros positvos o negativos.\n(2)Verificacion de numeros par e impar + verificacion de rango.\n(3)Verificacion de sexo.\n(4)Salir.\n");
    scanf("%d", &opcmenu);

    switch (opcmenu)
    {
    // Programa 1. Verficacion de numeros positvos o negativos.
    case 1:
        system("clear");

        printf("Escriba dos numeros:\n");
        scanf("%d %d", &num, &num1);

        if (num > 0 && num1 > 0)
        {
            printf("Los numeros son positivos.\n");
        }
        else
        {
            printf("Los numeros son negativos.\n");
        }

        if (num < 0 || num1 < 0)
        {
            printf("Al menos un numero es positivo.\n");
        }

        system("pause");
        break;

    // Programa 2. Verificacion de numeros par e impar + verificacion de rango.
    case 2:
        system("clear");

        printf("Escriba un numero:\n");
        scanf("%d", &num);
        printf("Escriba un rango minimo y maximo para los numeros:\n");
        scanf("%d %d", &rangomin, &rangomax);

        if (num % 2 == 0)
        {
            printf("El numero es par.\n");
        }
        else
        {
            printf("El numero es impar.\n");
        }

        if (num >= rangomin && num <= rangomax)
        {
            printf("El numero esta dentro del rango seleccionado.\n");
        }
        else
        {
            printf("El numero esta fuera de rango.\n");
        }

        system("pause");
        break;

    // Programa 3. Verificacion de sexo.
    case 3:
        system("clear");

        printf("Escriba la letra de su sexo: (M - F)\n");
        scanf("%s", &sexo);

        if (sexo == 'm' || sexo == 'f')
        {
            printf("Usted obtiene un bono.\n");
        }
        else
        {
            printf("Usted no obtiene bono.\n");
        }

        system("pause");
        break;

    case 4:
        printf("Gracias, nos vemos luego.\n");
        break;

    default:
        printf("Opcion invalida, seleccione una opcion que este disponible.\n");

        system("pause");
        break;
    }
}

int main()
{
    while (opcmenu != 4)
    {
        getMenu();
    }

    return 0;
}