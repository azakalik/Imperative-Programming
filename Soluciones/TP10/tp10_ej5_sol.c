#include <stdlib.h>
#include "utillist.h"

TList restaList(TList lista1,  TList lista2){
    if (lista1 == NULL){ 
        return NULL;
    }
    if (lista2 == NULL || lista1->elem < lista2->elem){ 
        TList aux = malloc(sizeof(TNode));
        aux-> elem = lista1-> elem;
        aux-> tail = restaList(lista1->tail, lista2);
        return aux;
    }
    if (lista1->elem > lista2->elem){ 
        return restaList(lista1, lista2->tail);
    } 
    // Son iguales
    return restaList(lista1->tail, lista2->tail); 
}
