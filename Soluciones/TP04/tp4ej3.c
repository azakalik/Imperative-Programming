#include <stdio.h>

#define	PI      3.1416
#define	VOLUMEN(r) 	(4.0 / 3.0 * PI * (r) * (r) * (r))

int
main(void) {
	int i;

	for(i = 1; i <= 10; i++)
		printf("Radio %2d -> Volumen %8.2f\n", i, VOLUMEN(i));
	return 0;
}
