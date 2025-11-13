#include <stdio.h>
#include <stdlib.h>

// Estructura para un nodo de la lista
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Puntero a la cabeza de la lista
Nodo* cabeza = NULL;

// Funcion para insertar un nuevo nodo al inicio de la lista
void insertar(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return;
    }
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
    printf("Numero %d insertado.\n", valor);
}

// Funcion para eliminar un nodo con un valor especifico
void eliminar(int valor) {
    Nodo *actual = cabeza;
    Nodo *anterior = NULL;

    // Caso 1: El nodo a eliminar es la cabeza
    if (actual != NULL && actual->dato == valor) {
        cabeza = actual->siguiente; // Mover la cabeza al siguiente nodo
        free(actual); // Liberar la memoria del nodo
        printf("Numero %d eliminado de la lista.\n", valor);
        return;
    }

    // Caso 2: Buscar el nodo a eliminar en el resto de la lista
    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si 'actual' es NULL, el valor no se encontro
    if (actual == NULL) {
        printf("El numero %d NO se encontro en la lista.\n", valor);
        return;
    }

    // Caso 3: El nodo a eliminar esta en medio o al final
    anterior->siguiente = actual->siguiente; // Saltar el nodo actual
    free(actual); // Liberar la memoria del nodo
    printf("Numero %d eliminado de la lista.\n", valor);
}

// Funcion para mostrar la lista
void mostrarLista() {
    Nodo* actual = cabeza;
    printf("Lista actual: ");
    if (actual == NULL) {
        printf("Lista vacia.\n");
        return;
    }
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Funcion principal del Ejercicio 2
void ejercicio2() {
    int numeroBuscar;

    printf("\n--- EJERCICIO 2: BUSCAR Y ELIMINAR UN ELEMENTO ---\n");

    // 1. Insertar varios numeros enteros
    insertar(40);
    insertar(20);
    insertar(10);
    insertar(50);
    mostrarLista();

    // 2. Permitir al usuario buscar un numero
    printf("Ingrese el numero que desea buscar y eliminar: ");
    if (scanf("%d", &numeroBuscar) != 1) {
        // Manejo basico de error de entrada
        printf("Entrada invalida. Saliendo del ejercicio.\n");
        while(getchar() != '\n'); // Limpiar buffer de entrada
        return;
    }

    // 3 y 4. Buscar y eliminar o mostrar mensaje
    eliminar(numeroBuscar);
    mostrarLista();
}

// Liberar la memoria de la lista (util para el final del programa)
void liberarLista() {
    Nodo *actual = cabeza;
    Nodo *siguiente = NULL;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    cabeza = NULL;
}

// Ejercicio 3
// Funcion para mostrar, contar y sumar los elementos de la lista
void contarYSumar(Nodo* lista) {
    int contador = 0;
    int suma = 0;
    Nodo* actual = lista;

    printf("Elementos de la lista: ");
    if (actual == NULL) {
        printf("Lista vacia.\n");
        printf("Cantidad de nodos: 0\n");
        printf("Suma total de valores: 0\n");
        return;
    }

    // Recorrer la lista
    while (actual != NULL) {
        printf("%d ", actual->dato);
        contador++;
        suma += actual->dato;
        actual = actual->siguiente;
    }
    printf("\n");

    // Mostrar los resultados
    printf("Cantidad de nodos: %d\n", contador);
    printf("Suma total de valores: %d\n", suma);
}

// Funcion para insertar al inicio (usada para crear la lista del ejercicio 3)
// Se renombra a insertar_e3 para evitar conflictos con la global 'cabeza' del E2
Nodo* insertar_e3(Nodo* cabeza_e3, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return cabeza_e3;
    }
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = cabeza_e3;
    return nuevoNodo;
}

// Funcion para liberar la memoria de la lista del Ejercicio 3
void liberarLista_e3(Nodo* lista) {
    Nodo *actual = lista;
    Nodo *siguiente = NULL;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

// Funcion principal del Ejercicio 3
void ejercicio3() {
    Nodo* lista_e3 = NULL; // Lista local para el ejercicio 3

    printf("\n--- EJERCICIO 3: CONTAR Y SUMAR LOS ELEMENTOS ---\n");

    // Crear la lista con algunos valores
    lista_e3 = insertar_e3(lista_e3, 5);
    lista_e3 = insertar_e3(lista_e3, 15);
    lista_e3 = insertar_e3(lista_e3, 30);
    lista_e3 = insertar_e3(lista_e3, 10);
    lista_e3 = insertar_e3(lista_e3, 20);

    // 1. Mostrar todos los elementos, 2. Contar y sumar
    contarYSumar(lista_e3);

    // Liberar la memoria de esta lista local
    liberarLista_e3(lista_e3);
}

int main() {
    ejercicio2();
    liberarLista(); // Liberar memoria de la lista global del Ejercicio 2

    ejercicio3();

    return 0;
}