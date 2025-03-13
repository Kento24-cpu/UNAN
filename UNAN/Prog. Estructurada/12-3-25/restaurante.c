#include <stdio.h>

int main()
{
    int res, res1, res2;

    char plato[99] = "Platillo 1, Carne asada con gallopinto y gaseosa de 500ml.";
    char plato1[99] = "Platillo 2, Pollo con papas en caldillo con arroz y te frio de 500ml.";
    char plato2[99] = "Platillo 3, Queso frito, maduro, huevo y gallopinto con cafe.";

    float precio = 220.00;
    float precio1 = 180.00;
    float precio2 = 100.00;

    printf("Hola!\nBienvenidos a nuestro restaurante!\nDesea entrar a nuestro menu?\n(1)Si.\n(0)No.\n");
    scanf("%i", &res);

    if (res == 1)
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
    else
    {
        printf("Tenga buen dia, gracias por elegirnos!");
    }

    return 0;
}
