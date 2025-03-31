// Dada las horas trabajadas de una persona y el valor por hora.
// Calcular su salario e imprimirlo.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float hor, horT, sal;

    system("clear");

    printf("Horas trabajadas:\n");
    scanf("%f", &horT);

    printf("Valor de la hora:\n");
    scanf("%f", &hor);

    sal = horT * hor;

    system("clear");

    printf("El salario del trabajador es: %.2f", sal);

    return 0;
}