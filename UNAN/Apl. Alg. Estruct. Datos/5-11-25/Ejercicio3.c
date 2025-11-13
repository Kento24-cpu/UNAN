#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct Huesped
{
        int numHab;
        char nombre[100];
        time_t fechaArr;
        float precio;
        struct Huesped *siguiente;
} Huesped;

Huesped *listaHuespedes = NULL;

void limpiarBuffer()
{
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
}

void obtenerFechaStr(time_t tiempo, char *buffer)
{
        struct tm *tm_info = localtime(&tiempo);
        strftime(buffer, 20, "%Y-%m-%d", tm_info);
}

void registrarHuesped()
{
        Huesped *nuevo = (Huesped *)malloc(sizeof(Huesped));
        if (nuevo == NULL)
        {
                printf("Error de asignacion de memoria.\n");
                return;
        }

        printf("\n--- Registrar Huesped ---\n");
        printf("Numero de Habitacion (para ordenar): ");
        scanf("%d", &nuevo->numHab);
        limpiarBuffer();
        printf("Nombre del Huesped: ");
        fgets(nuevo->nombre, 100, stdin);
        nuevo->nombre[strcspn(nuevo->nombre, "\n")] = 0;
        printf("Precio de la Habitacion por dia: ");
        scanf("%f", &nuevo->precio);
        limpiarBuffer();

        nuevo->fechaArr = time(NULL);

        if (listaHuespedes == NULL)
        {
                listaHuespedes = nuevo;
                nuevo->siguiente = nuevo;
                printf("Huesped registrado. Lista circular inicializada.\n");
                return;
        }

        Huesped *actual = listaHuespedes;
        Huesped *anterior = NULL;

        // Buscar la posicion de insercion para mantener el orden
        do
        {
                if (actual->numHab > nuevo->numHab)
                {
                        break;
                }
                anterior = actual;
                actual = actual->siguiente;
        } while (actual != listaHuespedes);

        // 1. Insertar al INICIO
        if (anterior == NULL)
        {
                Huesped *ultimo = listaHuespedes;
                while (ultimo->siguiente != listaHuespedes)
                {
                        ultimo = ultimo->siguiente;
                }

                nuevo->siguiente = listaHuespedes;
                ultimo->siguiente = nuevo;
                listaHuespedes = nuevo;
        }
        // 2. Insertar al FINAL o INTERMEDIO
        else
        {
                nuevo->siguiente = anterior->siguiente;
                anterior->siguiente = nuevo;
        }
        printf("Huesped registrado y lista circular ordenada.\n");
}

void borrarHuesped()
{
        if (listaHuespedes == NULL)
        {
                printf("La lista de huespedes esta vacia. Nada que borrar.\n");
                return;
        }
        int numHabBorrar;
        printf("\n--- Borrar Huesped ---\n");
        printf("Ingrese numero de habitacion del huesped a borrar: ");
        scanf("%d", &numHabBorrar);
        limpiarBuffer();

        Huesped *actual = listaHuespedes;
        Huesped *anterior = NULL;

        do
        {
                if (actual->numHab == numHabBorrar)
                {
                        if (actual == listaHuespedes && actual->siguiente == listaHuespedes)
                        {
                                free(actual);
                                listaHuespedes = NULL;
                                printf("Ultimo huesped borrado. Lista vacia.\n");
                                return;
                        }

                        if (actual == listaHuespedes)
                        {
                                Huesped *ultimo = listaHuespedes;
                                while (ultimo->siguiente != listaHuespedes)
                                {
                                        ultimo = ultimo->siguiente;
                                }
                                listaHuespedes = listaHuespedes->siguiente;
                                ultimo->siguiente = listaHuespedes;
                                anterior = actual;
                        }
                        else
                        {
                                anterior->siguiente = actual->siguiente;
                        }

                        printf("Huesped de habitacion %d borrado.\n", numHabBorrar);
                        free(actual);
                        return;
                }
                anterior = actual;
                actual = actual->siguiente;
        } while (actual != listaHuespedes);

        printf("Huesped con numero de habitacion %d no encontrado para borrar.\n", numHabBorrar);
}

