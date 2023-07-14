#include <stdio.h>
#include <math.h>
#include "getnum.h"

int lugar(int num, int pos);

int main(void)
{
    int j, boleto, esCapicua = 1;

    boleto = getint("Ingrese un número de 5 dígitos:");

    if (boleto >= 10000 && boleto <= 99999)
    {
        for (j = 1; j <= 2 && esCapicua ; j++)
            if (lugar(boleto, j) != lugar(boleto, 5 - j + 1))
            {
                esCapicua = 0;
            }
        printf("El boleto %ses capicúa\n", (esCapicua) ? "" : "no ");
    }
    else
        printf("Ingreso incorrecto de datos.\n");

    return 0;
}
/* Omitimos el código de la función lugar */