#include <stdio.h>

char name[20];

int main()
{
    printf("Dame tu nombre:\n");
    scanf("%s", &name);
    printf("Hola %s :D", name);

    return 0;
}
