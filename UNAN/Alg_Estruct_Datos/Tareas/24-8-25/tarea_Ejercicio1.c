#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

void mostrarArreglo(int *ptr, int n);                // Muestra todos los elementos del arreglo
float calcularPromedio(int *ptr, int n);             // Calcula y retorna el promedio
int encontrarMaximo(int *ptr, int n, int *posicion); // Encuentra el máximo y su posición
int copiarPares(int *origen, int n, int *destino);   // Copia números pares a otro arreglo

int main()
{
        // Declaracion de variables.
        int arreglo[MAX_SIZE], arregloPares[MAX_SIZE], n, posicionMaximo, cantidadPares, valorMaximo;
        float promedio;

        system("clear"); // Limpiar consola.

        // Solicitar cantidad de elementos
        printf("Ingrese la cantidad de elementos (máximo %d): ", MAX_SIZE);
        scanf("%d", &n);

        // Validar entrada
        if (n <= 0 || n > MAX_SIZE)
        {
                printf("Cantidad inválida. Debe ser entre 1 y %d\n", MAX_SIZE);
                return 1;
        }

        // TODO: Llenar el arreglo usando punteros
        printf("Ingrese %d números enteros:\n", n);

        // Bucle para llenar el arreglo.
        for (int i = 0; i < n; i++)
        {
                scanf("%d", arreglo + i);
        }

        // TODO: Llamar a las funciones implementadas

        system("clear"); // Limpiar consola.

        // 1. Mostrar arreglo original
        printf("\nArreglo original:\n");
        mostrarArreglo(arreglo, n);

        // 2. Calcular y mostrar promedio
        promedio = calcularPromedio(arreglo, n);
        printf("\nPromedio: %.2f\n", promedio);

        // 3. Encontrar y mostrar máximo
        valorMaximo = encontrarMaximo(arreglo, n, &posicionMaximo);
        printf("\nValor máximo: %d en la posición: %d\n", valorMaximo, posicionMaximo);

        // 4. Copiar pares y mostrarlos
        cantidadPares = copiarPares(arreglo, n, arregloPares);
        printf("\nNúmeros pares encontrados: %d\n", cantidadPares);
        if (cantidadPares > 0)
        {
                printf("Arreglo de pares:\n");
                mostrarArreglo(arregloPares, cantidadPares);
        }
        else
        {
                printf("No se encontraron números pares.\n");
        }

        return 0;
}

// FUNCIÓN 1: Mostrar arreglo usando punteros
// TODO: Implementar esta función
void mostrarArreglo(int *ptr, int n)
{
        // Bucle para mostrar los elementos del arreglo.
        for (int i = 0; i < n; i++)
        {
                printf("%d ", *(ptr + i));
        }
        printf("\n"); // Salto de linea despues de los elementos.
}

// FUNCIÓN 2: Calcular promedio usando punteros
// TODO: Implementar esta función
float calcularPromedio(int *ptr, int n)
{
        long int suma = 0; // Para evitar desbordamiento en sumas grandes.

        // Bucle para recorrer el arreglo y sumar cada elemento.
        for (int i = 0; i < n; i++)
        {
                suma += *(ptr + i);
        }

        return (float)suma / n; // Conversion de int a float para retornar el promedio.
}

// FUNCIÓN 3: Encontrar máximo y su posición usando punteros
// TODO: Implementar esta función
int encontrarMaximo(int *ptr, int n, int *posicion)
{
        // Indicacion por si no se encuentra valor.
        if (n <= 0)
        {
                *posicion = -1;
                return -1;
        }

        int valorMaximo = *ptr; // Ubicacion del valor mas alto.
        *posicion = 0;          // Ubicacion de memoria donde se guardara el valor mas alto.

        // Bucle que recorre el array y actualiza el valor maximo en cada iteracion.
        for (int i = 1; i < n; i++)
        {
                if (*(ptr + i) > valorMaximo)
                {
                        valorMaximo = *(ptr + i);
                        *posicion = i;
                }
        }

        return valorMaximo; // Retorna el valor mas alto y su posicion.
}

// FUNCIÓN 4: Copiar números pares a otro arreglo usando punteros
// TODO: Implementar esta función
int copiarPares(int *origen, int n, int *destino)
{
        int cantidadPares = 0; // Nuevo arreglo con numeros pares.

        // Bucle que recorre el array de origen.
        for (int i = 0; i < n; i++)
        {
                // Si los elementos son divisibles entre 2 se guardara en el arreglo.
                if (*(origen + i) % 2 == 0)
                {
                        *(destino + cantidadPares) = *(origen + i);
                        cantidadPares++;
                }
        }
        return cantidadPares; // Retorna los elementos pares del array nuevo.
}
