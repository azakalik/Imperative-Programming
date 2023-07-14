#include <stdio.h>
#include "getnum.h"

int
main(void) {
	int num;

	num = getint("Ingrese un entero positivo: ");
	printf ("\n%d / 2 = %d\n", num, num >>1 );
	return 0;
}