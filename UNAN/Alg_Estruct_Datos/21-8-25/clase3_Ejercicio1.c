#include <stdio.h>

int main()
{
        int x = 42;
        int *p = &x;

        printf("Valor de x: %d\n", x);
        printf("Direccion de x: %p\n", &x);
        printf("Valor que guarda p: %p\n", p);
        printf("Valor al que apunta p: %d\n", *p);

        return 0;
}