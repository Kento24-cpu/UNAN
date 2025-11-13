#include <stdio.h>
#include <stdlib.h>

struct NodoSimple
{
  int dato;
  struct NodoSimple *sig;
};

struct NodoSimple *crearNodoSimple(int dato)
{
  struct NodoSimple *nuevoNodo = (struct NodoSimple *)malloc(sizeof(struct NodoSimple));
  if (nuevoNodo == NULL)
  {
    printf("Error de asignacion de memoria\n");
    exit(1);
  }
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;
  return nuevoNodo;
}

void insertarAlFinal(struct NodoSimple **cabeza, int dato)
{
  struct NodoSimple *nuevoNodo = crearNodoSimple(dato);
  if (*cabeza == NULL)
  {
    *cabeza = nuevoNodo;
    (*cabeza)->sig = *cabeza;
    return;
  }
  struct NodoSimple *ultimo = *cabeza;
  while (ultimo->sig != *cabeza)
  {
    ultimo = ultimo->sig;
  }
  ultimo->sig = nuevoNodo;
  nuevoNodo->sig = *cabeza;
}

void mostrarListaCircular(struct NodoSimple *cabeza)
{
  if (cabeza == NULL)
  {
    printf("Lista vacia\n");
    return;
  }
  struct NodoSimple *actual = cabeza;
  do
  {
    printf("%d -> ", actual->dato);
    actual = actual->sig;
  } while (actual != cabeza);
  printf("(Inicio)\n");
}

void dividirListaCircular(struct NodoSimple *cabeza, struct NodoSimple **cabeza1, struct NodoSimple **cabeza2)
{
  if (cabeza == NULL || cabeza->sig == cabeza)
  {
    *cabeza1 = cabeza;
    *cabeza2 = NULL;
    return;
  }

  struct NodoSimple *lenta = cabeza;
  struct NodoSimple *rapida = cabeza->sig;

  while (rapida != cabeza && rapida->sig != cabeza)
  {
    lenta = lenta->sig;
    rapida = rapida->sig->sig;
  }

  *cabeza1 = cabeza;
  *cabeza2 = lenta->sig;

  struct NodoSimple *ultimo1 = lenta;
  struct NodoSimple *ultimo2 = *cabeza2;

  while (ultimo2->sig != cabeza)
  {
    ultimo2 = ultimo2->sig;
  }

  ultimo1->sig = *cabeza1;
  ultimo2->sig = *cabeza2;
}

int main()
{
  struct NodoSimple *original = NULL;
  struct NodoSimple *primeraMitad = NULL;
  struct NodoSimple *segundaMitad = NULL;

  insertarAlFinal(&original, 1);
  insertarAlFinal(&original, 2);
  insertarAlFinal(&original, 3);
  insertarAlFinal(&original, 4);
  insertarAlFinal(&original, 5);
  insertarAlFinal(&original, 6);
  insertarAlFinal(&original, 7);

  printf("1. Lista Original:\n");
  mostrarListaCircular(original);

  dividirListaCircular(original, &primeraMitad, &segundaMitad);

  printf("\n2. Primera Mitad:\n");
  mostrarListaCircular(primeraMitad);

  printf("\n3. Segunda Mitad:\n");
  mostrarListaCircular(segundaMitad);

  return 0;
}