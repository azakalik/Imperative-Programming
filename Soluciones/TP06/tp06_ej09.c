/* Calcula la desviacion estandar */
double desv(const char vector[], int cantnum );

/* nibbleh. Dado un char devuelve el nibble alto */
char nibbleh ( char num );

/* nibblel. Dado un char devuelve el nibble bajo */
char nibblel ( char num );

/* Recibe el vector y la cantidad de numeros. Devuelve el promedio */ 
double promedio ( const char vector[] , int cantnum );

/* Calcula la sumatoria de la desviacion estandar */
double sumatoria ( double promedio , const char vector[], int cantnum);

// Esta version de promedio, si bien parece mas clara que la
// version no comentada, no es del todo correcta, por que?
/*
double 
promedio( const char vector[] , int cantnum ) {
	int i; 
	double suma = 0;

	for ( i = 0; i < cantnum/2; i++ )
		suma += nibbleh( vector[i] ) + nibblel ( vector[i] ) ;

	return suma/cantnum;
}
*/

double 
desv( const char vector[] , int cantnum ) {
    if ( cantnum == 0)
     return 0.0;
     
	double prom, sumat;

	prom = promedio( vector , cantnum );
	sumat = sumatoria( prom , vector , cantnum );

	return sqrt(sumat/cantnum);
}


double 
promedio( const char vector[] , int cantnum ) {
	int i = 0, cantAux; 
	double suma = 0;

	cantAux = cantnum; 
	while ( cantAux-- > 0) {
		/* Tomamos el nibble alto */
		suma += nibbleh( vector[i] );
		
		/* Si corresponde tomamos el nibble bajo */
		if ( cantAux-- )
			suma += nibblel ( vector[i] );
		i++;
	}
	return suma / cantnum;
}

double 
sumatoria ( double promedio , const char vector[], int cantnum ) {
	int i=0;
	double acum=0;

	while ( cantnum-- > 0) {
		acum+=pow( nibbleh( vector [i] ) - promedio, 2);

		if ( cantnum-- )
			acum+=pow( nibblel( vector [i] ) - promedio, 2);
		i++;
	}

	return acum;
} 

char nibbleh ( char num ) {
	return nibblel ( (unsigned char) num >> 4 ) ;
}

char nibblel ( char num ) {
	return num & 0x0F;
}
