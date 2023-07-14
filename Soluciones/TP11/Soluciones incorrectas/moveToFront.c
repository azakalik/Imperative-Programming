// El problema es que no pasa el test

#include <stdlib.h>
#include <stdio.h>
#include "moveToFront.h"


typedef struct TNode {
    elemType elem;
    struct TNode* tail;
} TNode;

typedef struct moveToFrontCDT {
    TNode* head;
    TNode* current;
    size_t dim;     //Cantidad de elementos
} moveToFrontCDT;


/* Retorna un nuevo conjunto de elementos genéricos. Al inicio está vacío */
moveToFrontADT newMoveToFront() {
    return calloc(1, sizeof(moveToFrontCDT));
}

//------------------FREE------------------
void freeRec(TNode* node) {
    if (node == NULL) {
        return;
    }
    freeRec(node->tail);
    free(node);
}

void freeMoveToFront(moveToFrontADT moveToFront) {
    freeRec(moveToFront->head);
    free(moveToFront);
}
 
//------------------ADD------------------
TNode* addRec(TNode* head, elemType elem, int* added) {
    if (head == NULL) {
        TNode* node = malloc(sizeof(TNode));
        node->tail = NULL;
        node->elem = elem;
        *added = 1;
        return node;
    }
    if (compare(head->elem, elem) == 0) {
        return head;
    }
    head->tail = addRec(head->tail, elem, added);
    return head;
}

/* Inserta un elemento si no está. Lo inserta al final.
** Retorna 1 si lo agregó, 0 si no.
*/
unsigned int add(moveToFrontADT moveToFront, elemType elem) {
    int added = 0;
    moveToFront->head = addRec(moveToFront->head, elem, &added);
    moveToFront->dim += added;
    return added;
}

//------------------SIZE------------------
 
/* Retorna la cantidad de elementos que hay en la colección */
unsigned int size(moveToFrontADT moveToFront) {
    return moveToFront->dim;
}
 
/* Se ubica al principio del conjunto, para poder iterar sobre el mismo */
void toBegin(moveToFrontADT moveToFront) {
    moveToFront->current = moveToFront->head;
}

/* Retorna 1 si hay un elemento siguiente en el iterador, 0 si no */
int hasNext(moveToFrontADT moveToFront) {
    return moveToFront->current != NULL;
}

/* Retorna el siguiente elemento. Si no hay siguiente elemento, aborta */
elemType next(moveToFrontADT moveToFront) {
    if (!hasNext(moveToFront)) {
        exit(1);
    }
    elemType e = moveToFront->current->elem;
    moveToFront->current = moveToFront->current->tail;
    return e;
}

//------------------GET------------------
//Si lo encuentro, devuelvo ese nodo y enlazo el anterior con el siguiente al nodo encontrado.
TNode* getRec(TNode* node, elemType elem, TNode** foundedNode) {
    if (node == NULL) {
        return NULL;
    }
    if ( compare(node->elem, elem) == 0) {
        *foundedNode = node;
        return node->tail;
    }
    node->tail = getRec(node->tail, elem, foundedNode);
    return node;
}

/* Retorna una copia del elemento. Si no existe retorna NULL.
** Para saber si el elemento está, usa la función compare. 
** Si el elemento estaba lo ubica al principio.
*/
elemType * get(moveToFrontADT moveToFront, elemType elem) {
    TNode* foundedNode = NULL;

    moveToFront->head = getRec(moveToFront->head, elem, &foundedNode);

    if (foundedNode != NULL) {
        TNode* aux = moveToFront->head;
        moveToFront->head = foundedNode;
        foundedNode->tail = aux;
    
        elemType* copy = malloc(sizeof(elemType));
        *copy = elem;
        return copy;
    }
    return NULL;
}