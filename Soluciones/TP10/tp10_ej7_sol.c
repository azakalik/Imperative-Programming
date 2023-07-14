#include <stdlib.h>
#include "utillist.h"
	
TList listIntersec  (const TList list1, const TList list2) {
  if (list1 == NULL || list2 == NULL)
     return NULL;
  // Son iguales ?
  if (list1->elem == list2->elem) {
    TList aux = malloc(sizeof(TNode));
    aux->elem = list1->elem;
    aux->tail = listIntersec(list1->tail, list2->tail);
    return aux;
  }
  if (list1->elem > list2->elem) {
    return listIntersec(list1, list2->tail);
  }
  return listIntersec(list1->tail, list2);
}
