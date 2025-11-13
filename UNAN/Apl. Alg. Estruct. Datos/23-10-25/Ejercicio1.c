#include <stdio.h>
#include <stdlib.h>

#define ASCENDENTE 1
#define DESCENDENTE 0

typedef struct _nodo
{
	int valor;
	struct _nodo *siguiente;
	struct _nodo *anterior;
} tipoNodo;
typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;
/* Funciones con listas: */
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
void BorrarLista(Lista *);
void MostrarLista(Lista l, int orden);

int main()
{
	Lista lista = NULL;
	Lista lista_diez = NULL;
	pNodo p;
	int i;

	/* Prueba original */
	Insertar(&lista, 20);
	Insertar(&lista, 10);
	Insertar(&lista, 40);
	Insertar(&lista, 30);
	printf("--- PRUEBA ORIGINAL ---\n");
	MostrarLista(lista, ASCENDENTE);
	MostrarLista(lista, DESCENDENTE);
	Borrar(&lista, 10);
	Borrar(&lista, 15);
	Borrar(&lista, 45);
	Borrar(&lista, 30);
	MostrarLista(lista, ASCENDENTE);
	MostrarLista(lista, DESCENDENTE);
	BorrarLista(&lista);

	/* Nueva prueba: Lista del 10 al 100 de diez en diez */
	printf("\n--- NUEVA PRUEBA: LISTA 10 AL 100 ---\n");
	for (i = 10; i <= 100; i += 10)
	{
		Insertar(&lista_diez, i);
	}

	printf("Lista de 10 a 100 insertada:\n");
	MostrarLista(lista_diez, ASCENDENTE);
	MostrarLista(lista_diez, DESCENDENTE);

	BorrarLista(&lista_diez);

	return 0;
}

void Insertar(Lista *lista, int v)
{
	pNodo nuevo, actual;
	/* Crear un nodo nuevo */
	nuevo = (pNodo)malloc(sizeof(tipoNodo));
	if (nuevo == NULL)
		return; /* Manejo de error de memoria */
	nuevo->valor = v;

	/* Colocamos actual en la primera posicion de la lista (el nodo con anterior NULL) */
	actual = *lista;
	if (actual)
		while (actual->anterior)
			actual = actual->anterior;

	/* Si la lista esta vacia o el primer miembro es mayor que el nuevo
	 */
	if (!actual || actual->valor > v)
	{
		/* Anadimos la lista a continuacion del nuevo nodo */
		nuevo->siguiente = actual;
		nuevo->anterior = NULL;
		if (actual)
			actual->anterior = nuevo;
		/* El nuevo nodo es ahora el que no tiene anterior, asi que *lista debe apuntar a el */
		*lista = nuevo;
	}
	else
	{
		/* Avanzamos hasta el ultimo elemento o hasta que el siguiente tenga un valor mayor que v */
		while (actual->siguiente && actual->siguiente->valor <= v)
			actual = actual->siguiente;
		/* Insertamos el nuevo nodo despues del nodo anterior */
		nuevo->siguiente = actual->siguiente;
		actual->siguiente = nuevo;
		nuevo->anterior = actual;
		if (nuevo->siguiente)
			nuevo->siguiente->anterior = nuevo;
	}
}

void Borrar(Lista *lista, int v)
{
	pNodo nodo;

	/* Buscar el nodo de valor v */
	nodo = *lista;
	/* Nos movemos al inicio de la lista para buscar correctamente */
	while (nodo && nodo->anterior)
		nodo = nodo->anterior;

	/* Busqueda hacia adelante */
	while (nodo && nodo->valor != v)
		nodo = nodo->siguiente;

	/* El valor v no esta en la lista */
	if (!nodo)
		return;

	/* Borrar el nodo */
	/* Si lista apunta al nodo que queremos borrar, apuntar a otro */
	if (nodo == *lista)
	{
		if (nodo->anterior)
			*lista = nodo->anterior;
		else
			*lista = nodo->siguiente;
	}
	/* Si *lista es NULL despues del borrado, no es necesario hacer mas porque se maneja en las siguientes condiciones */

	if (nodo->anterior) /* no es el primer elemento */
		nodo->anterior->siguiente = nodo->siguiente;
	if (nodo->siguiente) /* no es el ultimo nodo */
		nodo->siguiente->anterior = nodo->anterior;

	/* Si el nodo borrado era el unico y *lista se puso a NULL, free(nodo) es lo ultimo */
	if (!nodo->anterior && !nodo->siguiente && *lista == nodo)
		*lista = NULL;

	free(nodo);
}

void BorrarLista(Lista *lista)
{
	pNodo nodo, actual;
	if (!*lista)
		return;

	/* Ir al inicio de la lista */
	actual = *lista;
	while (actual->anterior)
		actual = actual->anterior;

	while (actual)
	{
		nodo = actual;
		actual = actual->siguiente;
		free(nodo);
	}
	*lista = NULL;
}

void MostrarLista(Lista lista, int orden)
{
	pNodo nodo = lista;
	if (!lista)
	{
		printf("Lista vacia\n");
		return;
	}

	/* Ir al inicio o fin de la lista */
	if (orden == ASCENDENTE)
	{
		while (nodo->anterior)
			nodo = nodo->anterior;
		printf("Orden ascendente: ");
		while (nodo)
		{
			printf("%d -> ", nodo->valor);
			nodo = nodo->siguiente;
		}
	}
	else /* DESCENDENTE */
	{
		while (nodo->siguiente)
			nodo = nodo->siguiente;
		printf("Orden descendente: ");
		while (nodo)
		{
			printf("%d -> ", nodo->valor);
			nodo = nodo->anterior;
		}
	}

	printf("NULL\n"); /* Indica el final de la lista */
}