#include <stdlib.h>
#include "utillist.h"

/**
** No puede ser void porque se puede insertar delante
*/
TList addAll(TList lista1,  TList lista2) {
  if (lista2 == NULL)                             // Nada para agregar
     return lista1;
  if (lista1 == NULL || lista1->elem > lista2->elem) {
    TList aux = malloc(sizeof(TNode));
    aux->elem = lista2->elem;
    aux->tail = addAll(lista1, lista2->tail);
    return aux;
  }
  if (lista1->elem < lista2->elem)
     lista1->tail = addAll(lista1->tail, lista2);
  else
     lista1->tail = addAll(lista1->tail, lista2->tail);
  return lista1;
}



// Un error bastante común es resolverlo de la siguiente forma
TList addAllWrong(TList lista1,  TList lista2) {
  if (lista2 == NULL)
     return lista1;
  if ( lista1 == NULL)                           // Quiero agregar los elementos de lista2
     return lista2;
  if (lista1->elem > lista2->elem) {
    TList aux = malloc(sizeof(TNode));
    aux->elem = lista2->elem;
    aux->tail = addAllWrong(lista1, lista2->tail);
    return aux;
  }
  if (lista1->elem < lista2->elem)
     lista1->tail = addAllWrong(lista1->tail, lista2);
  else
     lista1->tail = addAllWrong(lista1->tail, lista2->tail);
  return lista1;
}
// El error cometido es que los nodos de lista2 se deben agregar a lista1, y lo que estamos
// haciendo acá es "enganchar" las dos listas. El último elemento de lista1 termina apuntando
// a un nodo de lista2, por lo que cambios en una lista repercuten en la otra. O si libero lista1
// también estaría liberando parte de lista2
