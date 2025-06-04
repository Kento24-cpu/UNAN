#include <stdio.h>
#include <stdlib.h>

int main()
{
    char namesArray[3][99] = {"Juan", "Juan1", "Juan2"};

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", namesArray[i]);
    }

    return 0;
}