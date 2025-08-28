// Escribir un programa que calcule y visualize la medida aritmetica de un vector de 10 elementos numericos,
// utilizando una variable puntero que apunte a dicho vector.

#include <stdio.h>
#include <stdlib.h>

int main()
{
        int vector[10], i, *ptr, suma;
        float promedio;

        ptr = vector;

        for (i = 0; i < 10; i++)
        {
                printf("Numero %d del vector:\n", i + 1);
                scanf("%d", &vector[i]);
                suma += *(ptr + i);
        }

        promedio = (float)suma / 10;

        printf("El promedio del vector es: %.2f", promedio);

        free(ptr);
        ptr = NULL;

        return 0;
}
