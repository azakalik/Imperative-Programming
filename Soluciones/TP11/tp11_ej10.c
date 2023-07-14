/*
 * bagADT.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp11_ej10.h"

// Si bien no pide orden, como usamos una lista es más eficiente guardarlos ordenados
// También se podría haber usado un vector, guardando cada elemento nuevo al final (en caso de usar
// un vector no sería eficiente mantenerlo ordenado, salvo que nos aseguren que habrá pocas modificaciones
// y muchas búsquedas puntuales, y en ese caso usaremos búsqueda binaria).
// En cualquiera de los dos casos, lo importante es en no repetir elementos sino tener un contador
// de repeticiones de cada uno. 
// Una variante más simple de implementaar sería un vector donde cada vez que agrego un elemento lo inserto al final, sin 
// importar si ya estaba o no. Mas allá de la ineficiencia en espacio, pensar cómo sería implementar la función
// mostPopular con esa estructura.
struct node {
	elemType head;
	unsigned int count;
	struct node * tail;
};

typedef struct node * nodeP;

struct bagCDT {
	nodeP first;
	unsigned int size;
	compare cmp;
};


bagADT
newBag( compare cmp ) {
	bagADT bag = calloc(1, sizeof(struct bagCDT));
	bag->cmp = cmp;
	return bag;
}


static unsigned int countRec(nodeP first, elemType elem, compare cmp) {
	int c;

    // Aprovechamos que está ordenado, y cortamos antes si encontramos uno mayor
	if(first == NULL || (c=cmp(first->head, elem)) > 0)
		return 0;
	
	if ( c == 0 )
		return first->count;

	return countRec( first->tail, elem, cmp);
}


unsigned int
count( const bagADT bag, elemType elem) {
    // También se podría implementar en forma iterativa
	return countRec(bag->first, elem, bag->cmp);
}


static nodeP addRec(nodeP first, elemType elem, int * countElem, compare cmp) {
	int c;
	if( first == NULL || (c=cmp(first->head, elem)) > 0 ) {
		nodeP aux = malloc(sizeof( struct node ));

		aux->tail = first;
		aux->head = elem;
		aux->count = 1;
		*countElem = 1;
		return aux;
	}

	if( c < 0 )
		first->tail = addRec( first->tail, elem, countElem, cmp);
	else
		*countElem = ++(first->count);
	return first;
}

unsigned int
add( bagADT bag, elemType element) {
	int countElem ;
	bag->first = addRec(bag->first, element, &countElem, bag->cmp);
	if (countElem == 1)	// es el primero
		bag->size++;
	return countElem;
}



void
freeBag( bagADT bag) {
	nodeP curr = bag->first, aux;

	while (curr != NULL) {
		aux = curr->tail;
		free(curr);
		curr = aux;
	}
	free(bag);
}

unsigned int
size(const bagADT bag) {
	return bag->size;
}
 

// El algoritmo es el mismo que buscar el mayor valor en una colección no ordenada,
// solo que el valor a comparar es la cantidad de repeticiones.
elemType mostPopular(const bagADT bag) {
	elemType ans;
	if ( bag->size == 0) {
		fprintf(stderr, "El bag no debe estar vacío\n");
        exit(1);
	}
	else {
		nodeP aux = bag->first;
		int cant = aux->count;
		ans = aux->head;
		aux = aux->tail;
		while ( aux != NULL ) {
			if ( aux->count > cant ) {
				ans = aux->head;
				cant = aux->count;
			}
			aux = aux->tail;
		}
	}
	return ans;
}
