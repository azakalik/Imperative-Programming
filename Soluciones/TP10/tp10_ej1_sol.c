#include "utillist.h"

int sumAll(const TList list) {
	if ( list == NULL )
		return 0;
	return list->elem + sumAll(list->tail);
}

// Versión donde la lista vacía retorna 1
int odds1(const TList list) {
	if ( list == NULL )
		return 1;
	// Se pueden invertir los términos y también funciona,
	// pero sería ineficiente
	return list->elem % 2 && odds1(list->tail);
}

// Versión donde la lista vacía retorna cero
int odds2(const TList list) {
	// En esta versión el caso de lista vacia es de validación, no es el caso base
	// En cuanto a eficiencia, sería más lógico que se valide ANTES de llamar a la función 
	if ( list == NULL )
		return 0;
	// Verdadero caso base: una lista con un elemento
	if ( list->tail == NULL )
		return list->elem % 2;

	// Se pueden invertir los términos y tambien funciona,
	// pero sería ineficiente
	return list->elem % 2 && odds2(list->tail);
}
