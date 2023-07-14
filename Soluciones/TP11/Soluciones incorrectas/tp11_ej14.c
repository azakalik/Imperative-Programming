#include "tp11_ej14.h"
#include <stdlib.h>

#define ASCENDENTE 1
#define INDICE 0

typedef struct TNode
{
    elemType elem;
    struct TNode *next;
} TNode;

typedef TNode *TList;

typedef struct listCDT
{
    TList firstAsc;
    TList firstIdx;

    TList currentAsc;
    TList currentIdx;
} listCDT;

listADT newList() { return calloc(1, sizeof(listCDT)); }

static TNode *createNode(TList myList, elemType elem)
{
    TList newNode = malloc(sizeof(TNode));
    newNode->next = myList;
    newNode->elem = elem;
    return newNode;
}

static TList addRec(TList myList, elemType elem, int version)
{
    int c;
    if (myList == NULL)
        return createNode(myList, elem);
    if (version)
    {
        if ((c = compare(elem, myList->elem)) < 0)
            return createNode(myList, elem);
        if (c == 0)
            return myList;
    }
    myList->next = addRec(myList->next, elem, version);
    return myList;
}

void add(listADT list, elemType elem)
{
    list->firstAsc = addRec(list->firstAsc, elem, ASCENDENTE);
    list->firstIdx = addRec(list->firstIdx, elem, INDICE);
}

void removeElem(listADT list, elemType elem);

void toBegin(listADT list) { list->currentIdx = list->firstIdx; }
int hasNext(listADT list) { return list->currentIdx != NULL; }
elemType next(listADT list)
{
    if (!hasNext(list))
        exit(1);
    elemType aux = list->currentIdx->elem;
    list->currentIdx = list->currentIdx->next;
    return aux;
}

void toBeginAsc(listADT list) { list->currentAsc = list->firstAsc; }
int hasNextAsc(listADT list) { return list->currentAsc != NULL; }
elemType nextAsc(listADT list)
{
    if (!hasNextAsc(list))
        exit(1);
    elemType aux = list->currentAsc->elem;
    list->currentAsc = list->currentAsc->next;
    return aux;
}

void freeRec(TList list)
{
    if (list == NULL)
        return;
    freeRec(list->next);
    free(list);
}

void freeList(listADT list)
{
    freeRec(list->firstAsc);
    freeRec(list->firstIdx);
    free(list);
}
