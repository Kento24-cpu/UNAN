#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Tarea modificada para título dinámico
typedef struct Tarea {
    int id;
    char* titulo;        // Usar puntero para memoria dinámica
    int prioridad;       // 1 alta, 2 media, 3 baja
    int estado;          // 0 pendiente, 1 completada
    struct Tarea* siguiente;
} Tarea;

static int siguiente_id_global = 1;
#define FILENAME "tareas.txt" // Nombre del archivo de persistencia

// Prototipos
Tarea* crear_tarea(const char* titulo, int prioridad, int id);
void insertar_ordenado(Tarea** cabeza, Tarea* nueva_tarea);
void listar_tareas(const Tarea* cabeza, int filtro_estado);
int completar_tarea(Tarea* cabeza, int id);
Tarea* buscar_tarea_por_id(Tarea* cabeza, int id); // Nueva para edición
int editar_tarea(Tarea** cabeza, int id);         // Nueva variante
int eliminar_tarea(Tarea** cabeza, int id);
void buscar_por_prioridad(const Tarea* cabeza, int prioridad);
void liberar_todo(Tarea** cabeza);
int siguiente_id(void);
void leer_linea(char* buf, size_t sz);
static int menor_o_igual(const Tarea* a, const Tarea* b);

// Funciones de las variantes
void mostrar_estadisticas(const Tarea* cabeza); // Variante Estadísticas
int guardar_lista(const Tarea* cabeza);        // Variante Persistencia
int cargar_lista(Tarea** cabeza);              // Variante Persistencia

// Implementación de Lógica y Helpers
static int menor_o_igual(const Tarea* a, const Tarea* b) {
    if (a->prioridad != b->prioridad) return a->prioridad < b->prioridad;
    return a->id <= b->id;
}

void leer_linea(char* buf, size_t sz) {
    if (fgets(buf, (int)sz, stdin)) {
        size_t n = strlen(buf);
        if (n > 0 && buf[n - 1] == '\n') buf[n - 1] = '\0';
    } else {
        if (sz > 0) buf[0] = '\0';
    }
}

int siguiente_id(void) {
    return siguiente_id_global++;
}

Tarea* crear_tarea(const char* titulo, int prioridad, int id) {
    Tarea* t = (Tarea*)malloc(sizeof(Tarea));
    if (!t) {
        perror("Error al asignar memoria para Tarea");
        exit(EXIT_FAILURE);
    }
    t->id = id;
    // VARIANT: Títulos con memoria dinámica
    t->titulo = strdup(titulo); // strdup asigna memoria y copia la cadena
    if (!t->titulo) {
        perror("Error al asignar memoria para el título");
        free(t);
        exit(EXIT_FAILURE);
    }
    t->prioridad = prioridad;
    t->estado = 0; // pendiente
    t->siguiente = NULL;
    // Ajustar el ID global si se está cargando desde archivo
    if (id >= siguiente_id_global) {
        siguiente_id_global = id + 1;
    }
    return t;
}

void insertar_ordenado(Tarea** cabeza, Tarea* nueva_tarea) {
    if (*cabeza == NULL || !menor_o_igual(nueva_tarea, *cabeza)) {
        nueva_tarea->siguiente = *cabeza;
        *cabeza = nueva_tarea;
        return;
    }
    Tarea* anterior = *cabeza;
    Tarea* actual = (*cabeza)->siguiente;

    while (actual != NULL && menor_o_igual(actual, nueva_tarea)) {
        anterior = actual;
        actual = actual->siguiente;
    }
    anterior->siguiente = nueva_tarea;
    nueva_tarea->siguiente = actual;
}

/**
 Lista tareas, aplicando un filtro de estado (-1: todas, 0: pendientes, 1: completadas).
 CORRECCIÓN: Se agrega la llave de cierre faltante.
 */
