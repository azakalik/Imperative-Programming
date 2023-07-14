#include <stdio.h>
#include "getnum.h"

int
main(void) {
	int n1, n2;
	
	n1 = getint("\nIngrese el numero1:");
	n2 = getint("\nIngrese el numero2:");
	
	printf("\nEl promedio es %.1f\n", (n1+n2)/2.0);
	printf("La suma es %d\n", n1+n2);
	printf("El menor es %d\n", (n1<n2)? n1 : n2);
	printf("El mayor es %d\n", (n1<n2)? n2 : n1);
	printf("%sson iguales\n", (n1==n2)? "" : "no ");
	return 0;
}
