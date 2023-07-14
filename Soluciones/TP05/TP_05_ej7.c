/* Este programa estima el valor de e a la X por medio de una serie, y luego muestra la 
** comparación con el valor calculado usando la función provista por la biblioteca 
** matemática. El valor de X es leído desde la entrada estándar 
*/

#include <stdio.h>
#include <math.h>
#include "getnum.h"

#define EPSILON 0.0000001

/* Devuelve la estimación de e a la X con un error de EPSILON,
** recibe el valor de X 
*/
double ex(double x);

int main(void)
{
	double eEstimado, eReal, x;

	x = getfloat("Ingrese el valor de x para calcular exp(x): ");
	if (x < 0)
		printf("Solo para positivos\n");
	else
	{
		eEstimado = ex(x);
		eReal = exp(x);
		printf("\nValor calculado: %f\n", eEstimado);
		printf("Valor real: %f\n", eReal);
	}
	return 0;
}

double
ex(double x)
{
	double factorial = 1;
	double valor, anterior, potX;
	int termino = 1;

	if (x < 0)
		return –1;

	potX = x;
	valor = 1;
	anterior = 0;
	while (valor – anterior > EPSILON)
	{
		anterior = valor;
		valor += potX / factorial;
		potX *= x;
		termino++;
		factorial *= termino;
	}

	return valor;
}
