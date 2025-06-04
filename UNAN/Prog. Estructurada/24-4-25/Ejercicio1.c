#include <stdio.h>
#include <stdlib.h>

int main()
{
    int salarios[3], salarioFinal[3], count = 0, elements, antiguedad, i = 0;

    system("clear");

    while (count < 3)
    {
        printf("Ingrese sus salarios:\n");
        scanf("%i", &elements);
        printf("Antiguedad:\n");
        scanf("%i", &antiguedad);

        salarios[count++] = elements;

        system("clear");
    }

    printf("Salarios:\n");

    for (i = 0; i < count; i++)
        printf("%i\n", salarios[i]);

    if (antiguedad >= 1)
    {
        for (i = 0; i < 3; i++)
        {
            if (salarios[i] < 1000)
            {
                salarioFinal[i] = (salarios[i] * 0.10) + salarios[i];
                printf("Su salario final es de: %i\n", salarioFinal[i]);
            }
            else
            {
                salarioFinal[i] = (salarios[i] * 0.05) + salarios[i];
                printf("Su salario final es de: %i\n", salarioFinal[i]);
            }
        }
    }
    else if (salarios[i] < 1000)
    {
        salarioFinal[i] = (salarios[i] * 0.10) + salarios[i];
        printf("Su salario final es de: %i\n", salarioFinal[i]);
    }
    else if (salarios[i] >= 1000)
    {
        salarioFinal[i] = (salarios[i] * 0.05) + salarios[i];
        printf("Su salario final es de: %i\n", salarioFinal[i]);
    }
    else
        printf("No aplica bono: %i\n", salarios[i]);

    return 0;
}