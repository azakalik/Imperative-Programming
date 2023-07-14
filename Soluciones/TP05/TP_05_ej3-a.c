#include <stdio.h>
#include <math.h>
#include "getnum.h"

int lugar(int num, int pos);

int main(void)
{
    int j, boleto, esCapicua = 1;

    boleto = getint("Ingrese un numero de 5 digitos:");

    if (boleto >= 10000 && boleto <= 99999)
    {
        for (j = 1; esCapicua && j <= 2; j++)
            if (lugar(boleto, j) != lugar(boleto, 5 - j + 1))
            {
                esCapicua = 0;
            }
        printf("El boleto %ses capicua\n", (esCapicua) ? "" : "no ");
    }
    return 0;
}

int lugar(int num, int pos)
{
    return (num / (int)pow(10, pos - 1)) % 10;
}
