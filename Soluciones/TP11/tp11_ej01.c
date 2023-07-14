#include <stdlib.h>

typedef struct node * TList; 

typedef struct node {
		int elem;
		struct node * tail;
} TNode;
	

TList removeIf (TList list, int (*criteria)(int)) {
  if (list == NULL)
     return NULL;
  // Hay que borrarlo ?
  if (criteria(list->elem)) {
    TList aux = list->tail;
    free(list);
    return removeIf(aux, criteria);
  }
  // La lista no cambia, pero tal vez si la sublista
  list->tail = removeIf(list->tail, criteria);
  return list;
}