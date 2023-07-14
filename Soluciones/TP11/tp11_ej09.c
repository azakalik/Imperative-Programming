#include <stdlib.h>
#include "setADT.h"
#define MAX 50

static listADT lists[MAX] = {NULL};

struct listCDT {
	nodeP first;
	unsigned int size;
  nodeP  next;
};

int 
newList() {
	int i;
	listADT list;
	for (i = 0; i < MAX && lists[i] != NULL; i++);

 	if ( i==MAX )    // No hay espacio para nuevas listas
     return -1;
	
	list = calloc(1, sizeof(struct listCDT));
	if ( list == NULL )
		return -1;

	lists[i] = list;
	return i;
}

void 
freeList(unsigned int list) {
	listADT aux = lists[list];   // Asumimos un índice válido

	nodeP curr=list->first, aux;

	while (curr != NULL) {
		aux = curr->tail;
		free(curr);
		curr = aux;
	}
	free(list);
	lists[i] = NULL;
}

int 
isEmpty(unsigned int list) {
	return listIsEmpty(lists[list]);    // Asumimos un índice válido
}
