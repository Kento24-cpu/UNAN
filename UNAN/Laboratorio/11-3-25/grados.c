#include <stdio.h>

// Variables
float far, cel;

int main()
{
    printf("Convertir grados Farenheit a Celcious\nIngrese los Farenheit:\n");
    scanf("%f", &far);

    cel = (far - 32) * 5 / 9;

    printf("Los grados %.2f de farenheit en Celcious es: %.2f", far, cel);
}
