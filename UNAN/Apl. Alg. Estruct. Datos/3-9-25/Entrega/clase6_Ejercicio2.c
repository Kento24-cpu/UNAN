#include <stdio.h>
#include <stdlib.h>

int main()
{
        int cantNumeros, *numeros, i, auxiliar, pasada;

        printf("Cantidad de numeros a ingresar:\n");
        scanf("%d", &cantNumeros);

        numeros = (int *)calloc(cantNumeros, sizeof(int));

        if (numeros == NULL)
        {
                printf("Error al asignar memoria.\n");
                return 1;
        }

        for (i = 0; i < cantNumeros; i++)
        {
                printf("Numero %d:\n", i + 1);
                scanf("%d", &numeros[i]);
        }

        printf("Numeros antes de ordenar:\n");

        for (i = 0; i < cantNumeros; i++)
                printf("%d\n", numeros[i]);

        for (pasada = 1; pasada < cantNumeros; pasada++)
        {
                for (i = 0; i < cantNumeros - 1; i++)
                {
                        if (numeros[i] > numeros[i + 1])
                        {
                                auxiliar = numeros[i];
                                numeros[i] = numeros[i + 1];
                                numeros[i + 1] = auxiliar;
                        }
                }
        }

        printf("Numeros despues de ordenar:\n");

        for (i = 0; i < cantNumeros; i++)
                printf("%d\n", numeros[i]);

        free(numeros);
        numeros = NULL;

        return 0;
}