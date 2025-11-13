#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definicion de la estructura de la lista enlazada
struct datos
{
    char pais[30];
    char capital[30];
    struct datos *siguiente;
};
typedef struct datos paises;

// Prototipos de funciones
paises* nuevo(void);
void error(void);
void anadir (paises** cab, const char pais[], const char capital[]);
paises* buscar_por_pais (paises* cabecera, const char pais[]);
void borrar(paises** cab, const char pais[]);
paises* buscar_por_capital (paises* cabecera, const char capital[]);
void ver(paises*);
int menu (char *opciones[], int numOpciones);
void limpiar_buffer(void);
void leer_cadena(char *destino, int tamano);

// Opciones del menu
char *opciones[] = {
    "Insertar un elemento.",
    "Buscar por pais.",
    "Buscar por capital",
    "Ver todos los datos",
    "Borrar un dato",
    "Salir"
};

void limpiar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void leer_cadena(char *destino, int tamano) {
    if (fgets(destino, tamano, stdin) != NULL) {
        // Buscar y eliminar el salto de linea ('\n')
        destino[strcspn(destino, "\n")] = 0;
    }
}

// Funcion principal
int main()
{
    paises*cabecera=NULL;
    paises*q;
    char pa[30];
    char cap[30];
    char opcion_char;

    // Carga inicial de datos
    printf("Cargando datos iniciales...\n");
    anadir(&cabecera, "Canada", "Ottawa");
    anadir(&cabecera, "Peru", "Lima");
    anadir(&cabecera, "Francia", "Paris");
    anadir(&cabecera, "Alemania", "Bonn");
    anadir(&cabecera, "Nicaragua", "Managua");
    anadir(&cabecera, "Uruguay", "Montevideo");
    anadir(&cabecera, "Israel", "Jerusalen");
    anadir(&cabecera, "Italia", "Roma");
    anadir(&cabecera, "Paraguay", "Asuncion");
    // Se corrige "Ciudad_de_Mexico" para permitir busqueda con espacios si se usa leer_cadena
    anadir(&cabecera, "Mexico", "Ciudad de Mexico");
    anadir(&cabecera, "Argentina", "Buenos Aires");
    printf("Carga completa. Presione ENTER para continuar.\n");
    limpiar_buffer(); // Limpia cualquier '\n' remanente
    getchar();

    while(1)
    {
        // Se usa system("cls") para entornos Windows. En Linux/macOS seria system("clear").
        system("cls");
        opcion_char = menu(opciones, 6);
        system("cls");

        switch(opcion_char)
        {
            case '1':
                printf("--- Insertar un elemento ---\n");
                printf("Introduzca el pais (ej. Costa Rica): ");
                limpiar_buffer(); // Limpia buffer antes de leer cadena
                leer_cadena(pa, sizeof(pa));

                printf("Introduzca la capital (ej. San Jose): ");
                leer_cadena(cap, sizeof(cap));

                anadir(&cabecera, pa, cap);
                printf("\nElemento anadido: %s - %s.\n", pa, cap);
                break;

            case '2':
                printf("--- Buscar por pais ---\n");
                printf("Escriba el nombre del pais: ");
                limpiar_buffer();
                leer_cadena(pa, sizeof(pa));

                q = buscar_por_pais(cabecera, pa);

                if(q)
                    printf("\n\tLa capital de %s es %s\n\n", q->pais, q->capital);
                else
                    printf("\n\tPais '%s' no encontrado.\n", pa);
                break;

            case '3':
                printf("--- Buscar por capital ---\n");
                printf("Escriba el nombre de la capital: ");
                limpiar_buffer();
                leer_cadena(cap, sizeof(cap));

                q = buscar_por_capital(cabecera, cap);

                if(q)
                    printf("\n\t%s es la capital de %s\n\n", q->capital, q->pais);
                else
                    printf("\n\tCapital '%s' no encontrada.\n", cap);
                break;

            case'4':
                printf("--- Informe de Paises y Capitales ---\n");
                ver(cabecera);
                break;

            case'5':
                printf("--- Borrar un dato ---\n");
                printf("Que pais desea borrar: ");
                limpiar_buffer();
                leer_cadena(pa, sizeof(pa));

                borrar(&cabecera, pa);
                break;

            case'6':
                printf("Saliendo del programa. Adios!\n");
                exit(0);

            default:
                // Esto no deberia ocurrir si el menu funciona bien, pero es buena practica
                printf("Opcion invalida. Error en el flujo del programa.\n");
                break;
        }

        printf("\nPresione ENTER para continuar...");
        getchar();
    }
}

