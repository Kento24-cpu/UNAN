// Encuentra el error en el siguiente código en C:

// #include <stdio.h>
// main()
// {
//         float x = 55.4;
//         int *p;
//         p = &x;
//         printf("El valor correcto es : %f\n ", x);
//         printf("Valor apuntado : %f\n ", *p);
// }

#include <stdio.h>

int main()
{
        float x = 55.4;
        float *p;

        p = &x;

        printf("El valor correcto es : %.2f\n ", x);
        printf("Valor apuntado : %.2f\n ", *p);

        return 0;
}
