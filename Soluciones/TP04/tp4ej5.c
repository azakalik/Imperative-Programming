#include <stdio.h>
#include "getnum.h"

/* IMPORTANTE: Los paréntesis no están de más. a  y b pueden ser expresiones */
#define MAXIMO2(a,b,resp)  (resp = ((a)>(b)) ? (a) : (b))

int
main(void)
{
	int num1, num2, maximo;

	num1 = getint("Ingrese primer numero:");
	num2 = getint("Ingrese segundo numero:");

	MAXIMO2(num1, num2, maximo);
	printf("El mayor entre %d y %d es %d\n", num1, num2, maximo);

	/* Otra forma de hacerlo */
	printf("El mayor entre %d y %d es %d\n", num1, num2, MAXIMO2(num1, num2, maximo));
	return 0;
}
