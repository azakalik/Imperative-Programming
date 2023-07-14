#include <stdio.h>
#include "getnum.h"

#define MAXIMO2(a,b,resp)  (resp = ((a)>(b)) ? (a) : (b))

/* Esta macro se basa en la anterior, calculando el máximo de los dos
** primeros, y luego comparando este máximo con el tercer número 
*/
#define MAXIMO3(a,b,c,resp) (resp = (MAXIMO2(a,b,resp)>(c)) ? resp : (c))

// En la anterior se asume que MAXIMO2 usa un condicional y retorna un valor, pero si usara un if no seria valido
#define MAXIMO3bis(a,b,c,resp) { MAXIMO2(a,b,resp); if ((c) > resp) resp = c; }

int
main(void) {
	int num1, num2, num3, maximo;

	num1 = getint("Ingrese el primer numero: ");
	num2 = getint("Ingrese el segundo numero: ");
	num3 = getint("Ingrese el tercer numero: ");

	MAXIMO3(num1, num2, num3, maximo);
	printf("El mayor entre %d, %d y %d es %d\n", num1, num2, num3, maximo);

	/* Otra forma de hacerlo, no sirve con MAXIMO3bis */
	printf("El mayor entre %d, %d y %d es %d\n", num1, num2, num3, MAXIMO3(num1, num2, num3, maximo));
	return 0;
}
