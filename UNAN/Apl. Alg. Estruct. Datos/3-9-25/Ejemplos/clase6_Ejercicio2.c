#include <stdio.h>

int BusquedaBinaria(int a[], int clave, int inf, int sup)
{
        int centro;

        if (inf > sup)
                return -1;

        else
        {
                centro = (inf + sup) / 2;

                if (a[centro] == clave)
                        return centro;
                else if (a[centro] < clave)
                        return BusquedaBinaria(a, clave, centro + 1, sup);
                else
                        return BusquedaBinaria(a, clave, inf, centro - 1);
        }
}

int main()
{
        int array[] = {2, 4, 5, 7, 8, 9, 10};
        int n = (sizeof(array) / sizeof(int));
        int pos, valor = 8;

        pos = BusquedaBinaria(array, valor, 0, n - 1);
        if (pos == -1)
                printf("\nEl valor %d, no se encontro", valor);
        else
                printf("\nEl valor %d, esta en la posicion %d", valor, pos);

        putchar('\n');
        return 0;
}