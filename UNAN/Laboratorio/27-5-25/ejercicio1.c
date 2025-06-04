// Realizar una funcion que convierta grados centigrados a grados fahrenheit.
// Formula: (f = 9 / 5 * C + 32)

#include <stdio.h>
#include <stdlib.h>

void getFahrenheit()
{
    float celcious, fahrenheit;

    system("clear");

    printf("Ingrese el valor en Celcious:\n");
    scanf("%f", &celcious);

    fahrenheit = (celcious * 9 / 5) + 32;

    printf("Los grados %.2f Celcious en Fahrenheit son: %.2f", celcious, fahrenheit);
}

int main()
{
    getFahrenheit();

    return 0;
}