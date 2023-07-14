#include <stdlib.h>


// Como el primero no se elimina, puede ser void
void order (TList list) {
  if (list == NULL || list->tail == NULL)
      return;
  if ( list->elem >= list->tail->elem) {
    TList auxToFree = list->tail;
    list->tail = auxToFree->tail;
    free(auxToFree);
    
    // Seguimos procesando list, puede que siga desordenada
    order(list);
  } else {
    order(list->tail);
  }
}