paises* nuevo(void)
{
    paises* q = (paises*)malloc(sizeof(paises));
    if (q == NULL)
        error();
    return(q);
}

void error (void)
{
    printf("\n[ERROR]: No hay espacio suficiente en memoria.\n");
    exit(-1);
}

int menu(char *opciones[], int numOpciones)
{
    int i;
    int opcion_char;

    printf("\n_________________ M E N U _________________\n\n");
    for (i = 1; i <= numOpciones; ++i)
        printf("%3d.- %s\n", i, opciones[i-1]);
    printf("___________________________________________\n");

    do
    {
        printf("\nOpcion (1 - %d): ", numOpciones);
        opcion_char = getchar(); // Lee el caracter de opcion
        limpiar_buffer();        // Limpia cualquier caracter adicional o '\n'
    } while (opcion_char < '1' || opcion_char > '6');

    return opcion_char;
}

void anadir(paises** cab, const char pais[], const char capital[])
{
    paises* nuevo_nodo = nuevo();

    // Usar strncpy para evitar desbordamiento de buffer
    strncpy(nuevo_nodo->pais, pais, sizeof(nuevo_nodo->pais) - 1);
    nuevo_nodo->pais[sizeof(nuevo_nodo->pais) - 1] = '\0';

    strncpy(nuevo_nodo->capital, capital, sizeof(nuevo_nodo->capital) - 1);
    nuevo_nodo->capital[sizeof(nuevo_nodo->capital) - 1] = '\0';

    nuevo_nodo->siguiente = *cab;
    *cab = nuevo_nodo; // El nuevo nodo es ahora la cabecera
}

paises* buscar_por_pais(paises* cabecera, const char pais[])
{
    paises* actual = cabecera;
    while (actual != NULL)
    {
        if (strcmp(actual->pais, pais) == 0)
        {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

paises* buscar_por_capital (paises* cabecera, const char capital[])
{
    paises* actual = cabecera;
    while (actual != NULL)
    {
        if (strcmp(actual->capital, capital) == 0)
        {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

void borrar (paises** cab, const char pais[])
{
    paises* actual = *cab;
    paises* anterior = NULL;

    if (actual == NULL)
    {
        printf("\tLa lista esta vacia. No se puede borrar.\n");
        return;
    }

    // Caso 1: Borrar la cabecera
    if (strcmp(actual->pais, pais) == 0)
    {
        *cab = actual->siguiente;
        free(actual);
        printf("\tPais '%s' borrado exitosamente.\n", pais);
        return;
    }

    // Caso 2: Buscar en el resto de la lista
    while (actual != NULL && strcmp(actual->pais, pais) != 0)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
    {
        printf("\tPais '%s' no encontrado en la lista.\n", pais);
        return;
    }

    // Desvincular y borrar el nodo
    anterior->siguiente = actual->siguiente;
    free(actual);
    printf("\tPais '%s' borrado exitosamente.\n", pais);
}

void ver(paises* cabecera)
{
    paises* actual = cabecera;
    int contador = 0;

    if (actual == NULL)
    {
        printf("\n\tLa lista esta vacia.\n");
        return;
    }

    printf("\n%-4s%-30s%s\n", "No.", "Pais", "Capital");
    printf("-------------------------------------------\n");

    while (actual != NULL)
    {
        contador++;
        printf("%-4d%-30s%s\n", contador, actual->pais, actual->capital);
        actual = actual->siguiente;
    }
    printf("-------------------------------------------\n");
    printf("Total de registros: %d\n", contador);
}