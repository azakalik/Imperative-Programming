#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

/**
** En esta versión dejamos el primer elemento de una secuencia de repetidos
** Puede ser void porque el head de la lista no cambia
*/
void deleteDupl (TList list) {
  // Una lista vacía o de un elemento no tiene duplicados
  if (list == NULL || list->tail == NULL)
     return ;
  if (list->elem == list->tail->elem) {
    // borramos tail
    TList aux = list->tail;
    list->tail = aux->tail;
    free(aux);
    // error común: invocar con list->tail: si hay 3 seguidos solo borra el del medio
    deleteDupl(list);
    return;
  }
  // Eliminamos duplicados en la sublista
  deleteDupl(list->tail);
}

/*
** Dejamos el último de una secuencia de repetidos, por lo que la lista puede cambiar ( o sea,
** el que era el primero ya no está, necesito saber quién es el "nuevo primero")
*/ 
TList deleteDupl2 (TList list) {
  // Una lista vacía o de un elemento no tiene duplicados
  if (list == NULL || list->tail == NULL)
     return list;
  // Como funciona el caso base, funciona para una lista de menor longitud
  // Pedimos entonces que elimine duplicados de la sublista
  list->tail = deleteDupl2(list->tail);
  if ( list->elem == list->tail->elem) {
     TList aux = list->tail;
     free(list);
     return aux;
  }
  // No es igual al header de la sublista
  return list;
}

// Una version mas "elegante"
TList deleteDupl3 (TList list) {
  // Una lista vacía o de un elemento no tiene duplicados
  if (list == NULL || list->tail == NULL)
     return list;
  // Como funciona el caso base, funciona para una lista de menor longitud
  // Pedimos entonces que elimine duplicados de la sublista
  TList aux = deleteDupl3(list->tail);
  if ( list->elem == aux->elem) {
     free(list);
     return aux;
  }
  list->tail = aux;
  return list;
}

