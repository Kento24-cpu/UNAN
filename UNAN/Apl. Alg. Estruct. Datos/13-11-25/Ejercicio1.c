#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
  int dato;
  struct Nodo *sig;
  struct Nodo *ant;
};

struct Nodo *crearNodo(int dato)
{
  struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
  if (nuevoNodo == NULL)
  {
    printf("Error de asignacion de memoria\n");
    exit(1);
  }
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;
  nuevoNodo->ant = NULL;
  return nuevoNodo;
}

void insertarOrdenado(struct Nodo **cabeza, int dato)
{
  struct Nodo *nuevoNodo = crearNodo(dato);
  if (*cabeza == NULL)
  {
    *cabeza = nuevoNodo;
    (*cabeza)->sig = *cabeza;
    (*cabeza)->ant = *cabeza;
    return;
  }

  struct Nodo *actual = *cabeza;

  if (dato <= actual->dato)
  {
    nuevoNodo->ant = actual->ant;
    nuevoNodo->sig = actual;
    actual->ant->sig = nuevoNodo;
    actual->ant = nuevoNodo;
    *cabeza = nuevoNodo;
    return;
  }

  do
  {
    if (dato <= actual->sig->dato && actual->sig != *cabeza)
    {
      nuevoNodo->sig = actual->sig;
      nuevoNodo->ant = actual;
      actual->sig->ant = nuevoNodo;
      actual->sig = nuevoNodo;
      return;
    }
    actual = actual->sig;
  } while (actual != *cabeza);

  nuevoNodo->sig = *cabeza;
  nuevoNodo->ant = actual->ant;
  actual->ant->sig = nuevoNodo;
  (*cabeza)->ant = nuevoNodo;
}

void mostrarAdelante(struct Nodo *cabeza)
{
  if (cabeza == NULL)
  {
    printf("Lista vacia\n");
    return;
  }
  struct Nodo *actual = cabeza;
  printf("Lista hacia adelante: ");
  do
  {
    printf("%d ", actual->dato);
    actual = actual->sig;
  } while (actual != cabeza);
  printf("\n");
}

void mostrarAtras(struct Nodo *cabeza)
{
  if (cabeza == NULL)
  {
    printf("Lista vacia\n");
    return;
  }
  struct Nodo *actual = cabeza->ant;
  printf("Lista hacia atras: ");
  do
  {
    printf("%d ", actual->dato);
    actual = actual->ant;
  } while (actual != cabeza->ant);
  printf("\n");
}

int main()
{
  struct Nodo *lista = NULL;
  int opcion, dato;

  do
  {
    printf("\n--- Lista Circular Doblemente Enlazada ---\n");
    printf("1. Insertar numero ordenadamente\n");
    printf("2. Mostrar lista hacia adelante\n");
    printf("3. Mostrar lista hacia atras\n");
    printf("4. Salir\n");
    printf("Ingrese opcion: ");
    if (scanf("%d", &opcion) != 1)
    {
      while (getchar() != '\n')
        ;
      opcion = 0;
      continue;
    }

    switch (opcion)
    {
    case 1:
      printf("Ingrese el numero a insertar: ");
      if (scanf("%d", &dato) == 1)
      {
        insertarOrdenado(&lista, dato);
      }
      else
      {
        printf("Entrada invalida\n");
        while (getchar() != '\n')
          ;
      }
      break;
    case 2:
      mostrarAdelante(lista);
      break;
    case 3:
      mostrarAtras(lista);
      break;
    case 4:
      printf("Saliendo del programa.\n");
      break;
    default:
      printf("Opcion no valida. Intente de nuevo.\n");
    }
  } while (opcion != 4);

  return 0;
}