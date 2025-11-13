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
    return;
  }
  struct NodoSimple *actual = *cabeza;
  while (actual->sig != NULL)
  {
    actual = actual->sig;
  }
  actual->sig = nuevoNodo;
}

void mostrarLista(struct NodoSimple *cabeza)
{
  struct NodoSimple *actual = cabeza;
  while (actual != NULL)
  {
    printf("%d -> ", actual->dato);
    actual = actual->sig;
  }
  printf("NULL\n");
}

int detectarCiclo(struct NodoSimple *cabeza)
{
  struct NodoSimple *lenta = cabeza;
  struct NodoSimple *rapida = cabeza;

  while (rapida != NULL && rapida->sig != NULL)
  {
    lenta = lenta->sig;
    rapida = rapida->sig->sig;
    if (lenta == rapida)
    {
      return 1;
    }
  }
  return 0;
}

void romperCiclo(struct NodoSimple *cabeza)
{
  if (cabeza == NULL || cabeza->sig == NULL)
  {
    return;
  }

  struct NodoSimple *lenta = cabeza;
  struct NodoSimple *rapida = cabeza;
  int cicloDetectado = 0;

  while (rapida != NULL && rapida->sig != NULL)
  {
    lenta = lenta->sig;
    rapida = rapida->sig->sig;
    if (lenta == rapida)
    {
      cicloDetectado = 1;
      break;
    }
  }

  if (cicloDetectado)
  {
    struct NodoSimple *ptr1 = cabeza;
    struct NodoSimple *ptr2 = lenta;

    while (ptr1 != ptr2)
    {
      ptr1 = ptr1->sig;
      ptr2 = ptr2->sig;
    }

    while (ptr2->sig != ptr1)
    {
      ptr2 = ptr2->sig;
    }

    ptr2->sig = NULL;
    printf("Ciclo roto exitosamente.\n");
  }
  else
  {
    printf("No se detecto ningun ciclo.\n");
  }
}

int main()
{
  struct NodoSimple *lista = NULL;

  insertarAlFinal(&lista, 10);
  insertarAlFinal(&lista, 20);
  insertarAlFinal(&lista, 30);
  insertarAlFinal(&lista, 40);
  insertarAlFinal(&lista, 50);
  insertarAlFinal(&lista, 60);

  struct NodoSimple *cuartoNodo = lista->sig->sig->sig;
  struct NodoSimple *ultimoNodo = lista->sig->sig->sig->sig->sig;

  ultimoNodo->sig = cuartoNodo;
  printf("Lista creada y ciclo generado (60 -> 40).\n");

  printf("\n1. Detectando ciclo...\n");
  if (detectarCiclo(lista))
  {
    printf("Ciclo detectado (Algoritmo de Floyd).\n");

    printf("\n2. Rompiendo ciclo...\n");
    romperCiclo(lista);

    printf("\n3. Lista final sin el ciclo:\n");
    mostrarLista(lista);
  }
  else
  {
    printf("No se detecto ciclo.\n");
    printf("\nLista final:\n");
    mostrarLista(lista);
  }

  return 0;
}