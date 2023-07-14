#include <stdio.h>

#define DELTA 'A' - 'a'

int
main(void) {
	char letra;
	
	printf("Ingrese una letra :");
	letra = getchar();
	
	printf("\n%c en mayusculas = %c\n", letra, (letra>='a' && letra<='z')? letra+DELTA : letra);
	return 0;
}
