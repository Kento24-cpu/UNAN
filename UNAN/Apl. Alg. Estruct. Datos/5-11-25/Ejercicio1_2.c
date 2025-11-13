#include <stdio.h>
#include <stdlib.h>

// Definicion de la estructura del nodo
struct Nodo
{
        int dato;
        struct Nodo *siguiente;
};

// Funcion para crear un nuevo nodo
struct Nodo *crearNodo(int dato)
{
        struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
        if (nuevoNodo == NULL)
        {
                printf("Error: No se pudo asignar memoria.\n");
                exit(1);
        }
        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = NULL;
        return nuevoNodo;
}

// Funcion para mostrar la lista una vez (Ejercicio 1)
void mostrarListaUnaVez(struct Nodo *primero)
{
        if (primero == NULL)
        {
                printf("Lista vacia.\n");
                return;
        }

        struct Nodo *actual = primero;

        // Recorrer una sola vuelta e imprimir el ultimo nodo
        do
        {
                printf("%d", actual->dato);
                actual = actual->siguiente;

                // El " -> " se imprime despues de cada nodo
                printf(" -> ");

        } while (actual != primero);

        printf("\n");
}

// Funcion para mostrar la lista dos veces (Ejercicio 2)
void mostrarListaDosVeces(struct Nodo *primero)
{
        if (primero == NULL)
        {
                printf("Lista vacia.\n");
                return;
        }

        struct Nodo *actual = primero;
        int vueltas = 0;
        int max_vueltas = 2;
        int nodos_por_vuelta = 3;
        int nodos_recorridos = 0;

        while (vueltas < max_vueltas)
        {
                if (nodos_recorridos % nodos_por_vuelta == 0)
                {
                        vueltas++;
                        if (vueltas > 1)
                        {
                                printf("\nRecorrido %d: ", vueltas);
                        }
                        else
                        {
                                printf("Recorrido %d: ", vueltas);
                        }
                }

                printf("%d", actual->dato);

                // Imprimir " -> " al final de cada nodo
                printf(" -> ");

                actual = actual->siguiente;
                nodos_recorridos++;
        }
        // Para asegurar que la ultima flecha no se imprima justo despues de la segunda vuelta
        // Se ha modificado el bucle para que termine despues de la segunda flecha.
        printf("\n");
}

// Funcion principal
int main()
{
        // 1. Crear los nodos
        struct Nodo *nodo1 = crearNodo(10);
        struct Nodo *nodo2 = crearNodo(20);
        struct Nodo *nodo3 = crearNodo(30);

        // 2. Enlazar los nodos
        nodo1->siguiente = nodo2;
        nodo2->siguiente = nodo3;

        // Modificacion: Hacerla circular (ultimo nodo apunta al primero)
        nodo3->siguiente = nodo1;

        struct Nodo *primero = nodo1;

        // --- Ejercicio 1 ---
        printf("--- Ejercicio 1: Crear y mostrar una lista circular simple ---\n");
        mostrarListaUnaVez(primero);
        printf("\n");

        // --- Ejercicio 2 ---
        printf("--- Ejercicio 2: Recorrer la lista circular dos veces ---\n");
        mostrarListaDosVeces(primero);

        // Liberar la memoria
        if (primero != NULL)
        {
                struct Nodo *actual = primero->siguiente;
                struct Nodo *temp;
                primero->siguiente = NULL;

                while (actual != NULL)
                {
                        temp = actual;
                        actual = actual->siguiente;
                        free(temp);
                }
                free(primero);
        }

        return 0;
}