// Hacer un programa en C que llene un array de 10 enteros con números aleatorios del 0 al 99
// luego de eso los muestre en pantalla y diga cuál es el elemento mayor y cuántas veces se repite.

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

        conteo = ContarValorMayor(a, TAM, max);

        printf("El elemento mayor es: %d\n", max);
        printf("El elemento mayor se repite: %d veces\n", conteo);
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
        printf("Arreglo: ");
}

int encontrarMayor(int arreglo[], int tam)
{
        int max = arreglo[0];
}

int contarValorMayor(int arreglo[], int tam, int valor)
{
        int contar = 0;
}
