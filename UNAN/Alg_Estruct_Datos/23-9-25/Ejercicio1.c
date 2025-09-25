#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int contar_apariciones(FILE *archivo, const char *palabra);
void convertir_a_minusculas(char *cadena);

int main()
{
        char nombre_archivo[MAX_SIZE];
        char palabra_buscada[MAX_SIZE];
        FILE *archivo;
        int contador;

        system("clear");

        printf("Introduce el nombre del archivo de texto (ej: archivo.txt): ");
        scanf("%s", nombre_archivo);

        printf("Introduce la palabra que quieres buscar: ");
        scanf("%s", palabra_buscada);

        archivo = fopen(nombre_archivo, "r");
        if (archivo == NULL)
        {
                printf("Error: No se pudo abrir el archivo %s.\n", nombre_archivo);
                return 1;
        }

        convertir_a_minusculas(palabra_buscada);

        contador = contar_apariciones(archivo, palabra_buscada);

        fclose(archivo);

        system("clear");

        printf("\nLa palabra '%s' aparece %d veces en el archivo %s.\n", palabra_buscada, contador, nombre_archivo);

        return 0;
}

int contar_apariciones(FILE *archivo, const char *palabra)
{
        char palabra_leida[MAX_SIZE];
        int contador = 0;

        while (fscanf(archivo, "%s", palabra_leida) != EOF)
        {

                convertir_a_minusculas(palabra_leida);

                if (strcmp(palabra_leida, palabra) == 0)
                {
                        contador++;
                }
        }

        return contador;
}

void convertir_a_minusculas(char *cadena)
{
        for (int i = 0; cadena[i]; i++)
        {
                cadena[i] = tolower((unsigned char)cadena[i]);
        }
}