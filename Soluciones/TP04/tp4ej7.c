#include <stdio.h>

#define isdigit(digit) ((digit>='0' && digit<='9') ? 1 : 0)

int
main(void) {
	int letra;

	letra = getchar();

	if ( isdigit(letra) )
			printf("Es un dígito\n");
	else
			printf("No es un dígito\n");
	return 0;
}

/* 
    Otra solución válida:
    #define isdigit(digit) (digit>='0' && digit<='9')
*/ 