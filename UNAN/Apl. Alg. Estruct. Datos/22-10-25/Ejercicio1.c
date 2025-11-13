#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura del nodo para el paciente
struct nodo {
    int codigo;       // campo codigo
    char nombres[30]; // campo que almacena el nombre
    char apellidos[30];// campo que almacena el apellido
    char direccion[60];// campo que almacena la direccion
    long telefono;    // campo que almacena el telefono
    struct nodo *sgte; // Puntero al siguiente nodo
};

typedef struct nodo *Lista; // Alias para el puntero al inicio de la lista

// Prototipos de funciones
void menu();
Lista crearNodo(int codigo, char *nombres, char *apellidos, char *direccion, long telefono);
void registrarPaciente(Lista *lista);
void eliminarPaciente(Lista *lista);
void actualizarPaciente(Lista lista);
void mostrarPaciente(Lista lista);
void mostrarListado(Lista lista);
void liberarLista(Lista *lista);
Lista buscarPaciente(Lista lista, int codigo);
void limpiarBuffer();

// Función principal
int main() {
    Lista listaPacientes = NULL; // Inicializa la lista vacía
    int opcion;

    do {
        menu();
        if (scanf("%d", &opcion) != 1) {
            printf("\nOpcion invalida. Intente de nuevo.\n");
            limpiarBuffer();
            continue;
        }
        limpiarBuffer(); // Limpia el buffer después de leer el entero

        switch (opcion) {
            case 1:
                registrarPaciente(&listaPacientes);
                break;
            case 2:
                eliminarPaciente(&listaPacientes);
                break;
            case 3:
                actualizarPaciente(listaPacientes);
                break;
            case 4:
                mostrarPaciente(listaPacientes);
                break;
            case 5:
                mostrarListado(listaPacientes);
                break;
            case 6:
                printf("\nSaliendo del sistema. Liberando memoria...\n");
                liberarLista(&listaPacientes); // Libera la memoria antes de salir
                printf("Memoria liberada. Hasta pronto!\n");
                break;
            default:
                printf("\nOpcion no valida. Por favor, seleccione una opcion del 1 al 6.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}

void menu() {
    printf("\n=========================================\n");
    printf("     SISTEMA DE CONTROL DE PACIENTES     \n");
    printf("=========================================\n");
    printf("1. Registrar paciente\n");
    printf("2. Eliminar datos de paciente\n");
    printf("3. Actualizar datos de paciente\n");
    printf("4. Mostrar datos de paciente (Busqueda por codigo)\n");
    printf("5. Mostrar listado de pacientes\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Lista crearNodo(int codigo, char *nombres, char *apellidos, char *direccion, long telefono) {
    Lista nuevoNodo = (Lista)malloc(sizeof(struct nodo));
    if (nuevoNodo == NULL) {
        perror("Error al asignar memoria para el nuevo paciente");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->codigo = codigo;
    strncpy(nuevoNodo->nombres, nombres, 29);
    nuevoNodo->nombres[29] = '\0';
    strncpy(nuevoNodo->apellidos, apellidos, 29);
    nuevoNodo->apellidos[29] = '\0';
    strncpy(nuevoNodo->direccion, direccion, 59);
    nuevoNodo->direccion[59] = '\0';
    nuevoNodo->telefono = telefono;
    nuevoNodo->sgte = NULL;
    return nuevoNodo;
}

Lista buscarPaciente(Lista lista, int codigo) {
    Lista actual = lista;
    while (actual != NULL) {
        if (actual->codigo == codigo) {
            return actual; // Paciente encontrado
        }
        actual = actual->sgte;
    }
    return NULL; // Paciente no encontrado
}

void registrarPaciente(Lista *lista) {
    int codigo;
    char nombres[30], apellidos[30], direccion[60];
    long telefono;

    printf("\n--- REGISTRAR PACIENTE ---\n");
    printf("Ingrese Codigo: ");
    while (scanf("%d", &codigo) != 1 || codigo <= 0) {
        printf("Codigo invalido. Ingrese un numero positivo: ");
        limpiarBuffer();
    }
    limpiarBuffer(); // Limpia buffer después de leer el entero

    if (buscarPaciente(*lista, codigo) != NULL) {
        printf("\n¡Error! Ya existe un paciente con el codigo %d.\n", codigo);
        return;
    }

    printf("Ingrese Nombres: ");
    fgets(nombres, 30, stdin);
    nombres[strcspn(nombres, "\n")] = 0; // Eliminar salto de línea

    printf("Ingrese Apellidos: ");
    fgets(apellidos, 30, stdin);
    apellidos[strcspn(apellidos, "\n")] = 0;

    printf("Ingrese Direccion: ");
    fgets(direccion, 60, stdin);
    direccion[strcspn(direccion, "\n")] = 0;

    printf("Ingrese Telefono: ");
    while (scanf("%ld", &telefono) != 1 || telefono <= 0) {
        printf("Telefono invalido. Ingrese un numero positivo: ");
        limpiarBuffer();
    }
    limpiarBuffer();

    Lista nuevo = crearNodo(codigo, nombres, apellidos, direccion, telefono);

    if (*lista == NULL) {
        *lista = nuevo; // Si la lista está vacía, el nuevo nodo es el inicio
    } else {
        Lista actual = *lista;
        while (actual->sgte != NULL) {
            actual = actual->sgte;
        }
        actual->sgte = nuevo; // Se enlaza al final de la lista
    }
    printf("\nPaciente con codigo %d registrado exitosamente.\n", codigo);
}

void eliminarPaciente(Lista *lista) {
    int codigoBuscar;
    printf("\n--- ELIMINAR PACIENTE ---\n");

    if (*lista == NULL) {
        printf("\nLa lista de pacientes esta vacia. No hay nada que eliminar.\n");
        return;
    }

    printf("Ingrese el Codigo del paciente a eliminar: ");
    while (scanf("%d", &codigoBuscar) != 1 || codigoBuscar <= 0) {
        printf("Codigo invalido. Ingrese un numero positivo: ");
        limpiarBuffer();
    }
    limpiarBuffer();

    Lista actual = *lista;
    Lista anterior = NULL;

    // Caso: El nodo a eliminar es el primero
    if (actual != NULL && actual->codigo == codigoBuscar) {
        *lista = actual->sgte; // Cambia la cabeza de la lista
        free(actual);          // Libera la memoria
        printf("\nPaciente con codigo %d eliminado exitosamente.\n", codigoBuscar);
        return;
    }

    // Busca el nodo, manteniendo un puntero al anterior
    while (actual != NULL && actual->codigo != codigoBuscar) {
        anterior = actual;
        actual = actual->sgte;
    }

    // Si el paciente no se encontró
    if (actual == NULL) {
        printf("\nPaciente con codigo %d no encontrado.\n", codigoBuscar);
        return;
    }

    // Desenlaza el nodo de la lista y lo libera
    anterior->sgte = actual->sgte;
    free(actual);
    printf("\nPaciente con codigo %d eliminado exitosamente.\n", codigoBuscar);
}

void actualizarPaciente(Lista lista) {
    int codigoBuscar;
    char nombres[30], apellidos[30], direccion[60];
    long telefono;

    printf("\n--- ACTUALIZAR DATOS DE PACIENTE ---\n");

    if (lista == NULL) {
        printf("\nLa lista de pacientes esta vacia.\n");
        return;
    }

    printf("Ingrese el Codigo del paciente a actualizar: ");
    while (scanf("%d", &codigoBuscar) != 1 || codigoBuscar <= 0) {
        printf("Codigo invalido. Ingrese un numero positivo: ");
        limpiarBuffer();
    }
    limpiarBuffer();

    Lista paciente = buscarPaciente(lista, codigoBuscar);

    if (paciente == NULL) {
        printf("\nPaciente con codigo %d no encontrado.\n", codigoBuscar);
        return;
    }

    printf("\nDatos actuales del paciente %d: %s %s\n", paciente->codigo, paciente->nombres, paciente->apellidos);
    printf("\n--- Ingrese nuevos datos ---\n");

    // Recoger y actualizar nuevos datos
    printf("Nuevo Nombres (Deje vacio para no cambiar: %s): ", paciente->nombres);
    if (fgets(nombres, 30, stdin) && nombres[0] != '\n') {
        nombres[strcspn(nombres, "\n")] = 0;
        strncpy(paciente->nombres, nombres, 29);
        paciente->nombres[29] = '\0';
    }

    printf("Nuevo Apellidos (Deje vacio para no cambiar: %s): ", paciente->apellidos);
    if (fgets(apellidos, 30, stdin) && apellidos[0] != '\n') {
        apellidos[strcspn(apellidos, "\n")] = 0;
        strncpy(paciente->apellidos, apellidos, 29);
        paciente->apellidos[29] = '\0';
    }

    printf("Nueva Direccion (Deje vacio para no cambiar: %s): ", paciente->direccion);
    if (fgets(direccion, 60, stdin) && direccion[0] != '\n') {
        direccion[strcspn(direccion, "\n")] = 0;
        strncpy(paciente->direccion, direccion, 59);
        paciente->direccion[59] = '\0';
    }

    printf("Nuevo Telefono (Actual: %ld): ", paciente->telefono);
    char tel_str[20];
    if (fgets(tel_str, 20, stdin) && tel_str[0] != '\n') {
        if (sscanf(tel_str, "%ld", &telefono) == 1 && telefono > 0) {
            paciente->telefono = telefono;
        } else {
            printf("\nTelefono invalido. No se ha actualizado el telefono.\n");
        }
    }

    printf("\nDatos del paciente %d actualizados exitosamente.\n", codigoBuscar);
}

void mostrarPaciente(Lista lista) {
    int codigoBuscar;
    printf("\n--- MOSTRAR DATOS DE PACIENTE ---\n");

    if (lista == NULL) {
        printf("\nLa lista de pacientes esta vacia.\n");
        return;
    }

    printf("Ingrese el Codigo del paciente a mostrar: ");
    while (scanf("%d", &codigoBuscar) != 1 || codigoBuscar <= 0) {
        printf("Codigo invalido. Ingrese un numero positivo: ");
        limpiarBuffer();
    }
    limpiarBuffer();

    Lista paciente = buscarPaciente(lista, codigoBuscar);

    if (paciente == NULL) {
        printf("\nPaciente con codigo %d no encontrado.\n", codigoBuscar);
    } else {
        printf("\n--- DATOS DEL PACIENTE: %d ---\n", paciente->codigo);
        printf("Codigo: %d\n", paciente->codigo);
        printf("Nombres: %s\n", paciente->nombres);
        printf("Apellidos: %s\n", paciente->apellidos);
        printf("Direccion: %s\n", paciente->direccion);
        printf("Telefono: %ld\n", paciente->telefono);
        printf("------------------------------\n");
    }
}

void mostrarListado(Lista lista) {
    printf("\n--- LISTADO COMPLETO DE PACIENTES ---\n");
    if (lista == NULL) {
        printf("La lista de pacientes esta vacia.\n");
        return;
    }

    Lista actual = lista;
    int contador = 1;
    while (actual != NULL) {
        printf("\n--- Paciente #%d ---\n", contador);
        printf("Codigo: %d\n", actual->codigo);
        printf("Nombres: %s\n", actual->nombres);
        printf("Apellidos: %s\n", actual->apellidos);
        printf("Direccion: %s\n", actual->direccion);
        printf("Telefono: %ld\n", actual->telefono);
        printf("----------------------\n");
        actual = actual->sgte;
        contador++;
    }
}

void liberarLista(Lista *lista) {
    Lista actual = *lista;
    Lista sgte;

    while (actual != NULL) {
        sgte = actual->sgte; // Guarda el puntero al siguiente antes de liberar
        free(actual);        // Libera el nodo actual
        actual = sgte;       // Avanza al siguiente nodo
    }
    *lista = NULL; // Asegura que la lista quede en NULL
}