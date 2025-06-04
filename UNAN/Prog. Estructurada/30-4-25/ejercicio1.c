// Hacer una funcion que evalue a medida que se vende un boleto cuantas sillas estan disponibles, mandar un aviso cada 10 sillas menos
// (empezando desde las 50 sillas), cuando quedan 5 sillas, avisar una a una.
// while (bucle principal).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sillasTotales, sillasDisponibles, boletosTotales = 0, boletosVendidos;

    system("clear");

    printf("Ingrese el numero de sillas disponibles:\n");
    scanf("%i", &sillasTotales);

    sillasDisponibles = sillasTotales;

    system("clear");

    printf("Sillas disponibles: %i\n", sillasDisponibles);

    while (sillasDisponibles != 0)
    {
        printf("Cantidad de boletos a vender:\n");
        scanf("%i", &boletosVendidos);

        if (boletosVendidos > sillasDisponibles)
        {
            printf("Valor invalido, solo hay %i disponibles\n", sillasDisponibles);
            system("pause");
        }

        sillasDisponibles -= boletosVendidos;
        boletosTotales += boletosVendidos;

        if (sillasDisponibles <= 50 && sillasDisponibles % 10 == 0)
            printf("Quedan %i sillas disponibles\n", sillasDisponibles);
        else if (sillasDisponibles <= 5)
            printf("Quedan %i sillas disponibles\n", sillasDisponibles);
    }

    printf("Ya no hay sillas disponibles.\n");
    printf("Total de boletos vendidos: %i", boletosTotales);

    return 0;
}
