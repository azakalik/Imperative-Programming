#include <stdio.h>
#include "getnum.h"

int
main(void)
{
	int num, cant = 0;	

	do {
		num = getint("Ingrese un n�mero entero positivo: ");
	} while(num <= 0);

	while(num != 0) {
		if(num % 2 != 0) {
			cant++;
		}
		num >>= 1; /* Tambi�n podr�a ser num /= 2 */
	}

	printf("%d", cant);	
	return 0;
}
