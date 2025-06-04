#include <stdio.h>

// Declaracion de la funcion
int sum(int a, int b, int c);

// Definición de la función
int suma(int a, int b, int c)
{
    return a + b - c;
}

int main()
{
    int resultado = suma(5, 3, 100); // Llamada a la función
    printf("La suma es: %d\n", resultado);

    return 0;
}