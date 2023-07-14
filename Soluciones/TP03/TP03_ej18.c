#include <stdio.h>
#include "getnum.h"

int main(void)
{
    int i;
    long factorial = 1;

    printf("Cálculo de factorial\n");
    do
    {
        i = getint("Ingrese un numero no negativo: ");
        if (i < 0)
            printf("Número incorrecto\n");
    } while (i < 0);

    while (i > 1)
        factorial *= i--;

    /* Este resultado puede ser inválido si excede el rango del tipo long */
    printf(" \nEl factorial es: %ld\n", factorial);

    return 0;
}
