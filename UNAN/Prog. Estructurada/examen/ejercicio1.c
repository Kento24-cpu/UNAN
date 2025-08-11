#include <stdio.h>

int main()
{
        int numeros[7];
        int i, j;
        int temp;

        printf("Por favor, ingrese 7 numeros:\n");
        for (i = 0; i < 7; i++)
        {
                printf("Numero %d: ", i + 1);
                scanf("%d", &numeros[i]);
        }

        for (i = 0; i < 6; i++)
        {
                for (j = 0; j < 6 - i; j++)
                {
                        if (numeros[j] < numeros[j + 1])
                        {
                                temp = numeros[j];
                                numeros[j] = numeros[j + 1];
                                numeros[j + 1] = temp;
                        }
                }
        }

        printf("\nNumeros ordenados (de mayor a menor):\n");
        for (i = 0; i < 7; i++)
        {
                printf("%d ", numeros[i]);
        }
        printf("\n");

        printf("\nNumeros invertidos (el array ordenado, pero recorrido al reves):\n");
        for (i = 6; i >= 0; i--)
        {
                printf("%d ", numeros[i]);
        }
        printf("\n");

        return 0;
}