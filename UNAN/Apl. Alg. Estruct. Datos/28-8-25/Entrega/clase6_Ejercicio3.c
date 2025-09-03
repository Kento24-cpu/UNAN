// Elaborar programa que genere los 1000 primeros números primos y lo guarde en un fichero de texto
// llamado primo.txt. Cada número se escribirá en una línea.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> // Necesario para la función sqrt()

int main()
{
        FILE *pArchivo;
        int contador_primos = 0;
        int numero = 2; // El primer número primo es 2

        // 1. Abrir el archivo en modo de escritura ("w")
        pArchivo = fopen("primo.txt", "w");

        // 2. Manejo de errores: verificar si el archivo se abrió correctamente
        if (pArchivo == NULL)
        {
                perror("Error al abrir o crear el archivo primo.txt");
                return 1;
        }

        // 3. Generar los 1000 primeros números primos
        while (contador_primos < 1000)
        {
                bool es_primo = true;

                // Comprobar si 'numero' es primo
                // Se itera hasta la raíz cuadrada de 'numero' para optimizar
                for (int i = 2; i <= sqrt(numero); i++)
                {
                        if (numero % i == 0)
                        {
                                es_primo = false;
                                break; // No es primo, se puede salir del bucle
                        }
                }

                // 4. Si el número es primo, escribirlo en el archivo
                if (es_primo)
                {
                        fprintf(pArchivo, "%d\t", numero);
                        contador_primos++;
                }

                numero++;
        }

        // 5. Cerrar el archivo
        fclose(pArchivo);

        printf("Los 1000 primeros numeros primos han sido guardados en primo.txt.\n");

        return 0; // Se retorna 0 si todo sale bien
}
