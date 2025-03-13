#include <stdio.h>

float calif, exm, trabjof, prom;
int not, not1, not2;

int main()
{
    printf("Promedio de clase: Algoritmo\nNotas de los tres parciales:\n");
    scanf("%i %i %i", &not, &not1, &not2);
    printf("Nota del examen:\n");
    scanf("%f", &exm);
    printf("Nota del trabajo final:\n");
    scanf("%f", &trabjof);

    prom = ((not+not1 + not2 + exm + trabjof) / 5);

    printf("Su nota final es de: %f", prom);
}