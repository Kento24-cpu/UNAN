// Se necesita almacenar información sobre animales
// para gestionar una clínica veterinaria. Para comenzar,
// se supondrá que sólo hay un animal. Del animal es
// necesario conocer:
//      Tipo de animal (perro, gato, etc.)
//      Nombre
//      Edad
//      Nombre del dueño
// Implementa un programa que pida los datos necesarios del
// animal utilizando la siguiente variable de tipo puntero:
//      animal *a;

#include <stdio.h>
#include <stdlib.h>

struct ANIMALES
{
        char tipoAnimal[99];
        char name[99];
        int edad;
        char nameDueno[99];
};

int main()
{
        int animales, i;

        struct ANIMALES *a;

        printf("Animales a ingresar:\n");
        scanf("%d", &animales);

        a = (struct ANIMALES *)malloc(animales * sizeof(struct ANIMALES));

        return 0;
}