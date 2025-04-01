#include <stdio.h>

int main()
{
    // Variables
    float celsius, fahrenheit;

    // Solicitar al usuario la temperatura en Celsius
    printf("Ingrese la temperatura en grados Celsius:\n");
    scanf("%f", &celsius);

    // Convertir a Fahrenheit
    fahrenheit = ((celsius * 9 / 5) + 32);

    // Mostrar el resultado
    printf("La conversion de grados Celsius (%.2f) a Fahrenheit es: %.2f", celsius, fahrenheit);

    return 0;
}
