#include <stdlib.h>
#include "utillist.h"

typedef struct nodeBrief * TListBrief; 

typedef struct nodeBrief {
		int elem;
		size_t count;
		struct nodeBrief * tail;
} TNodeBrief;


TListBrief comprimeList(const TList list) {
    // El caso base es simple: si la lista está vacía, entonces la lista abreviada es una lista vacía
	if ( list == NULL) {
		return NULL;
	}
		
    // Primero pedimos que nos comprima la sublista (como funciona para el caso base,
    // sabemos que va a funcionar para una lista más corta, porque tiende al caso base)
	TListBrief bl = comprimeList(list->tail);
	
	// Ahora ya sabemos que bl es la "tail""de list abreviada.
    // Debemos comparar el header de list con el header de la sublista abreviada
    // Si son iguales, incrementamos la cantidad de repeticiones, sinó agregamos el nodo a la
    // sublista comprimida
	if ( bl == NULL || list->elem < bl->elem) {
		TListBrief aux = malloc(sizeof(TNodeBrief));   // El nuevo header de la sublista abreviada
		aux->elem = list->elem;
		aux->count = 1;
		aux->tail = bl;
		return aux;
	}
	// Si no es menor, entonces es igual
	bl->count++;
	return bl;
}
