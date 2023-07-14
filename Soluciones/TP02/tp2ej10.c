#include <stdio.h>
#include "getnum.h"

int
main(void) {
	int seg;
	
	seg = getint("Ingrese una cantidad de segundos: ");
	printf ("\n%d seg. = %d h %d m %d s\n", seg, seg / 3600, (seg % 3600)/60, seg % 60);
	return 0;
}
