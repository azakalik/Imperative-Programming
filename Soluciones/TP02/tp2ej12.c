#include <stdio.h>

int
main(void) {
	char lt;
	
	printf("Ingrese un carácter:");
	lt = getchar();
	printf ("El caracter %s es letra\n", (lt>='A' && lt<='Z' || lt>='a' && lt<='z') ? "SI" : "NO" );
	return 0;
}
