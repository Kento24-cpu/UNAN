#include <stdio.h>

int num, num1, suma, resta, multi;
float div;

int main()
{
    printf("Aritmetica\nIngrese dos numeros:\n");
    scanf("%i %i", &num, &num1);

    suma = num + num1;
    resta = num - num1;
    multi = num * num1;
    div = num / num1;

    printf("La suma de los numeros %i y %i es: %i\n", num, num1, suma);
    printf("La resta de los numeros %i y %i es: %i\n", num, num1, resta);
    printf("La multiplicacion de los numeros %i y %i es: %i\n", num, num1, multi);
    printf("La division de los numeros %i y %i es: %.2f\n", num, num1, div);

    return 0;
}