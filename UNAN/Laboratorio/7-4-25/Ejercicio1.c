// Operaciones Aritmeticas

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, num1, opcmenu, sum, res, mult;
    float div;

    if (system("cls"))
    {
        system("clear");
    }

    while (opcmenu != 5)
    {
        printf("Aritmetica.\nSeleccione una opcion:\n(1)Suma.\n(2)Resta.\n(3)Multiplicacion.\n(4)Division.\n(5)Salir.\n");
        scanf("%i", &opcmenu);

        switch (opcmenu)
        {

            if (system("cls"))
            {
                system("clear");
            }

        case 1:
            printf("Escriba dos numeros:\n");
            scanf("%i %i", &num, &num1);
            sum = num + num1;
            printf("La suma de los numeros es: %i\n", sum);

            system("continue");
            break;

        case 2:
            printf("Escriba dos numeros:\n");
            scanf("%i %i", &num, &num1);
            res = num - num1;
            printf("La resta de los numeros es: %i\n", res);
            break;

        case 3:
            printf("Escriba dos numeros:\n");
            scanf("%i %i", &num, &num1);
            mult = num * num1;
            printf("La multiplicacion de los numeros es: %i\n", mult);
            break;

        case 4:
            printf("Escriba dos numeros:\n");
            scanf("%i %i", &num, &num1);
            div = num / num1;
            printf("La division de los numeros es: %.2f\n", div);
            break;

        case 5:
            printf("Tenga buen dia!");
            break;

        default:
            printf("Opcion invalida, escoja una opcion dentro del menu.\n");
            break;
        }
    }

    return 0;
}