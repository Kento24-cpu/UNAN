// Ejercicio 2.
// Escribir un programa que lea 10 números por teclado. Luego lea dos más e indique si éstos están entre los
// anteriores.

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int numeros[10];
    int i;
    int num1, num2;
    bool encontrado1 = false;
    bool encontrado2 = false;

    printf("Ingrese 10 numeros enteros:\n");
    for (i = 0; i < 10; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\nIngrese el primer numero a verificar: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero a verificar: ");
    scanf("%d", &num2);

    for (i = 0; i < 10; i++)
    {
        if (numeros[i] == num1)
            encontrado1 = true;
        if (numeros[i] == num2)
            encontrado2 = true;
    }

    printf("\n--- Resultados de la verificacion ---\n");

    if (encontrado1)
        printf("El numero %d SI esta entre los numeros anteriores.\n", num1);
    else
        printf("El numero %d NO esta entre los numeros anteriores.\n", num1);

    if (encontrado2)
        printf("El numero %d SI esta entre los numeros anteriores.\n", num2);
    else
        printf("El numero %d NO esta entre los numeros anteriores.\n", num2);

    return 0;
}
