#include <stdio.h>
#include <math.h>
#include "getnum.h"

int main(void)
{
    int j, cifras, boleto, auxB, esCapicua = 1;

    boleto = getint("Ingrese un numero:");
    for (cifras = 0, auxB = boleto; auxB; cifras++, auxB /= 10)
        ;

    /****************************************************************************
	** Se recorre el nĂşmero comparando los extremos, la cantidad de comparaciones
	** corresponden a la mitad de la cantidad de cifras, sea par o impar 
    ***************************************************************************/
    for (j = 1; esCapicua && j <= cifras / 2; j++)
        if (lugar(boleto, j) != lugar(boleto, cifras - j + 1))
        {
            esCapicua = 0;
        }
    return esCapicua; /* Devuelve 1 si es capicua y 0 si no lo es */
}
