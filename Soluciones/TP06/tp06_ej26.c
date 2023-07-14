#include <stdlib.h>

char * 
encuentraCaracter(char * s, char c) {
	while(*s) {
		if(*s == c) {
			return s;
		}
		s++;
	}
	return NULL;
}

char * 
copiaCadena(char * d, const char * f) {
	while(*f) {
		*d++ = *f++;
	}
	return d;
}

void 
insertaDesde(char * s1, const char * s2, char c) {
	char * pos = encuentraCaracter(s1, c);
	if(pos != NULL)		
		copiaCadena(pos, s2);
}


/* soluciรณn utilizando string.h */
#include <string.h>

void 
insertaDesde(char * s1, const char * s2, char c) {
    char * pos = strchr(s1, c);
    if(pos != NULL)		
        strcpy(pos, s2);
}
