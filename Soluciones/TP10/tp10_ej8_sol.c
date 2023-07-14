#include <stdlib.h>
#include "utillist.h"
	

TList listUnion  (const TList list1, const TList list2) {
  if (list1 == NULL && list2 == NULL)
     return NULL;
  // Condiciones para saber si debemos copiar el de lista 1 ?
  if (list2==NULL || list1 != NULL && list1->elem < list2->elem) {
    TList aux = malloc(sizeof(TNode));
    aux->elem = list1->elem;
    aux->tail = listUnion(list1->tail, list2);
    return aux;
  }
  // Copiamos de lista 2 ? ( ya sabemos que list2 no es NULL, o hubiese sido verdadero
  // el if anterior )
  if (list1==NULL || list1->elem > list2->elem) {
    TList aux = malloc(sizeof(TNode));
    aux->elem = list2->elem;
    aux->tail = listUnion(list1, list2->tail);
    return aux;
  }
  // Son iguales
  TList aux = malloc(sizeof(TNode));
  aux->elem = list1->elem;
  aux->tail = listUnion(list1->tail, list2->tail);
  return aux;
}

// En la solución anterior estamos repitiendo el malloc en todos los casos.
// Si el primer if es falso ( al menos uno de los dos no es una lista vacía)
// entonces sabemos que vamos a crear un nodo, por lo que podemos hacer el malloc
// antes de determinar cuál vamos a copiar


TList listUnion2  (const TList list1, const TList list2) {
  if (list1 == NULL && list2 == NULL)
     return NULL;
  // Para simplificar casos, si lista1 es NULL, invertimos los parametros
  if ( list1 == NULL)
     return listUnion2(list2, list1);
  // Sí o sí se va a crear uno nuevo
  TList aux = malloc(sizeof(TNode));

  // Copiamos el de lista 1 ?
  if (list2==NULL || list1->elem < list2->elem) {
    aux->elem = list1->elem;
    aux->tail = listUnion2(list1->tail, list2);
  }
  // Copiamos de lista 2 ?
  // Ya sabemos que ni list1 ni list2 son NULL
  else if (list1->elem > list2->elem) {
    aux->elem = list2->elem;
    aux->tail = listUnion2(list1, list2->tail);
  } else {   // Son iguales
    aux->elem = list1->elem;
    aux->tail = listUnion2(list1->tail, list2->tail);
  }
  return aux;
}