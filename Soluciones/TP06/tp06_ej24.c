void
eliminaBlancos (char cadena[]) {
	unsigned int i,j;
	
	/* Recorrer el string con dos índices:
	** i: índice "original", para recorrer todos los caracteres hasta el final
	** j: índice "actual", al cual se van copiando los caracteres. Este índice no 
	**    se incrementa cuando hay blancos repetidos 
	** En otras palabras: lo mismo que eliminaCeros
    */
	for (i = j = 0; cadena[i] ; i++) 	{
		/* Si es el 1er. caracter ó no hay dos blancos seguidos, se copia */
		if ( i == 0 || !(cadena[i] == ' ' && cadena[i-1] == ' '))
				cadena[j++] = cadena[i];
	}

	/* Colocar el 0 de fin de string en el índice actual */
	cadena[j] = 0;
}