// Hacer un programa que almacene 100 numeros float en un array luego que imprima los valores en orden.

#include <stdio.h>
#include <stdlib.h>

int compareFloats(const void *a, const void *b)
{
    float fa = *(const float *)a;
    float fb = *(const float *)b;
    return (fa > fb) - (fa < fb);
}

int main()
{
    float numeros[100];

    for (int i = 0; i < 100; i++)
    {
        numeros[i] = (float)(i * 0.77);
    }

    qsort(numeros, 100, sizeof(float), compareFloats);

    printf("--- Values in Ascending Order ---\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%.2f\n", numeros[i]);
    }

    return 0;
}