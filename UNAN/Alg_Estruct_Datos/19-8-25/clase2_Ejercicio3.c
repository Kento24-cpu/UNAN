// Encuentra el error en el siguiente código en C:
// #include <stdio.h>
// main()
// {
//         int i, *p;

//         i = 50;
//         *p = i;

//         printf("El valor de i es %i\n", i);

//         printf("El valor de *p es %i\n", *p);
// }

#include <stdio.h>

int main()
{
        int i, *p;

        i = 50;
        p = &i;

        printf("El valor de i es %i\n", i);
        printf("El valor de *p es %i\n", *p);

        return 0;
}
