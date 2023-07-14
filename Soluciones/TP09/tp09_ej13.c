

char * strrchrRec(const char *s, char c) {
	if ( *s == 0 )
		return NULL;
	char * aux = strrchrRec(s+1, c);
	if ( aux != NULL )
		return aux;
	if ( *s==c )
		return s;
	return NULL;
}

