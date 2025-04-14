// Bebidas

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opc;

    printf("Bebidas a escoger:\n");
    printf("(1) Coca Cola - C$20\n");
    printf("(2) Agua - C$20\n");
    printf("(3) Hi-C - C$15\n");
    printf("(4) Del Valle - C$20\n");
    printf("(5) Gatorade - C$40\n");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        printf("Su bebida es Coca Cola y vale 20 yukas");
        break;
    case 2:
        printf("Su bebida es Agua y vale 20 yukas");
        break;
    case 3:
        printf("Su bebida es Hi-C y vale 15 yukas");
        break;
    case 4:
        printf("Su bebida es Del Valle y vale 20 yukas");
        break;
    case 5:
        printf("Su bebida es Gatorade y vale 40 yukas");
        break;

    default:
        printf("Opcion invalida.");
        break;
    }

    return 0;
}