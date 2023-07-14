#include <stdio.h>

#define SWAP(tipo, x, y) {tipo temp; temp= x; x= y; y= temp;}

int
main(void) {
	int a = 5, b = 3;

	printf("Antes del swap: a=%d, b=%d\n", a, b);

	/* El primer parámetro corresponde al tipo de las variables a intercambiar */
	SWAP(int, a, b);

	printf("Despues del swap: a=%d, b=%d\n", a, b);
	return 0;
}

// La solución anterior está bien para los alcances de la materia, pero
// una solución más segura sería usar el operador ## para asegurarnos que
// la variable auxiliar que creamos no cause problemas (pensar qué pasaría
// si en vez de a y b una de las variables de main se llamara temp)


#define SWAP(tipo, x, y) {tipo temp ## x ## y; temp ## x ## y= x; x= y; y= temp ## x ## y;}

// De esta forma nos aseguramos que nuestra variable auxiliar no tenga un nombre
// que coincida con alguna de las que nos pasaron