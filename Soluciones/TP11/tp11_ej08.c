#include <stdlib.h>
#include <string.h>
#include "tp11_ej08.h"
#include "listADT.h" // incluye elemType

/* Usamos internamente la lista para manejar la colección de elementos
** Usamos una lista ordenada que no acepta repetidos, caso contrario tendríamos que
** verificar -antes de insertar- si el elemento está o no, para no agregarlo
** dos veces
*/

typedef struct setCDT {
	listADT list;
	int (compare*)(elemType, elemType)
} setCDT;

setADT
newSet(int (compare*)(elemType, elemType)) {
	setADT set = malloc(sizeof(struct setCDT));
	if (set == NULL)
		return NULL;

	set->list = newList(compare);
	set->compare = compare;
	return set;
}

void freeSet(setADT set) {
	void *e;
	/* Debemos liberar primero la lista */
	freeList(set->list);
	free(set);
}

int isEmptySet(setADT set) {
	return isEmpty(set->list);
}

int setContains(setADT set, elemType element) {
	return belongs(set->list, element);
}

int addElement(setADT set, elemType element) {
	return insert(set->list, element);
}

int deleteElement(setADT set, elemType element) {
	return delete (set->list, element);
}

int sizeSet(setADT set) {
	return size(set->list);
}

setADT
unionSet(setADT set1, setADT set2) {
    // Asumimos que la funcion de comparacion es la misma en ambos conjuntos
	setADT set;
	listADT l1, l2;

	set = newSet(set1->compare);
	if (set == NULL)
		return NULL;

	l1 = set1->list;
	toBegin(l1);

	/* Si set1 y set2 son el mismo conjunto, no podemos iterar como
    ** si fueran dos conjuntos distintos (se mezclarían los iteradores)
	*/
	if (set1 == set2) 	{
		while (hasNext(l1))
			addElement(set, next(l1));
		return set;
	}

	/* Podríamos agregar todos los elementos de l1 y luego todos los de l2
    ** pero no sería muy eficiente
    */
	l2 = set2->list;
	toBegin(l2);

	if (hasNext(l1) || hasNext(l2)) {
		elemType e1, e2;

		int has1, has2;

		if (has1 = hasNext(l1))
			e1 = next(l1);
		if (has2 = hasNext(l2))
			e2 = next(l2);

		while (has1 || has2) 		{
			if (!has2 || (has1 && set1->compare(e1, e2) < 0)) {
				addElement(set, e1);
				if (has1 = hasNext(l1))
					e1 = next(l1);
			} else if (!has1 || (has2 && set1->compare(e1, e2) > 0)) {
				addElement(set, e2);
				if (has2 = hasNext(l2))
					e2 = next(l2);
			} else { // son iguales
				addElement(set, e1);
				if (has1 = hasNext(l1))
					e1 = next(l1);
				if (has2 = hasNext(l2))
					e2 = next(l2);
			}
		}
	}
	return set;
}

setADT
intersectionSet(setADT set1, setADT set2) {
	setADT set;
	listADT l1, l2;

	set = newSet(set1->compare);
	if (set == NULL)
		return NULL;

	l1 = set1->list;
	toBegin(l1);

	/* Si set1 y set2 son el mismo conjunto, no podemos iterar como
    ** si fueran dos conjuntos
	*/
	if (set1 == set2) {
		while (hasNext(l1))
			addElement(set, next(l1));
		return set;
	}
	l2 = set2->list;
	toBegin(l2);

	elemType e1, e2;
	int has1=hasNext(l1), has2=hasNext(l2);
	if ( has1 && has2 ) {
		e1 = next(l1);
		e2 = next(l2);
	}

	while (has1 && has2) {
		if (set1->compare(e1, e2) < 0) {
		    if ( has1 = hasNext(l1))
			    e1 = next(l1);
		} else if (set1->compare(e2, e1) < 0) {
		    if ( has2 = hasNext(l2))
			    e2 = next(l2);
		}else {
			addElement(set, e1);
			if ( has2 = hasNext(l2))
			    e2 = next(l2);
		    if ( has1 = hasNext(l1))
	    		e1 = next(l1);
		}
	}
	return set;
}

setADT
diffSet(setADT set1, setADT set2) {
	elemType e1, e2;
	setADT set;
	listADT l1, l2;

	set = newSet(set1->compare);

	/* Si son el mismo conjunto, retornar conjunto vacío */
	if (set == NULL || set1 == set2)
		return set;

	l1 = set1->list;
	l2 = set2->list;

	toBegin(l1);
	toBegin(l2);

    int has1, has2;
	if (has2 = hasNext(l2))
		e2 = next(l2);

	if (has1 = hasNext(l1))
		e1 = next(l1);

	int c;
	while (has1) {
		if (!has2 || (c = set1->compare(e1, e2)) < 0) {
			addElement(set, e1);
			if ( has1 = hasNext(l1))
			    e1 = next(l1);
		} else if (c > 0) {
		    if ( has2 = hasNext(l2)) 
			    e2 = next(l2);
		} else {
		    if ( has1 = hasNext(l1))
			    e1 = next(l1);
			if ( has2 = hasNext(l2)) 
			    e2 = next(l2);
		}
	}
	return set;
}
