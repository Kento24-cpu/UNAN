#include <stdio.h>
#include <stdlib.h>

void getCombinations(int dado1, int dado2)
{
    for (dado1 = 1; dado1 <= 6; dado1++)
    {
        for (dado2 = 1; dado2 <= 6; dado2++)
        {
            printf("[%d, %d]", dado1, dado2);
        }
        printf("\n");
    }
}

int main()
{
    system("clear");

    printf("Todas las generaciones posibles:\n");

    getCombinations(1, 1);

    return 0;
}