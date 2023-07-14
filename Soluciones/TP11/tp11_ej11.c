#include "tp11_ej11.h"
#include <stdlib.h>


// En esta versión mantenemos un vector paralelo indicando si cada uno está libre o no
// Otra posibilidad hubiese sido definir una estructura con el elemento y la marca
// struct pos{
//     elemType elem;
//     char isEmpty;
// }
//
// typedef struct vectorCDT{
//     struct pos * elems;
//     size_t dim;
//     size_t used_spaces;
// }vectorCDT;
// Una desventaja es que ocupa más memoria porque desperdicia 3 bytes por cada elemento

// Una tercera posibilidad es usar un vector de punteros a elemType
// Tiene como desventaja que por cada elemento se crea además un puntero (4 u 8 bytes), pero sería
// más eficiente en memoria si el porcentaje de ocupación del vector es bajo y elemType es una estructura con 
// una cantidad considerable de bytes.

typedef struct vectorCDT{
    elemType * elems;
    char * isEmpty;    // isEmpty[i] == 1 si elems[i] esta libre, 0 si no está libre
    size_t dim;
    size_t used_spaces;
    int (*compare)(elemType source, elemType target);   // Función de comparación
}vectorCDT;

vectorADT newVector(int (*compare)(elemType source, elemType target)){
    vectorADT ans = calloc(1, sizeof(vectorCDT));
    ans->compare = compare;
    return ans;
}

void freeVector(vectorADT v){
    if(v!=NULL){
        free(v->elems);
        free(v->isEmpty);
    }
    free(v);
    return;
}

size_t put(vectorADT v, elemType * elems, size_t dim, size_t index){
    if(elems==NULL)
        return 0;
    if(dim+index > v->dim){
        v->elems=realloc(v->elems, sizeof(elemType)*(dim + index));

        v->isEmpty=realloc(v->isEmpty, sizeof(char)*(dim + index));

        for(size_t i=v->dim; i< dim + index; i++)
            v->isEmpty[i] = 1;
        v->dim = dim + index;
    }
    size_t count=0;
    for(size_t i=index, j=0; i < index+dim; i++, j++){
        if(v->isEmpty[i]){
            v->elems[i]=elems[j];
            v->isEmpty[i]=0;
            count++;
            v->used_spaces++;
        }
    }
    return count;
}

int getIdx(vectorADT v, elemType elem){
    for(size_t i=0; i < v->dim; i++){
        if(! v->isEmpty[i] && v->compare(v->elems[i], elem)==0) {
                return i;
            }
        }
    return -1;
}

void deleteElement(vectorADT v, size_t index){
    if(index>=v->dim)
        return;
    if(! v->isEmpty[index]){
        v->isEmpty[index] = 1;
        v->used_spaces--;
    }
    return;
}

int elementCount(vectorADT v){
    return v->used_spaces;
}