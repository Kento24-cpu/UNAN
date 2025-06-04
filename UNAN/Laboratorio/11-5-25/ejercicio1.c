// Un jefe de casilla desea determinar cuántas personas de cada una de las secciones que componen
// su zona asisten el día de la votaciones. Las secciones son: norte, sur y centro también desea
// determinar cuál es la sección con mayor número de votantes

#include <stdio.h>
#include <ctype.h>

int main()
{
    int votosNorte = 0;
    int votosSur = 0;
    int votosCentro = 0;
    int opcionSeccion;
    char continuarInput;

    printf("Sistema de Conteo de Votantes por Seccion\n");
    printf("-----------------------------------------\n");

    do
    {

        printf("\nIngrese la seccion del votante:\n");
        printf("1. Norte\n");
        printf("2. Sur\n");
        printf("3. Centro\n");
        printf("Seleccione una opcion (1-3): ");

        int scanf_result = scanf("%d", &opcionSeccion);

        while (getchar() != '\n')
            ;

        if (scanf_result == 1)
        {
            switch (opcionSeccion)
            {
            case 1:
                votosNorte++;
                printf("Voto registrado para la seccion Norte.\n");
                break;
            case 2:
                votosSur++;
                printf("Voto registrado para la seccion Sur.\n");
                break;
            case 3:
                votosCentro++;
                printf("Voto registrado para la seccion Centro.\n");
                break;
            default:
                printf("Opcion invalida. Por favor, ingrese 1, 2 o 3.\n");

                break;
            }
        }
        else
        {
            printf("Entrada invalida. Por favor, ingrese un numero (1-3) para la seccion.\n");
        }

        do
        {
            printf("¿Desea ingresar otro votante? (s/n): ");
            scanf(" %c", &continuarInput);

            while (getchar() != '\n')
                ;

            continuarInput = toupper(continuarInput);

            if (continuarInput != 'S' && continuarInput != 'N')
            {
                printf("Respuesta invalida. Por favor, ingrese 's' para si o 'n' para no.\n");
            }
        } while (continuarInput != 'S' && continuarInput != 'N');

    } while (continuarInput == 'S');

    printf("\n--- Resultados Finales del Conteo de Votantes ---\n");
    printf("Seccion Norte: %d votantes\n", votosNorte);
    printf("Seccion Sur: %d votantes\n", votosSur);
    printf("Seccion Centro: %d votantes\n", votosCentro);

    if (votosNorte == 0 && votosSur == 0 && votosCentro == 0)
    {
        printf("\nNo se registraron votantes en ninguna seccion.\n");
    }
    else
    {
        int maxVotos = votosNorte;

        if (votosSur > maxVotos)
        {
            maxVotos = votosSur;
        }
        if (votosCentro > maxVotos)
        {
            maxVotos = votosCentro;
        }

        printf("\nLa seccion o secciones con mayor numero de votantes (%d) es/son:\n", maxVotos);

        if (votosNorte == maxVotos)
        {
            printf("- Norte\n");
        }
        if (votosSur == maxVotos)
        {
            printf("- Sur\n");
        }
        if (votosCentro == maxVotos)
        {
            printf("- Centro\n");
        }
    }

    printf("\nFin del programa.\n");

    return 0;
}