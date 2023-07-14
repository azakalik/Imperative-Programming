#include <stdio.h>
#include <math.h>
#include "getnum.h"

int lugar(int num, int pos);

int main(void)
{
    int j, cifras, boleto, auxB, esCapicua = 1;

    boleto = getint("Ingrese un número:");

    /* Calcular la cantidad de cifras del número */
    for (cifras = 0, auxB = boleto; auxB; cifras++, auxB /= 10)
        ;

    /* Se recorre el número comparando los extremos, la cantidad de comparaciones
	** corresponden a la mitad de la cantidad de cifras, sea par o impar 
	** Línea anterior: for(j=1; j<=2; j++) 
       */
    for (j = 1; esCapicua && j <= cifras / 2; j++)
        if (lugar(boleto, j) != lugar(boleto, cifras - j + 1))
        {
            esCapicua = 0;
        }
    printf("El boleto %ses capicúa\n", (esCapicua) ? "" : "no ");

    return 0;
}
