/* Copia n caracteres desde el string t hacia s 
** Esta funcion no es similar a strcpy, ya que si
** t tiene mas de n caracteres, no copia el cero final
** y si tiene menos rellena con ceros.
*/
char * my_strncpy(char *target, const char *source, unsigned int n)
{
    char * p = target;
    while (*source && n > 0){
        *target++ = *source++;
        n--;
    }
    while (n-- > 0)
        *target++ = 0;
    return p;
}

/* Concatena n caracteres desde el string t al final del string s 

*/
char * my_strncat(char *target, const char *source, unsigned int n)
{   
    // No podemos hacer lo siguiente, ya que strncat no rellena con ceros y siempre
    // deja el string s null-terminated
    // strncpy(target + strlen(target), source, n);
    char* p = target + strlen(target);

	// Agregamos al final
	while (*source != '\0' && n--)
		*p++ = *source++;

	// El cero final
	*p = '\0';

	return target;
}


/* Compara en base a valor ASCII los primeros n caracteres de dos strings
** Devuelve :
** < 0 si s < t		 0   si s==t	 		> 0 si s > t 
*/
int my_strncmp(char *s, char *t, unsigned int n)
{
    for (; n && *s == *t && *s; s++, t++, n--)
      ;
    if (n == 0 )
       return 0;
    
    return *s - *t;
}