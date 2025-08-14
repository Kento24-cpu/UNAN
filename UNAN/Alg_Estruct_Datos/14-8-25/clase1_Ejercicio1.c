// Cree un programa utilizando funciones que calcule e imprima el total y el promedio de 4 números decimales digitados por el usuario

#include <stdio.h>

void leerNumeros(float *num, float *num1, float *num2, float *num3);
float calcularTotal(float num, float num1, float num2, float num3);
float calcularPromedio(float total, int tam);

int main()
{
        float num, num1, num2, num3;
        float total, promedio;
        int tamano = 4;

        leerNumeros(&num, &num1, &num2, &num3);
        total = calcularTotal(num, num1, num2, num3);
        promedio = calcularPromedio(total, tamano);

        printf("El total es: %.2f\n", total);
        printf("El promedio es: %.2f\n", promedio);
        return 0;
}

void leerNumeros(float *num, float *num1, float *num2, float *num3)
{
        printf("Ingrese 4 numeros:\n");
        scanf("%f %f %f %f", num, num1, num2, num3);
}

float calcularTotal(float num, float num1, float num2, float num3)
{
        return num + num1 + num2 + num3;
}

float calcularPromedio(float total, int tamano)
{
        return total / tamano;
}