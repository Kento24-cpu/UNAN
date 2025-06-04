#include <stdio.h>
#include <stdlib.h>

void getTable(void)
{
    for (int i = 0; (i < 9); i++)
    {
        if (i == 2 || i == 5 || i == 8)
            printf("[]\n");
        else
            printf("[]");
    }
}

int main()
{
    getTable();

    return 0;
}