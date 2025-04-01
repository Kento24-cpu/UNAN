#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, num1;
    float division, division1;

    system("clear");

    printf("Comparacion de numeros pares e impares.\nEscribe dos numeros:\n");
    scanf("%i %i", &num, &num1);

    division = num % 2;
    division1 = num1 % 2;

    system("clear");

    if (division)
    {
        printf("El numero %i es impar\n", num);
    }
    else
    {
        printf("El numero %i es par\n", num);
    }

    if (division1)
    {
        printf("El numero %i es impar\n", num1);
    }
    else
    {
        printf("El numero %i es par\n", num1);
    }

    return 0;
}