#include <stdio.h>

int num, num1, num2;
float med;

int main()
{
    printf("Media de tres numeros\nIngrese tres numeros:\n");
    scanf("%i %i %i", &num, &num1, &num2);

    med = (num + num1 + num2) / 3;

    printf("La media de los numeros %i %i %i es: %f", num, num1, num2, med);
}
