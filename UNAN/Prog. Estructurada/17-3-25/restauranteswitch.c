// 2. Menú del Restaurante con switch... case
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

    // Confirmar la opción elegida usando switch...case
    printf("Usted ha seleccionado: ");
    switch (opcion)
    {
    case 1:
        printf("Hamburguesa\n");
        break;
    case 2:
        printf("Pizza\n");
        break;
    case 3:
        printf("Pasta\n");
        break;
    case 4:
        printf("Ensalada\n");
        break;
    case 5:
        printf("Pollo Asado\n");
        break;
    case 6:
        printf("Sopa\n");
        break;
    case 7:
        printf("Sushi\n");
        break;
    case 8:
        printf("Tacos\n");
        break;
    default:
        printf("Opcion no valida\n");
    }

    return 0;
}