#include <stdio.h>

int
main(void) {
	char a, b;
	
	printf("Ingrese dos caracteres seguidos: ");
	a = getchar();
	b = getchar();
		
	printf("\nEl caracter '%c' es %s al caracter '%c'\n", a, (a==b)? "igual" : (a>b)? "mayor" : "menor",b);
	return 0;
}
