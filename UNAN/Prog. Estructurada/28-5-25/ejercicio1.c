#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[2][3], filas, columnas;

    for (filas = 0; filas < 2; filas++)
    {
        for (columnas = 0; columnas < 3; columnas++)
        {
            printf("Ingrese los numeros [2][3]:\n");
            scanf("%d", &matriz[filas][columnas]);
        }
    }

    for (filas = 0; filas < 2; filas++)
    {
        for (columnas = 0; columnas < 3; columnas++)
        {
            printf("[%d\t]", matriz[filas][columnas]);
        }
        printf("\n");
    }

    return 0;
}