void listar_tareas(const Tarea* cabeza, int filtro_estado) {
    if (!cabeza) {
        printf("[Lista vacía]\n");
        return;
    }
    int conteo = 0;
    const Tarea* p = cabeza;
    printf("\n--- Listado de Tareas ---\n");
    while (p) {
        if (filtro_estado == -1 || p->estado == filtro_estado) {
            printf("ID:%-4d | Pri:%d | Estado:%-5s | Título:%s\n",
                   p->id, p->prioridad, p->estado ? "COMPL" : "PEND", p->titulo);
            conteo++;
        }
        p = p->siguiente;
    }
    if (conteo == 0) {
        printf("[No hay tareas para el filtro solicitado]\n");
    }
}

// @brief Marca una tarea como completada por su ID.
int completar_tarea(Tarea* cabeza, int id) {
    Tarea* p = cabeza;
    while (p) {
        if (p->id == id) {
            p->estado = 1;
            return 1;
        }
        p = p->siguiente;
    }
    return 0;
}

// Busca una tarea por ID y devuelve su puntero.
Tarea* buscar_tarea_por_id(Tarea* cabeza, int id) {
    Tarea* p = cabeza;
    while (p) {
        if (p->id == id) return p;
        p = p->siguiente;
    }
    return NULL;
}

int editar_tarea(Tarea** cabeza, int id) {
    Tarea* tarea = buscar_tarea_por_id(*cabeza, id);
    if (!tarea) {
        printf("No se encontró la tarea con id %d.\n", id);
        return 0;
    }

    printf("Editando Tarea ID %d (Prioridad actual: %d, Título actual: %s)\n",
           id, tarea->prioridad, tarea->titulo);

    // Editar Título
    char nuevo_titulo[128];
    printf("Nuevo título (dejar vacío para no cambiar): ");
    leer_linea(nuevo_titulo, sizeof(nuevo_titulo));

    if (strlen(nuevo_titulo) > 0) {
        free(tarea->titulo); // Liberar el título viejo (memoria dinámica)
        tarea->titulo = strdup(nuevo_titulo);
        if (!tarea->titulo) {
            perror("Error al asignar memoria para el nuevo título");
            exit(EXIT_FAILURE);
        }
        printf("Título actualizado.\n");
    }

    // Editar Prioridad
    int nueva_prioridad = tarea->prioridad;
    printf("Nueva prioridad (1-3, 0 para no cambiar): ");
    if (scanf("%d", &nueva_prioridad) == 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF) {} // Limpiar buffer

        if (nueva_prioridad >= 1 && nueva_prioridad <= 3 && nueva_prioridad != tarea->prioridad) {
            int vieja_prioridad = tarea->prioridad;
            tarea->prioridad = nueva_prioridad;

            // Si la prioridad cambió, debe reordenarse (eliminar y reinsertar)
            Tarea* temp = tarea;
            // Primero, remover temporalmente el nodo de la lista SIN liberar
            if (eliminar_tarea(cabeza, id)) {
                temp->siguiente = NULL; // Asegurar que el nodo removido no apunte a la lista
                // Reinsertar ordenadamente con la nueva prioridad
                insertar_ordenado(cabeza, temp);
                printf("Prioridad cambiada de %d a %d. Tarea reordenada.\n", vieja_prioridad, nueva_prioridad);
            } else {
                // Esto no debería pasar si buscar_tarea_por_id tuvo éxito, pero es un fallback
                printf("Error interno al intentar reordenar la tarea.\n");
                return 0;
            }
        } else if (nueva_prioridad != 0) {
            printf("Prioridad no válida o no cambiada.\n");
        }
    } else {
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
    }

    return 1;
}

