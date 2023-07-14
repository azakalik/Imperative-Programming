#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uInt ;

#define TRUE 1
#define FALSE !TRUE

/* Recibe un string con el formato dd/mm/yyyy y retorna por parámetro el día, mes
** y año de la misma. En caso de que el formato sea inválido
** o la fecha incorrecta, retorna FALSE y no altera los parámetros
*/
int valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio);

 /* Devuelve TRUE si el año es bisiesto y FALSE en caso contrario */
int esBisiesto(uInt anio);

/* Función auxiliar que verifica que un string sea de la forma dd/mm/yyyy */
static int 
valFormato( const char * fecha) {4
	int resp = TRUE, i;

	/* Validamos primero la longitud y los separadores */
	resp = (fecha[2] == '/' && fecha[5] == '/' && strlen(fecha)==10 );

	/* Validamos ahora que el resto sean digitos */
	if ( resp )
		for (i = 0 ; fecha[i] && resp; i++)
			if ( i != 2 && i !=5 && !isdigit(fecha[i]))
				resp = FALSE;

	return resp;
}

int 
esBisiesto(uInt anio) {
	return ( (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0 );
}

/* Funcion auxiliar que extrae el dia, mes y año de un string con el formato 
** dd/mm/yyyy ya validado
*/
static int 
extraeFecha( const char * fecha, uInt *dia, uInt *mes, uInt *anio) {
/* Usamos dos vectores auxiliares en los cuales se almacenan los días de cada mes. 
** El primer vector para los años no bisiestos y el segundo para los años bisiestos.
*/
static int diasMes[][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
 						{31,29,31,30,31,30,31,31,30,31,30,31}};
int fechaOK = FALSE;

	*dia = atoi(fecha);
	*mes = atoi(fecha + 3);
	*anio = atoi(fecha + 6);

	if ( *dia > 0 && *mes >= 1 && *mes <= 12)
		fechaOK = *dia <= diasMes[esBisiesto(*anio)][*mes-1] ;

	return fechaOK;
}

int
valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio) {
	int fechaOK;
	uInt lDia, lMes, lAnio;

   fechaOK = valFormato(fecha) && extraeFecha(fecha,&lDia,&lMes,&lAnio);
	
  /* Si la fecha es valida, actualizar los parametros de salida. Caso contrario
  ** quedan con los valores al momento de la invocación
  */
	if ( fechaOK) {
		*dia  = lDia;
		*mes  = lMes;
		*anio = lAnio;
	}

	return fechaOK;	
}
