#include <stdio.h>

int main()
{
        int *ptr, i, x[5] = {1, 2, 3, 4, 5};

        ptr = x;

        *ptr = 9;

        for (i = 0; i < 5; i++)
        {
                printf("%d", x[i]);
        }

        return 0;
}