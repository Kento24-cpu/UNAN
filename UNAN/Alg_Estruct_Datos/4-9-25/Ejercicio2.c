#include <stdio.h>
#include <stdlib.h>

int main()
{
        int *ptrNumeros, i, numeros, numeroMaximo;

        printf("Cantidad de numeros a ingresar:\n");
        scanf("%d", &numeros);

        ptrNumeros = (int *)calloc(numeros, sizeof(int));

        if (ptrNumeros == NULL)
        {
                printf("Error al asignar memoria.\n");
                return 1;
        }

        for (i = 0; i < numeros; i++)
        {
                printf("Ingrese el numero %d:\n", i + 1);
                scanf("%d", &ptrNumeros[i]);
        }

        printf("Numeros pares:\n");

        for (i = 0; i < numeros; i++)
        {
                if (ptrNumeros[i] % 2 == 0)
                        printf("%d ", ptrNumeros[i]);
        }

        printf("\n");

        printf("Numeros impares:\n");

        for (i = 0; i < numeros; i++)
        {
                if (ptrNumeros[i] % 2 != 0)
                        printf("%d ", ptrNumeros[i]);
        }

        for (i = 0; i < numeros; i++)
        {
                if (i == 0)
                        numeroMaximo = ptrNumeros[i];
                if (ptrNumeros[i] > numeroMaximo)
                        numeroMaximo = ptrNumeros[i];
        }

        printf("\n");

        printf("Numero mayor ingresado: %d\n", numeroMaximo);

        free(ptrNumeros);
        ptrNumeros = NULL;

        return 0;
}