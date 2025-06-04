// Leer los 250000 votos otorgados a los 3 candidatos a gobernador e imprimir el numero del
// candidato ganador y su cantidad de votos.
// do while.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int voto;
    int candidato1 = 0;
    int candidato2 = 0;
    int candidato3 = 0;
    int votos_emitidos = 0;
    const int TOTAL_VOTOS = 250000;

    system("clear");

    srand(time(NULL));

    printf("Procesando %d votos...\n", TOTAL_VOTOS);

    do
    {
        voto = (rand() % 3) + 1;

        switch (voto)
        {
        case 1:
            candidato1++;
            break;
        case 2:
            candidato2++;
            break;
        case 3:
            candidato3++;
            break;
        default:
            printf("Voto invalido: %d\n", voto);
            break;
        }
        votos_emitidos++;
    } while (votos_emitidos < TOTAL_VOTOS);

    printf("\nResultados de la votacion:\n");
    printf("Candidato 1: %d votos\n", candidato1);
    printf("Candidato 2: %d votos\n", candidato2);
    printf("Candidato 3: %d votos\n", candidato3);

    int ganador_numero;
    int ganador_votos;

    if (candidato1 >= candidato2 && candidato1 >= candidato3)
    {
        ganador_numero = 1;
        ganador_votos = candidato1;
    }
    else if (candidato2 >= candidato1 && candidato2 >= candidato3)
    {
        ganador_numero = 2;
        ganador_votos = candidato2;
    }
    else
    {
        ganador_numero = 3;
        ganador_votos = candidato3;
    }

    printf("\nEl candidato ganador es el numero %d con %d votos.\n", ganador_numero, ganador_votos);

    return 0;
}