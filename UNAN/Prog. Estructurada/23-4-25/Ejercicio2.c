// Crear un login que controle si el usuario ha ingresado mal el password si ha errado 3 veces mandar mensaje de bloqueo.
// Ciclo for

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int password, i;
    char user[99];

    system("clear");

    printf("Ingrese el usuario:\n");
    scanf("%s", user);

    for (i = 0; i < 3; i++)
    {
        printf("Ingrese la contrasena:\n");
        scanf("%i", &password);

        if (password == 12345678)
        {
            printf("Contrasena correcta!\n");
            break;
        }
        else
            printf("Contrasena incorrecta, intentelo nuevamente\n");
    }

    if (password != 12345678)
        printf("Demasiados intentos, has sido bloqueado");

    return 0;
}