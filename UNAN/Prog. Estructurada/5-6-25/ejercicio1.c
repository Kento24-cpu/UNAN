// Una empresa de streamming requere ordenar y clasificar el inventario o catalogo de peliculas.
// Hacer una estructura que gestione las peliculas, debe contener:
//      Nombre
//      Genero
//      Año
//      Director
//      Puntuación
// Luego con el uso de arreglo y ciclos guardar los datos de cada pelicula.
// Posterior crear un menu para que el usuario pueda filtrar por genero, año, director y puntuacion.
// Tambien podra buscar por nombre de pelicula, el programa debe solicitar al admin indique la cantidad de
// peliculas a ingresar.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructuras
struct CATALOGO
{
    char nombre[99];
    char genero[99];
    int year;
    char director[99];
    float puntuacion;
};

// Declaracion de funciones
void insertMovies();
void getMovies();
void getMenu();
void login();

// Variables globales
int cantidadPeliculas, i;

struct CATALOGO *peliculas;

int main()
{
    getMenu();

    return 0;
}

void login()
{
    char userAdmin[10] = "ElpaYaso23";
    int AdminPassword = 1234;

    char userName[10];
    int userPassword;

    int validarUsuario = strcmp(userName, userAdmin);

    system("clear");

    while (userPassword != AdminPassword && validarUsuario != 0)
    {
        printf("Ingrese el usuario del Admin:\n");
        scanf("%s", userName);
        printf("Ingrese la contraseña de Admin:\n");
        scanf("%d", &userPassword);

        if (userPassword != AdminPassword && validarUsuario != 0)
            printf("Error de validacion, intentelo nuevamente.\n");
        else
            insertMovies();
    }
}

void insertMovies()
{
    system("clear");

    printf("Cantidad de peliculas a ingresar:\n");
    scanf("%d", &cantidadPeliculas);

    peliculas = (struct CATALOGO *)malloc(cantidadPeliculas * sizeof(struct CATALOGO));

    if (peliculas == NULL)
    {
        printf("Error al asignar memoria\n");
    }

    for (i = 0; i < cantidadPeliculas; i++)
    {
        printf("Ingreso de peliculas\n--------------------\n");
        printf("Nombre:");
        scanf("%s\n", peliculas[i].nombre);
        printf("Genero:");
        scanf("%s\n", peliculas[i].genero);
        printf("Año:");
        scanf("%d\n", &peliculas[i].year);
        printf("Director:");
        scanf("%s\n", peliculas[i].director);
        printf("Puntuacion:");
        scanf("%f\n", &peliculas[i].puntuacion);
    }
    getMenu();
}

void getMovies()
{
    printf("Catalogo de peliculas\n---------------------\n\n");

    for (i = 0; i < cantidadPeliculas; i++)
    {
        printf("Pelicula %d\n", i + 1);
        printf("Nombre: %s\n", peliculas[i].nombre);
        printf("Genero: %s\n", peliculas[i].genero);
        printf("Año: %d\n", peliculas[i].year);
        printf("Director: %s\n", peliculas[i].director);
        printf("Puntuacion: %.2f", peliculas[i].puntuacion);
    }
}

void getMenu()
{
    int opcion;

    printf("Bienvenidos a la app de Streamming 'Elpa-Yaso', seleccione una opcion del menu:\n(1)Ingresar peliculas.\n(2)Ver catalogo.\n(0)Salir.\n");
    printf("\tNota: Para ingresar peliculas necesita la Admin Password.\n");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        login();
        break;

    case 2:
        getMovies();
        break;

    default:
        printf("Opcion invalida, ingrese una opcion disponible.\n");
        break;
    }

    printf("Gracias por usar 'Elpa-Yaso', pase buen dia\n");
}
