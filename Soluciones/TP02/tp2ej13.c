#include <stdio.h>
#include "getnum.h"

int
main(void) {
	int a, b;
	
	a = getint("\nIngrese el numero1:");
	b = getint("Ingrese el numero2:");

	printf ("\n%d %ses multiplo de %d\n", b, (!a || b % a)? "no ": "", a);
	return 0;
}
