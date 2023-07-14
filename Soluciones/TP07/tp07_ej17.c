// Pensar por que no puede reemplazarse el ciclo 	
//          while ( *s ) s++;   
//  por   
//          while (*s++);

char * 
strCat ( char *s, const char *t)
{
	char *aux =s;
    while ( *s )
		s++;
	while (*s++ = *t++) ; 
    
    return aux;
}