void buscarHuesped()
{
        if (listaHuespedes == NULL)
        {
                printf("La lista de huespedes esta vacia.\n");
                return;
        }
        int numHabBuscado;
        printf("\n--- Buscar Huesped ---\n");
        printf("Ingrese numero de habitacion a buscar: ");
        scanf("%d", &numHabBuscado);
        limpiarBuffer();

        Huesped *actual = listaHuespedes;
        do
        {
                if (actual->numHab == numHabBuscado)
                {
                        char fecha_str[20];
                        obtenerFechaStr(actual->fechaArr, fecha_str);
                        printf("\n--- Huesped Encontrado ---\n");
                        printf("Habitacion: %d\n", actual->numHab);
                        printf("Nombre: %s\n", actual->nombre);
                        printf("Fecha Arribo: %s\n", fecha_str);
                        printf("Precio por dia: %.2f\n", actual->precio);
                        return;
                }
                actual = actual->siguiente;
        } while (actual != listaHuespedes);

        printf("Huesped con habitacion %d no encontrado.\n", numHabBuscado);
}

void visualizarInforme()
{
        if (listaHuespedes == NULL)
        {
                printf("No hay huespedes registrados.\n");
                return;
        }

        printf("\n--- INFORME DE HUESPEDES REGISTRADOS ---\n");
        printf("| %-10s | %-30s | %-12s | %-8s |\n",
               "Num. Hab.", "Nombre", "Fecha Arribo", "Precio");
        printf("|------------|--------------------------------|--------------|----------|\n");

        Huesped *actual = listaHuespedes;
        do
        {
                char fecha_str[20];
                obtenerFechaStr(actual->fechaArr, fecha_str);

                printf("| %-10d | %-30s | %-12s | %-8.2f |\n",
                       actual->numHab, actual->nombre, fecha_str, actual->precio);

                actual = actual->siguiente;
        } while (actual != listaHuespedes);
}

void facturacion()
{
        if (listaHuespedes == NULL)
        {
                printf("La lista de huespedes esta vacia.\n");
                return;
        }
        char nombreBuscado[100];
        printf("\n--- Facturacion ---\n");
        printf("Ingrese nombre del huesped a facturar: ");
        fgets(nombreBuscado, 100, stdin);
        nombreBuscado[strcspn(nombreBuscado, "\n")] = 0;

        Huesped *huesped = NULL;
        Huesped *actual = listaHuespedes;
        do
        {
                if (strcmp(actual->nombre, nombreBuscado) == 0)
                {
                        huesped = actual;
                        break;
                }
                actual = actual->siguiente;
        } while (actual != listaHuespedes);

        if (huesped == NULL)
        {
                printf("Huesped %s no encontrado.\n", nombreBuscado);
                return;
        }

        time_t fechaActual = time(NULL);
        double segundosAlojados = difftime(fechaActual, huesped->fechaArr);

        double diasAlojados = segundosAlojados / (60.0 * 60.0 * 24.0);

        if (diasAlojados < 1.0)
        {
                diasAlojados = 1.0;
        }
        else
        {
                diasAlojados = ceil(diasAlojados);
        }

        double total = diasAlojados * huesped->precio;

        printf("\n--- DETALLE DE FACTURA ---\n");
        printf("Huesped: %s\n", huesped->nombre);
        printf("Habitacion: %d\n", huesped->numHab);
        printf("Precio diario: %.2f\n", huesped->precio);
        printf("Dias de alojamiento (aproximado): %.0f dias\n", diasAlojados);
        printf("TOTAL A PAGAR: %.2f\n", total);
}

void liberarMemoriaHuespedes()
{
        if (listaHuespedes == NULL)
                return;
        Huesped *actual = listaHuespedes->siguiente;
        listaHuespedes->siguiente = NULL;
        while (actual != NULL)
        {
                Huesped *temp = actual;
                actual = actual->siguiente;
                free(temp);
        }
        free(listaHuespedes);
        listaHuespedes = NULL;
}

int main()
{
        int opcion;
        do
        {
                printf("\n\n--- MENU HUESPEDES (LISTA CIRCULAR ORDENADA) ---\n");
                printf("1. Registrar un huesped\n");
                printf("2. Borrar un huesped de la lista\n");
                printf("3. Buscar un huesped en la lista\n");
                printf("4. Visualizar un informe de los huespedes\n");
                printf("5. Facturacion\n");
                printf("0. Salir\n");
                printf("Seleccione una opcion: ");
                scanf("%d", &opcion);
                limpiarBuffer();

                switch (opcion)
                {
                case 1:
                        registrarHuesped();
                        break;
                case 2:
                        borrarHuesped();
                        break;
                case 3:
                        buscarHuesped();
                        break;
                case 4:
                        visualizarInforme();
                        break;
                case 5:
                        facturacion();
                        break;
                case 0:
                        liberarMemoriaHuespedes();
                        printf("Saliendo del programa.\n");
                        break;
                default:
                        printf("Opcion invalida. Intente de nuevo.\n");
                }
        } while (opcion != 0);

        return 0;
}