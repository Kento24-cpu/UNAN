// menú de restaurante con 8 platos y opciones para pedir.
// 1. Menú del Restaurante con if...else
#include <stdio.h>

int main()
{
    int opcion;

    // Mostrar el menú
    printf("--- Menu del Restaurante ---\n");
    printf("1. Hamburguesa\n");
    printf("2. Pizza\n");
    printf("3. Pasta\n");
    printf("4. Ensalada\n");
    printf("5. Pollo Asado\n");
    printf("6. Sopa\n");
    printf("7. Sushi\n");
    printf("8. Tacos\n");

    // Pedir al usuario que elija una opción
    printf("Seleccione una opcion (1-8): ");
    scanf("%d", &opcion);

    // Confirmar la opción elegida usando if...else
    printf("Usted ha seleccionado: ");
    if (opcion == 1)
    {
        printf("Hamburguesa\n");
    }
    else if (opcion == 2)
    {
        printf("Pizza\n");
    }
    else if (opcion == 3)
    {
        printf("Pasta\n");
    }
    else if (opcion == 4)
    {
        printf("Ensalada\n");
    }
    else if (opcion == 5)
    {
        printf("Pollo Asado\n");
    }
    else if (opcion == 6)
    {
        printf("Sopa\n");
    }
    else if (opcion == 7)
    {
        printf("Sushi\n");
    }
    else if (opcion == 8)
    {
        printf("Tacos\n");
    }
    else
    {
        printf("Opcion no valida\n");
    }

    return 0;
}
