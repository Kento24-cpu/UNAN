// 1. Se  necesita  obtener  el  promedio  simple  de  un  estudiante
// a  partir  de  sus  tres notas parciales.

#include <stdio.h>

int main()
{
    int nota, nota1, nota2;
    float prom;

    printf("Coloque las tres notas correspondientes\n");
    scanf("%i %i %i", &nota, &nota1, &nota2);

    prom = (nota + nota1 + nota2) / 3;

    printf("Su promedio de notas es: %.2f", prom);

    return 0;
}