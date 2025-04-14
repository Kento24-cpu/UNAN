// Calcular la utilidad de un trabajador con respecto a su antiguedad sabiendo que:
// 1 año a mas y menos de 2 años  15%
// 2 año a mas y menos de 5 años  20%
// 5 año a mas y menos de 10 años  35%
// 1 año a mas  40%

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int salario, antiguedad, suma;
    float utilidad;

    if (system("cls"))
    {
        system("clear");
    }

    printf("Escriba su salario y su antiguedad:\n");
    scanf("%i %i", &salario, &antiguedad);

    if (antiguedad >= 1 && antiguedad < 2)
    {
        utilidad = salario * 0.15;
        suma = salario + utilidad;
        printf("La utilidad del trabajador con respecto a su antiguedad (%i) es de: %.2f y la suma de la utilidad con su salario es: %i", antiguedad, utilidad, suma);
    }
    else if (antiguedad >= 2 && antiguedad < 5)
    {
        utilidad = salario * 0.2;
        suma = salario + utilidad;
        printf("La utilidad del trabajador con respecto a su antiguedad (%i) es de: %.2f y la suma de la utilidad con su salario es: %i", antiguedad, utilidad, suma);
    }
    else if (antiguedad >= 5 && antiguedad < 10)
    {
        utilidad = salario * 0.35;
        suma = salario + utilidad;
        printf("La utilidad del trabajador con respecto a su antiguedad (%i) es de: %.2f y la suma de la utilidad con su salario es: %i", antiguedad, utilidad, suma);
    }
    else if (antiguedad >= 10)
    {
        utilidad = salario * 0.4;
        suma = salario + utilidad;
        printf("La utilidad del trabajador con respecto a su antiguedad (%i) es de: %.2f y la suma de la utilidad con su salario es: %i", antiguedad, utilidad, suma);
    }
    else
    {
        printf("Fuera de rango.");
    }

    return 0;
}
