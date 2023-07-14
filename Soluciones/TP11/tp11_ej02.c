#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"

#define BORRA_BUFFER while (getchar() != '\n');
#define CANT_FUNC	3
#define PASOS 		100000
#define EPSILON 	0.000001
#define MEM_INC		10

typedef struct {
	double a,b ;
} tipoIntervalo;

typedef struct {
	int cant;
	int dim;
	tipoIntervalo * lista;
} tipoRaices;


/* Estructuras necesarias para el manejo del menú */
typedef struct{
	char * titulo;
	double (*funcion)(double);
}tipoItemMenu;

typedef struct{
	int cantItems;
	tipoItemMenu * items;
} tipoMenu;


				
/* Dado un intervalo y un puntero a una función busca subintervalos con raíces */
tipoRaices buscar_raices(tipoIntervalo, double (*funcion)(double));

/* Almacena un intervalo en la estructura tipoRaices, de no hay espacio ejecuta realloc() */
int almacenarRaiz(tipoRaices * resp, tipoIntervalo inter);

/* Libera la respuesta cuando deja de ser necesaria */
void freeRaices(tipoRaices resp);

/* Arma el menú y devuelve la opción elegida. Nota: asume menos de 10 opciones */
int armarMenu(tipoMenu menu);

/* función propia para evaluación */
double mifuncion(double);

/* Realiza la lectura de los extremos del intervalo */
void leerExtremos(tipoIntervalo *extremos);

/* Función que imprime los resultados en salida estándar */
void verResultados(tipoRaices respuesta);

int
main(void) {
	tipoItemMenu tabla[CANT_FUNC] = {{"Seno",sin},{"Coseno",cos}, {"x2 - 4",mifuncion}};
	tipoMenu menu = {CANT_FUNC, tabla};
	int opcion;
	tipoRaices respuesta;
	tipoIntervalo extremos;

	while (opcion = armarMenu(menu)) {
		leerExtremos(&extremos);
		respuesta = buscar_raices(extremos,tabla[opcion-1].funcion);
		verResultados(respuesta);	
		if (respuesta.cant >=0)
			reeRaices(respuesta);
	}
	return 0;
}

void
verResultados(tipoRaices respuesta) {
	int i;
	
	if (respuesta.dim == -1)	/* Corresponde a error de malloc() */
		printf("Error en el almacenamiento de raíces\n");
	else if (respuesta.cant > 0) {
		for (i=0; i<respuesta.cant; i++)
			printf("\nRaíz %d en [%f,%f]\n",
 				i+1,respuesta.lista[i].a, respuesta.lista[i].b);
	}
	else
		printf("\nNo hay raíces en ese intervalo\n");
}

double
mifuncion(double x) {
	return (x*x - 4.0);
}

int
armarMenu(tipoMenu menu) {
	int i;

	/* Imprime las opciones */
	for (i=0; i < menu.cantItems; i++)
		printf("%d - %s\n", i+1, menu.items[i].titulo);
	printf("0 - Salir\n");

	/* Espera respuesta del usuario */
	do
		i = getchar()-'0';
	while (i < 0 || i > menu.cantItems);

	BORRA_BUFFER

	return i;
}


tipoRaices
buscar_raices(tipoIntervalo extr, double (*funcion)(double)) {
	double x,fx,fxant, incremento;
	tipoRaices respuesta;
	int esRaiz = 0, error = 0;
	tipoIntervalo intActual;

	incremento = (extr.b - extr.a) / PASOS ;

	if (incremento == 0 )
		incremento = 0.00001;  

	respuesta.cant = -1;
	respuesta.dim = 0;
	
	/* Se recorre el intervalo, evaluando la función en cada punto */
	x = extr.a;
	fxant = fx = (*funcion)(x);
	while ( x <= extr.b && !error ) {
		if ( fx*fxant < 0  ||  fabs(fx) < EPSILON) {
			/* Con el flag esRaiz se controla que no se indique más de una vez la misma raíz.
 		** Si el punto anterior ya era raíz, entonces extender el intervalo
			*/
 			if ( ! esRaiz ) {
				respuesta.cant++;
				intActual.a = x - incremento;	 
    		}

			/* Si se detectó un cambio de signo es porque hay una raíz entre el x 
 			** anterior y el actual por lo tanto el fin del intervalo es x.
			** En cambio si x es raíz el extremo derecho del intervalo será el próximo x 
	 		*/
       	if ( fx * fxant < 0 )
				intActual.b = x;
       	else
				intActual.b = x + incremento;
				
			/* Se almacena el nuevo intervalo, o actualiza uno existente */
			if ( !almacenarRaiz(&respuesta, intActual) )	
				error = 1;	

       	esRaiz = 1;		
     } else
			esRaiz = 0;

		/* Paso al próximo punto */
		x += incremento;
		fxant = fx; 

		fx = (*funcion)(x);

	}
	respuesta.cant++;	/* Se incrementa cant porque internamente representa la posición actual,
 								** y al terminar debe indicar cantidad de raíces */
	return respuesta;
}

int 
almacenarRaiz(tipoRaices * resp, tipoIntervalo inter) {
	tipoIntervalo * aux;
	
	if (resp->dim == 0) { 	/* Si es la primera vez que se invoca */
		resp->lista = malloc(sizeof(tipoIntervalo) * MEM_INC);
		if (!resp->lista) {
			resp->dim = -1;	/* Si falla el pedido dim queda en –1 */
			return 0;
		}
		resp->dim = MEM_INC;	
	}
	else if (resp->cant == resp->dim) {	/* Si es necesario pedir más memoria */
		resp->dim += MEM_INC;
		aux = realloc(resp->lista, resp->dim * sizeof(tipoIntervalo));
		if (aux == NULL) {
			free(resp->lista);
			resp->dim = -1;
			return 0;
		}
		resp->lista = aux;
	}

	/* Se  almacena/actualiza  el intervalo */
	resp->lista[resp->cant] = inter;
	return 1;
}

void
freeRaices(tipoRaices resp) {
	free(resp.lista);
}

void 
leerExtremos(tipoIntervalo *extremos) {
	float a, b;

	/* leer extremos del intervalo */
	a = getfloat("Extremo 1:");
	b = getfloat("Extremo 2:");
	if (a<b) {
		extremos->a = a;	extremos->b = b;
	} else {
		extremos->b = a; extremos->a = b;
	}
}
