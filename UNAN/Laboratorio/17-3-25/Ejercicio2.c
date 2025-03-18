/*
2. Leer dos números y encontrar:
    a. La suma del doble del primero más el cuadrado del segundo.
    b. El promedio de sus cubos.
*/

#include <stdio.h>

int main()
{
    int num, num1, sum;
    float prom;

    printf("Dame dos numeros:\n");
    scanf("%i %i", &num, &num1);

    sum = (num + num) + (num1 * num1);
    prom = ((num * num * num) + (num1 * num1 * num1)) / 2;

    printf("La suma del doble del primero mas el cuadrado del segundo es: %i\nEl promedio de sus cubos es: %.2f", sum, prom);

    return 0;
}
