#include <stdio.h>
#include "getnum.h"
int main(void)
{
    double venta;
    do
    {
        venta = getfloat("\nIngrese la suma vendida: ");
    } while (venta < 0);
    if (venta > 4000)
        printf("El monto a cobrar es: $%10.2f\n", 300.0 + venta * 0.09);
    if (venta >= 2000 && venta <= 4000)
        printf("El monto a cobrar es: $%10.2f\n", 300.0 + venta * 0.07);
    if (venta >= 1000 && venta < 2000)
        printf("El monto a cobrar es: $%10.2f\n", 300.0 + venta * 0.05);
    if (venta < 1000)
        printf("El monto a cobrar es: $%10.2f\n", 300.0);
    return 0;
}