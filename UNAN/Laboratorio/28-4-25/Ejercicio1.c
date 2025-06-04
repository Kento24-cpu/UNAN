#include <stdio.h>

int count = 1;

void printPene(void)
{
    printf("%i Pene\n", count);
    count++;
}

int main()
{
    while (count != 0)
        printPene();
}