// Tres en raya.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play(char posicion[3][3]);
void getFirstTable(char posicion[3][3]);
void generateTable(char posicion[3][3]);
void player(char posicion[3][3]);
void computer(char posicion[3][3]);

int main()
{
    char posicion[3][3];

    system("clear");

    play(posicion);

    system("pause");
    return 0;
}

void play(char posicion[3][3])
{
    int contador = 0;

    getFirstTable(posicion);

    do
    {
        system("clear");

        generateTable(posicion);

        if (contador % 2 == 0)
            player(posicion);
        else
            computer(posicion);

        contador++;

    } while (contador <= 9);
}

void getFirstTable(char posicion[3][3])
{
    int filas, columnas;
    char aux = '1';

    for (filas = 0; filas < 3; filas++)
    {
        for (columnas = 0; columnas < 3; columnas++)
        {
            posicion[filas][columnas] = aux++;
        }
    }
}

void player(char posicion[3][3])
{
    char aux;
    int filas, columnas, seleccion;

    do
    {
        do
        {
            printf("Selecciona una posicion: \n");
            fflush(stdin);
            scanf("%c", &aux);
        } while (aux < '1' || aux > '9');

        seleccion = 0;

        switch (aux)
        {
        case '1':
            filas = 0;
            columnas = 0;
            if (posicion[filas][columnas] == 'X' || posicion[filas][columnas] == 'O')
            {
                seleccion = 1;
                printf("Posicion ocupada, selecciona otra posicion.\n\n");
            }
            break;

        case '2':
            filas = 0;
            columnas = 1;
            if (posicion[filas][columnas] == 'X' || posicion[filas][columnas] == 'O')
            {
                seleccion = 1;
                printf("Posicion ocupada, selecciona otra posicion.\n\n");
            }
            break;

        case '3':
            filas = 0;
            columnas = 2;
            if (posicion[filas][columnas] == 'X' || posicion[filas][columnas] == 'O')
            {
                seleccion = 1;
                printf("Posicion ocupada, selecciona otra posicion.\n\n");
            }
            break;

        case '4':
            filas = 1;
            columnas = 0;
            if (posicion[filas][columnas] == 'X' || posicion[filas][columnas] == 'O')
            {
                seleccion = 1;
                printf("Posicion ocupada, selecciona otra posicion.\n\n");
            }
            break;

        case '5':
            filas = 1;
            columnas = 1;
            if (posicion[filas][columnas] == 'X' || posicion[filas][columnas] == 'O')
            {
                seleccion = 1;
                printf("Posicion ocupada, selecciona otra posicion.\n\n");
            }
            break;

        case '6':
            filas = 1;
            columnas = 2;
            if (posicion[filas][columnas] == 'X' || posicion[filas][columnas] == 'O')
            {
                seleccion = 1;
                printf("Posicion ocupada, selecciona otra posicion.\n\n");
            }
            break;

        case '7':
            filas = 2;
            columnas = 0;
            if (posicion[filas][columnas] == 'X' || posicion[filas][columnas] == 'O')
            {
                seleccion = 1;
                printf("Posicion ocupada, selecciona otra posicion.\n\n");
            }
            break;

        case '8':
            filas = 2;
            columnas = 1;
            if (posicion[filas][columnas] == 'X' || posicion[filas][columnas] == 'O')
            {
                seleccion = 1;
                printf("Posicion ocupada, selecciona otra posicion.\n\n");
            }
            break;

        case '9':
            filas = 2;
            columnas = 2;
            if (posicion[filas][columnas] == 'X' || posicion[filas][columnas] == 'O')
            {
                seleccion = 1;
                printf("Posicion ocupada, selecciona otra posicion.\n\n");
            }
            break;

        default:
            break;
        }

    } while (seleccion == 1);

    posicion[filas][columnas] = 'X';
}

void computer(char posicion[3][3])
{
    int filas, columnas, seleccion;

    srand(time(NULL));

    do
    {
        filas = rand() % 3;
        columnas = rand() % 3;
        seleccion = 0;

        if (posicion[filas][columnas] == 'X' || posicion[filas][columnas] == 'O')
        {
            seleccion = 1;
        }

    } while (seleccion == 1);

    posicion[filas][columnas] = 'O';
}

void generateTable(char posicion[3][3])
{
    int filas, columnas;

    for (filas = 0; filas < 3; filas++)
    {
        for (columnas = 0; columnas < 3; columnas++)
        {
            if (columnas < 2)
                printf(" %c |", posicion[filas][columnas]);
            else
                printf(" %c ", posicion[filas][columnas]);
        }
        if (filas < 2)
            printf("\n-----------\n");
    }
    printf("\n\n");
}
