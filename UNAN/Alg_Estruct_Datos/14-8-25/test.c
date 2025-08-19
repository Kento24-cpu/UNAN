#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void llenarArreglo(int arreglo[], int tam);
void mostrarArreglo(int arreglo[], int tam);
int encontrarMayor(int arreglo[], int tam);
int contarValorMayor(int arreglo[], int tam, int valor);

int main()
{
        int a[TAM];
        int max, conteo;

        srand(time(NULL));

        llenarArreglo(a, TAM);

        mostrarArreglo(a, TAM);

        max = encontrarMayor(a, TAM);

        conteo = contarValorMayor(a, TAM, max);

        printf("El elemento mayor es: %d\n", max);

        if (conteo == 1)
        {
                printf("El elemento mayor se repite: %d vez\n", conteo);
        }
        else
        {
                printf("El elemento mayor se repite: %d veces\n", conteo);
        }

        return 0;
}

void llenarArreglo(int arreglo[], int tam)
{
        for (int i = 0; i < tam; i++)
        {
                arreglo[i] = rand() % 100;
        }
}

void mostrarArreglo(int a[], int tam)
{
        printf("Arreglo:\n");
        for (int i = 0; i < tam; i++)
        {
                printf("%d\n", a[i]);
        }
}

int encontrarMayor(int arreglo[], int tam)
{
        int max = arreglo[0];

        for (int i = 1; i < tam; i++)
        {
                if (arreglo[i] > max)
                        max = arreglo[i];
        }

        return max;
}

int contarValorMayor(int arreglo[], int tam, int valor)
{
        int contar = 0;

        for (int i = 1; i < tam; i++)
        {
                if (arreglo[i] == valor)
                {
                        contar++;
                }
        }

        return contar;
}
