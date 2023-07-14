#include <stdio.h>
#include "getnum.h"

int
main(void) {
	float velocidad;

	velocidad = getfloat("\nIngrese una velocidad en m/s: ");

	printf ("\nEn km/h = %f\n", (velocidad * 3600) / 1000 );
	return 0;
}