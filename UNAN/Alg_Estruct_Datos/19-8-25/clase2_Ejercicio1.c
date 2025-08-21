// Dadas las siguientes definiciones y
// asignaciones, ilustra cómo quedaría la
// memoria después de ejecutarlas.

// int x, *p1, *p2;
// *p1 = NULL;
// *p2 = NULL;
// x = 15;
// p1 = &x;
// p2 = p1;

#include <stdio.h>
#include <stdlib.h>

int main()
{
        int x, *p1, *p2;

        p1 = NULL;
        p2 = NULL;
        x = 15;
        p1 = &x;
        p2 = p1;

        printf("Valor de x = %d\nValor del puntero 1 = %d\nValor del puntero 2 = %d\n", x, *p1, *p2);

        return 0;
}