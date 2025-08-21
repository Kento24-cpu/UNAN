// Escribe un programa en C que solicite al usuario cuántos números desea ingresar, reserve memoria dinámicamente
// para almacenarlos, permita al usuario ingresar los valores y luego calcule y muestre el promedio de esos números.

#include <stdio.h>
#include <stdlib.h>

int main()
{
        int numeros, i, *pNumeros, suma = 0;
        float promedio;

        system("clear");

        printf("Cantidad de numeros a ingresar:\n");
        scanf("%d", &numeros);

        pNumeros = (int *)malloc(numeros * sizeof(int));

        if (pNumeros == NULL)
        {
                printf("Error al asignar memoria.");
                return 1;
        }

        for (i = 0; i < numeros; i++)
        {
                printf("Escriba el numero %d del array:\n", i + 1);
                scanf("%d", &pNumeros[i]);
        }

        system("clear");

        for (i = 0; i < numeros; i++)
        {
                suma = suma + pNumeros[i];

                printf("Numero %d: %d\n", i + 1, pNumeros[i]);
        }

        promedio = suma / numeros;

        printf("La suma de los numeros es: %d\n", suma);
        printf("El promedio de los numeros es: %.2f", promedio);

        free(pNumeros);
        pNumeros = NULL;

        return 0;
}