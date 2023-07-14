#include <math.h>
#include <errno.h>
#define EPSILON 0.00001

double
potencia(double base, int exponente)
{
    double pot;
    double auxBase;

    if (fabs(base) < EPSILON && exponente <= 0 ) {
        errno = EDOM;
		return -1.0;
    }
 
	if (exponente < 0)
	{
        auxBase = 1 / base;
        exponente *= -1;
	}
	else
		auxBase = base;
 
	for(pot = 1; exponente; pot *= auxBase, exponente--);
	
	return pot;
}
