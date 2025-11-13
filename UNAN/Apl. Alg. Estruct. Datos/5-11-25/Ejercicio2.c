#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estudiante
{
        int codigo;
        char nombre[50];
        char apellido[50];
        char correo[100];
        float nota;
        struct Estudiante *siguiente;
} Estudiante;

Estudiante *cabeza_e = NULL;
Estudiante *cola_e = NULL;

void limpiarBuffer()
{
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
}

void agregarEstudiante()
{
        Estudiante *nuevo = (Estudiante *)malloc(sizeof(Estudiante));
        if (nuevo == NULL)
        {
                printf("Error de asignacion de memoria.\n");
                return;
        }

        printf("\n--- Agregar Estudiante ---\n");
        printf("Codigo: ");
        scanf("%d", &nuevo->codigo);
        limpiarBuffer();
        printf("Nombre: ");
        fgets(nuevo->nombre, 50, stdin);
        nuevo->nombre[strcspn(nuevo->nombre, "\n")] = 0;
        printf("Apellido: ");
        fgets(nuevo->apellido, 50, stdin);
        nuevo->apellido[strcspn(nuevo->apellido, "\n")] = 0;
        printf("Correo: ");
        fgets(nuevo->correo, 100, stdin);
        nuevo->correo[strcspn(nuevo->correo, "\n")] = 0;
        printf("Nota (0.0 a 5.0): ");
        scanf("%f", &nuevo->nota);
        limpiarBuffer();

        if (cabeza_e == NULL)
        {
                cabeza_e = nuevo;
                cola_e = nuevo;
                nuevo->siguiente = cabeza_e;
                printf("Estudiante agregado. Lista circular inicializada.\n");
                return;
        }

        if (nuevo->nota >= 3.0)
        {
                nuevo->siguiente = cabeza_e;
                cabeza_e = nuevo;
                cola_e->siguiente = cabeza_e;
                printf("Estudiante aprobado insertado al inicio.\n");
        }
        else
        {
                cola_e->siguiente = nuevo;
                cola_e = nuevo;
                cola_e->siguiente = cabeza_e;
                printf("Estudiante reprobado insertado al final.\n");
        }
}

void buscarEstudiante()
{
        if (cabeza_e == NULL)
        {
                printf("La lista de estudiantes esta vacia.\n");
                return;
        }
        int codigoBuscado;
        printf("\n--- Buscar Estudiante ---\n");
        printf("Ingrese codigo a buscar: ");
        scanf("%d", &codigoBuscado);
        limpiarBuffer();

        Estudiante *actual = cabeza_e;
        do
        {
                if (actual->codigo == codigoBuscado)
                {
                        printf("\n--- Estudiante Encontrado ---\n");
                        printf("Codigo: %d\n", actual->codigo);
                        printf("Nombre: %s %s\n", actual->nombre, actual->apellido);
                        printf("Correo: %s\n", actual->correo);
                        printf("Nota: %.2f (%s)\n", actual->nota, (actual->nota >= 3.0 ? "Aprobado" : "Reprobado"));
                        return;
                }
                actual = actual->siguiente;
        } while (actual != cabeza_e);

        printf("Estudiante con codigo %d no encontrado.\n", codigoBuscado);
}

void eliminarEstudiante()
{
        if (cabeza_e == NULL)
        {
                printf("La lista de estudiantes esta vacia. Nada que eliminar.\n");
                return;
        }
        int codigoEliminar;
        printf("\n--- Eliminar Estudiante ---\n");
        printf("Ingrese codigo del estudiante a eliminar: ");
        scanf("%d", &codigoEliminar);
        limpiarBuffer();

        Estudiante *actual = cabeza_e;
        Estudiante *anterior = cola_e;

        do
        {
                if (actual->codigo == codigoEliminar)
                {
                        if (actual == cabeza_e && actual == cola_e)
                        {
                                free(actual);
                                cabeza_e = cola_e = NULL;
                                printf("Ultimo estudiante eliminado. Lista vacia.\n");
                                return;
                        }

                        if (actual == cabeza_e)
                        {
                                cabeza_e = cabeza_e->siguiente;
                                cola_e->siguiente = cabeza_e;
                        }
                        else if (actual == cola_e)
                        {
                                cola_e = anterior;
                                cola_e->siguiente = cabeza_e;
                        }
                        else
                        {
                                anterior->siguiente = actual->siguiente;
                        }

                        printf("Estudiante con codigo %d eliminado.\n", codigoEliminar);
                        free(actual);
                        return;
                }
                anterior = actual;
                actual = actual->siguiente;
        } while (actual != cabeza_e);

        printf("Estudiante con codigo %d no encontrado para eliminar.\n", codigoEliminar);
}

void contarAprobadosReprobados()
{
        int aprobados = 0;
        int reprobados = 0;
        if (cabeza_e == NULL)
        {
                printf("La lista esta vacia.\n");
                return;
        }

        Estudiante *actual = cabeza_e;
        do
        {
                if (actual->nota >= 3.0)
                {
                        aprobados++;
                }
                else
                {
                        reprobados++;
                }
                actual = actual->siguiente;
        } while (actual != cabeza_e);

        printf("\n--- Resumen de Estudiantes ---\n");
        printf("Total de estudiantes aprobados: %d\n", aprobados);
        printf("Total de estudiantes reprobados: %d\n", reprobados);
        printf("Total general: %d\n", aprobados + reprobados);
}

void liberarMemoriaEstudiantes()
{
        if (cabeza_e == NULL)
                return;
        Estudiante *actual = cabeza_e->siguiente;
        cabeza_e->siguiente = NULL;
        while (actual != NULL)
        {
                Estudiante *temp = actual;
                actual = actual->siguiente;
                free(temp);
        }
        free(cabeza_e);
        cabeza_e = cola_e = NULL;
}

int main()
{
        int opcion;
        do
        {
                printf("\n\n--- MENU ESTUDIANTES (LISTA CIRCULAR) ---\n");
                printf("1. Agregar un estudiante\n");
                printf("2. Buscar un estudiante por codigo\n");
                printf("3. Eliminar un estudiante\n");
                printf("4. Total de estudiantes aprobados/reprobados\n");
                printf("0. Salir\n");
                printf("Seleccione una opcion: ");
                scanf("%d", &opcion);
                limpiarBuffer();

                switch (opcion)
                {
                case 1:
                        agregarEstudiante();
                        break;
                case 2:
                        buscarEstudiante();
                        break;
                case 3:
                        eliminarEstudiante();
                        break;
                case 4:
                        contarAprobadosReprobados();
                        break;
                case 0:
                        liberarMemoriaEstudiantes();
                        printf("Saliendo del programa.\n");
                        break;
                default:
                        printf("Opcion invalida. Intente de nuevo.\n");
                }
        } while (opcion != 0);

        return 0;
}