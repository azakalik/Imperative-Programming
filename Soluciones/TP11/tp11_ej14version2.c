#include <stdlib.h>
#include <stdio.h>
#include "tp11_ej14.h"
/*
 * Esta solución evita tener que duplicar los nodos.
 * Para eso usa dos punteros tail en cada nodo:
 * uno que sigue el orden ascendente y otro guarda el orden de inserción
 * No se puede usar un solo tail, porque estaríamos en un momento 
 * apuntando al siguiente ascendente y luego lo cambiaría al siguiente por orden de inserción.
*/
typedef struct listCDT {
    struct node * firstAsc;     // primero en orden ascendente
    struct node * firstInsert;
    struct node * lastInsert;
    struct node * iterAsc;      // para iterar en orden ascendente
    struct node * iterInsert;
    int (*compare) (elemType e1, elemType e2); // función de comparación
} listCDT;

typedef struct node {
  elemType elem;
  struct node * tailasc;        // para seguir el orden ascendente
  struct node * tailins;        // para seguir el orden de insercion
} node;


listADT newList(int (*compare) (elemType e1, elemType e2))
{
 listADT ans = calloc(1,sizeof(listCDT));
 ans->compare = compare;
 return ans;
}

struct node *
nuevoNodo(elemType elem)
{
    struct node*aux = malloc(sizeof(struct node));
    aux->elem = elem;
    aux->tailasc = NULL;
    aux->tailins = NULL;
    return aux;
}
void add(listADT list, elemType elem)
{
    struct node *aux;
    if (list->firstInsert == NULL || list->compare(list->firstAsc->elem,elem)>0)
    {
        aux = nuevoNodo(elem);
        aux->tailasc = list->firstAsc;
        list->firstAsc = aux;
        if (list->firstInsert == NULL)
        {
            list->firstInsert = aux;
            list->lastInsert = aux;
        }
        else
        {
            list->lastInsert->tailins = aux;
            list->lastInsert= aux;
        }
        return;
    }

    struct node *iter = list->firstAsc;
    while (iter->tailasc!=NULL && (list->compare(iter->tailasc->elem,elem)<0))
    {
        iter = iter->tailasc;
    }
    aux = nuevoNodo(elem);
    aux->tailasc = iter->tailasc;
    iter->tailasc = aux;
    list->lastInsert->tailins = aux;
    list->lastInsert = aux;
    return;
}

void toBegin(listADT list)
{
    list->iterInsert = list->firstInsert;
}

int hasNext(listADT list)
{
    return (list->iterInsert !=  NULL);
}

elemType next(listADT list) {
  if ( !hasNext(list)) {
    fprintf(stderr, "Invalid use of iterator");
  }
  elemType toReturn = list->iterInsert->elem;
  list->iterInsert = list->iterInsert->tailins;
  return toReturn;
}

void toBeginAsc(listADT list)
{
    list->iterAsc = list->firstAsc;
}

int hasNextAsc(listADT list)
{
    return (list->iterAsc !=  NULL);
}
elemType nextAsc(listADT list)
{
    if ( !hasNextAsc(list)) {
    fprintf(stderr, "Invalid use of iterator");
    }
    elemType aux = list->iterAsc->elem;
    list->iterAsc = list->iterAsc->tailasc;
    return aux;
}

/* Libera la memoria reservada por la lista
 Se puede seguir cualquier orden. Es lo mismo, porque los nodos liberados son únicos.
 Si se sigue tailasc, liberará en forma ascendente todos los nodos
 Si se sigue tailins, liberará en forma insertada todos los nodos
 Pero de cualquier forma libera todos los nodos.
*/

void freeRec(node * first) {
  if ( first == NULL)
    return;
  freeRec(first->tailasc);
  free(first);
}

void freeList(listADT list) {
  freeRec(list->firstAsc);
  free(list);
}
