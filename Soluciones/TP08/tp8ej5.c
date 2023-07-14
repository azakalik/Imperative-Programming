#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R_MINIMO 10
#define R_MAXIMO 1000

typedef struct {
    int x,y; 
} tipoPunto;


/* Simula el movimiento de una partícula dentro de un círculo partiendo desde un origen dado.
** Retorna la cantidad de unidades de tiempo que tarda en salir del circulo 
*/
int simulacion(int radio, int origenX, int origenY);

/* genera un movimiento aleatorio en forma vertical u horizontal 
** actualizando la posición de la partícula 
*/
void mover (tipoPunto *particula);

/* devuelve 1 si la posición de la partícula esta fuera del circulo */
int salio (tipoPunto particula, int radio);


int
main (void) {
	unsigned long tiempo;
	int radio;

	srand(time(NULL));

	printf("\n\nSimulacion del movimiento de una particula\n");
	printf ("\n%10s%10s%10s\n","Radio","Tiempo","T/R");
	printf ("----------------------------------\n");

	for (radio = R_MINIMO; radio < R_MAXIMO; radio+= (R_MAXIMO-R_MINIMO)/10) {
		tiempo = simulacion( radio, 0, 0);
		printf ("%10d%10lu%10.2f\n",radio,tiempo,(float)tiempo/radio);
	}

	printf("\n\n");

	return 0;
}

int 
simulacion(int radio, int origenX, int origenY) {
	unsigned long tiempo;
	tipoPunto particula;

	particula.x = origenX;
	particula.y = origenY;
	tiempo = 0;
	do {
		tiempo++;
		mover ( &particula );
	} while (!salio(particula, radio));

	return tiempo;
}

 
void
mover(tipoPunto *particula) {
	int i;
	i = rand() % 4;
	switch (i)
	{
		case 0: particula->x--; break;
	    case 1: particula->y--; break;
		case 2: particula->x++; break;
	    case 3: particula->y++; break;
	}
	/* Otra forma de hacerlo seria :
	*	int movim[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	*
	* 	i= randInt(0, sizeof(movim)/sizeof(movim[0]));
	*
	*	particula->x += movim[i][0];
	*	particula->y += movim[i][1];
	*/
}

int 
salio (tipoPunto particula, int radio) {
	return ( (particula.x * particula.x + particula.y * particula.y) > radio * radio );
}
