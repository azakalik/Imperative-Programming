#include <stdio.h>

int main(void) {
	int edad = 25;
	float longitud = 185.654;
	char letra = 'Z';

	/* a) */
	printf("%-5d\n", edad);

	/* b) */
	printf("%10d\n", edad);

	/* c) */
	printf("%-10.2f\n", longitud);

	/* d) */
	printf("%8d\n", letra);

	return 0;
}