#include <stdio.h>
#include "getnum.h"

#define DIGITO 5

int main(void)
{
    int n;
    int contador = 0;

    n = getint("Ingrese un entero: ");

    /* Si es negativo lo convertimos para trabajar en positivo */
    if (n < 0)
        n *= -1;

    while (n != 0)
    {
        if ((n % 10) == DIGITO)
            contador++;
        n /= 10;
    }

    printf("\nCantidad de dígitos iguales a %d: %d\n", DIGITO, contador);
    return 0;
}
