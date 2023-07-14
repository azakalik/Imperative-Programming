#include <stdio.h>

int
main(void) {
	char letra1, letra2;
	
	printf("\nIngrese dos caracteres (uno al lado del otro): ");
	letra1 = getchar();
	letra2 = getchar();
	printf ("\nEl caracter de mayor valor ASCII es %c\n", (letra1>letra2) ? letra1 : letra2);
	return 0;
}
