/*
4. Elaborar  un  algoritmo  que  permita  ingresar  el  número
de  partidos  ganados, perdidos  y  empatados,  por  algún
equipo  en  el  torneo  apertura,  se  debe  de mostrar  su
puntaje  total,  teniendo  en  cuenta  que  por  cada  partido ganado
obtendrá 3 puntos, empatado 1 punto y perdido 0 puntos.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int parGan, parPer, parEmp, puntPG;
    int puntaje = 0;

    system("clear");

    printf("Ingrese los partidos ganados:\n");
    scanf("%i", &parGan);
    printf("Ingrese los partidos perdidos:\n");
    scanf("%i", &parPer);
    printf("Ingrese los partidos empatados:\n");
    scanf("%i", &parEmp);

    system("clear");

    puntPG = parGan * 3;
    parEmp = parEmp * 1;

    puntaje = (puntPG) + (parEmp);

    printf("Puntaje de partidos:\nGanados --- 3pts\nPerdidos --- 0pts\nEmpatados --- 1pts\n");
    printf("Partidos ganados: %i\nPartidos perdidos: %i\nPartidos empatados: %i\nPuntaje total: %i", parGan, parPer, parEmp, puntaje);

    return 0;
}
