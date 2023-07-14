#include <stdio.h>
#include "getnum.h"
#define BASICO 300.0
#define PORC1000 0.05
#define PORC2000 0.07
#define PORC4000 0.09
int main(void)
{
    double venta, total = BASICO;
    do
    {
        venta = getfloat("\nIngrese la suma vendida: ");
    } while (venta < 0);
    if (venta > 4000)
        total += venta * PORC4000;
    else if (venta >= 2000)
        total += venta * PORC2000;
    else if (venta >= 1000)
        total += venta * PORC1000;
    printf("El monto a cobrar es: $%10.2f\n", total);
    return 0;
}