// @brief Elimina una tarea por ID, liberando la memoria del título y del nodo.
int eliminar_tarea(Tarea** cabeza, int id) {
    if (*cabeza == NULL) return 0;

    if ((*cabeza)->id == id) {
        Tarea* tmp = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(tmp->titulo); // VARIANT: Liberar título dinámico
        free(tmp);
        return 1;
    }

    Tarea* anterior = *cabeza;
    Tarea* actual = (*cabeza)->siguiente;

    while (actual) {
        if (actual->id == id) {
            anterior->siguiente = actual->siguiente;
            free(actual->titulo); // VARIANT: Liberar título dinámico
            free(actual);
            return 1;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return 0;
}

// Muestra las tareas que coinciden con la prioridad dada.
void buscar_por_prioridad(const Tarea* cabeza, int prioridad) {
    if (prioridad < 1 || prioridad > 3) {
        printf("Prioridad inválida. Use 1/2/3.\n");
        return;
    }
    int encontrado = 0;
    const Tarea* p = cabeza;
    printf("\n--- Tareas con Prioridad %d ---\n", prioridad);
    while (p) {
        if (p->prioridad == prioridad) {
            printf("ID:%-4d | Pri:%d | Estado:%-5s | Título:%s\n",
                   p->id, p->prioridad, p->estado ? "COMPL" : "PEND", p->titulo);
            encontrado = 1;
        }
        p = p->siguiente;
    }
    if (!encontrado) {
        printf("[No hay tareas con prioridad %d]\n", prioridad);
    }
}

// Libera toda la memoria de la lista, incluyendo los títulos.
void liberar_todo(Tarea** cabeza) {
    Tarea* p = *cabeza;
    while (p) {
        Tarea* tmp = p;
        p = p->siguiente;
        free(tmp->titulo); // VARIANT: Liberar título dinámico
        free(tmp);
    }
    *cabeza = NULL;
}
/*
  Implementación de Variantes Adicionales
  VARIANT: Muestra el total de tareas, pendientes y completadas.
*/
void mostrar_estadisticas(const Tarea* cabeza) {
    int total = 0;
    int pendientes = 0;
    int completadas = 0;
    const Tarea* p = cabeza;

    while (p) {
        total++;
        if (p->estado == 0) {
            pendientes++;
        } else {
            completadas++;
        }
        p = p->siguiente;
    }

    printf("\n=== Estadísticas de Tareas ===\n");
    printf("Total de Tareas:     %d\n", total);
    printf("Tareas Pendientes:   %d\n", pendientes);
    printf("Tareas Completadas:  %d\n", completadas);
}

/*
 VARIANT: Guarda la lista en un archivo de texto.
 Formato: id|prioridad|estado|titulo\n
*/
int guardar_lista(const Tarea* cabeza) {
    FILE* f = fopen(FILENAME, "w");
    if (!f) {
        perror("Error al abrir el archivo para guardar");
        return 0;
    }

    const Tarea* p = cabeza;
    while (p) {
        // Guardar id, prioridad, estado y título
        fprintf(f, "%d|%d|%d|%s\n", p->id, p->prioridad, p->estado, p->titulo);
        p = p->siguiente;
    }

    fclose(f);
    return 1;
}

// VARIANT: Carga la lista desde un archivo de texto.
int cargar_lista(Tarea** cabeza) {
    FILE* f = fopen(FILENAME, "r");
    if (!f) {
        // El archivo no existe o no se puede abrir (normal al inicio)
        return 0;
    }

    char buffer[256];
    int id, prioridad, estado;
    char titulo_temp[192];
    int max_id = 0;

    // Liberar cualquier lista existente antes de cargar
    liberar_todo(cabeza);

    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        // Eliminar el salto de línea
        buffer[strcspn(buffer, "\n")] = 0;

        // Intentar parsear el formato: id|prioridad|estado|titulo
        if (sscanf(buffer, "%d|%d|%d|%191[^\n]", &id, &prioridad, &estado, titulo_temp) == 4) {
            Tarea* nueva_tarea = crear_tarea(titulo_temp, prioridad, id);
            nueva_tarea->estado = estado;

            // Reinsertar ordenadamente
            insertar_ordenado(cabeza, nueva_tarea);

            if (id > max_id) {
                max_id = id;
            }
        }
    }
    fclose(f);

    // Ajustar el ID global para evitar colisiones
    siguiente_id_global = max_id + 1;

    if (*cabeza) {
        printf("Lista cargada exitosamente desde %s.\n", FILENAME);
    }
    return 1;
}

// Implementación de MAIN (Menú principal)
int main(void) {
    Tarea* cabeza = NULL;
    int opcion;

    cargar_lista(&cabeza); // Cargar al inicio

    do {
        printf("\n=== Gestor de Tareas (Lista Simple) ===\n");
        printf("1) Agregar tarea\n");
        printf("2) Listar todas\n");
        printf("3) Listar pendientes\n");
        printf("4) Listar completadas\n");
        printf("5) Marcar como completada (por id)\n");
        printf("6) Eliminar tarea (por id)\n");
        printf("7) Buscar por prioridad\n");
        printf("8) Editar tarea (por id) - VARIANTE\n");
        printf("9) Mostrar Estadísticas - VARIANTE\n");
        printf("10) Guardar lista - VARIANTE\n");
        printf("11) Vaciar y salir\n"); // Opción 11 es la nueva salida

        printf("Elige una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            opcion = 0;
        }

        if (opcion == 1) {
            int pr;
            char titulo[64];
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Titulo: ");
            leer_linea(titulo, sizeof(titulo));
            do {
                printf("Prioridad (1 alta, 2 media, 3 baja): ");
                if (scanf("%d", &pr) != 1) {
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    pr = 0;
                }
            } while (pr < 1 || pr > 3);
            Tarea* t = crear_tarea(titulo, pr, siguiente_id());
            insertar_ordenado(&cabeza, t);
            printf("Tarea agregada con id %d.\n", t->id);

        } else if (opcion == 2) {
            listar_tareas(cabeza, -1);
        } else if (opcion == 3) {
            listar_tareas(cabeza, 0);
        } else if (opcion == 4) {
            listar_tareas(cabeza, 1);
        } else if (opcion == 5) {
            int id;
            printf("ID a completar: ");
            if (scanf("%d", &id) == 1) {
                if (completar_tarea(cabeza, id))
                    printf("Tarea %d marcada como completada.\n", id);
                else
                    printf("No se encontró la tarea con id %d.\n", id);
            }
        } else if (opcion == 6) {
            int id;
            printf("ID a eliminar: ");
            if (scanf("%d", &id) == 1) {
                if (eliminar_tarea(&cabeza, id))
                    printf("Tarea %d eliminada.\n", id);
                else
                    printf("No se encontró la tarea con id %d.\n", id);
            }
        } else if (opcion == 7) {
            int pr;
            printf("Prioridad a buscar (1/2/3): ");
            if (scanf("%d", &pr) == 1) {
                buscar_por_prioridad(cabeza, pr);
            }
        } else if (opcion == 8) { // VARIANTE: Edición
            int id;
            printf("ID a editar: ");
            if (scanf("%d", &id) == 1) {
                int c; while ((c = getchar()) != '\n' && c != EOF) {} // Limpiar buffer
                editar_tarea(&cabeza, id);
            }
        } else if (opcion == 9) { // VARIANTE: Estadísticas
            mostrar_estadisticas(cabeza);
        } else if (opcion == 10) { // VARIANTE: Guardar
            if (guardar_lista(cabeza))
                printf("Lista guardada exitosamente en %s.\n", FILENAME);
        } else if (opcion == 11) {
            guardar_lista(cabeza); // Intentar guardar antes de salir
            liberar_todo(&cabeza);
            printf("Memoria liberada. Saliendo...\n");
        } else {
            if (opcion != 0)
                printf("Opción no válida.\n");
        }
    } while (opcion != 11);

    return 0;
}