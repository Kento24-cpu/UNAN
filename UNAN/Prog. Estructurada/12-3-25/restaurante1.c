#include <stdio.h>

// Variables
int res, res1, res2;
char plato[99], plato1[99], plato2[99];
float precio, precio1, precio2, total;

int main()
{
    printf("Hola!\nBienvenidos a nuestro restaurante!\nDesea agregar platos a nuestro menu o escoger algo?\n(1)Agregar.\n(0)Escoger.\n");
    scanf("%i", &res);

    if (res == 1)
    {
        printf("Agregar plato\nEscriba el nombre y precio del plato 1:\n");
        scanf("%s %i", &plato, &precio);
        printf("Agregar plato\nEscriba el nombre y precio del plato 2:\n");
        scanf("%s %i", &plato1, &precio1);
        printf("Agregar plato\nEscriba el nombre y precio del plato 3:\n");
        scanf("%s %i", &plato2, &precio2);
    }
    else
    {
        printf("Perfecto!\nAqui tiene nuestro menu con todos los platillos a disposicion.\npuede seleccionar la opcion que mas le guste.\n");
        printf("(1)%s\n(2)%s\n(3)%s\n", plato, plato1, plato2);
        scanf("%i", &res1);

        switch (res1)
        {
        case 1:
            printf("El precio de dicho plato es: %.2f\n", precio);
            printf("Desea comprarlo?\n(1)Si\n(0)No\n");
            scanf("%i", &res2);

            if (res2 == 1)
            {
                printf("Perfecto!\nSu orden es:\n (1)%s con precio de: %.2f\n", plato, precio);
                printf("Su orden esta siendo preparada, en breve estara lista en su mesa\nMuchas gracias por su compra!");
            }

            break;

        case 2:
            printf("El precio de dicho plato es: %.2f\n", precio1);
            printf("Desea comprarlo?\n(1)Si\n(0)No\n");
            scanf("%i", &res2);

            if (res2 == 1)
            {
                printf("Perfecto!\nSu orden es:\n (2)%s con precio de: %.2f\n", plato1, precio1);
                printf("Su orden esta siendo preparada, en breve estara lista en su mesa\nMuchas gracias por su compra!");
            }

            break;

        case 3:
            printf("El precio de dicho plato es: %.2f\n", precio2);
            printf("Desea comprarlo?\n(1)Si\n(0)No\n");
            scanf("%i", &res2);

            if (res2 == 1)
            {
                printf("Perfecto!\nSu orden es:\n (3)%s con precio de: %.2f\n", plato2, precio2);
                printf("Su orden esta siendo preparada, en breve estara lista en su mesa\nMuchas gracias por su compra!");
            }

            break;

        default:
            break;
        }
    }

    return 0;
}
