#include <stdio.h>

// variables
int codCliente, res;

int main()
{
    printf("Estimado usario\nle queremos hacer constar que su saldo esta a punto de vencer,\nfavor pagar usando su codigo de usuario.\n\a");
    printf("Escriba su codigo de usuario:\n");
    scanf("%i", &codCliente);
    printf("Su codigo: %i es correcto?\n", codCliente);
    printf("(1) Si\n(0) No\n");
    scanf("%i", &res);

    if (res == 1)
    {
        printf("Perfecto!\nsu codigo ha sido verificado con exito\nBienvenido al sistema Bancario!");
    }
    else
    {
        printf("Lo siento, su codigo es incorrecto.\a");
    }
}