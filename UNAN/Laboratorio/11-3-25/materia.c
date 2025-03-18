#include <stdio.h>
#include <stdlib.h>

int main()
{
    float notF, promCalif;
    int not, not1, not2, exm, trabjof;

    system("clear");

    printf("Notas de los tres parciales: (0 - 10)\n");
    scanf("%i %i %i", &not, &not1, &not2);
    printf("Nota del examen: (0 - 10)\n");
    scanf("%i", &exm);
    printf("Nota del trabajo final: (0 - 10)\n");
    scanf("%i", &trabjof);

    promCalif = ((not+not1 + not2) / 3);

    notF = (promCalif * 0.55) + (exm * 0.3) + (trabjof * 0.15);

    system("clear");

    printf("Su nota final es de: %.2f", notF);
}