#include <stdio.h>
#include <math.h>
#include "getnum.h"

int lugar(int num, int pos);

int main(void)
{
    int j, flag, boleto, esCapicua = 1;

    /***************** LINEAS AGREGADAS *********************/
    do
    {
        boleto = getint("Ingrese un número de 5 dígitos:");
        if (flag = (boleto < 10000 || boleto > 99999))
            printf("Ingreso incorrecto de datos.\n");
    } while (flag);
    /********************************************************/

    for (j = 1; esCapicua && j <= 2; j++)
        if (lugar(boleto, j) != lugar(boleto, 5 - j + 1))
        {
            esCapicua = 0;
        }
    printf("El boleto %ses capicúa\n", (esCapicua) ? "" : "no ");
    return 0;
}
