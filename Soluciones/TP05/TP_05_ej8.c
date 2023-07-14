#include <stdio.h>
#include <math.h>
#include "getnum.h"

/* Devuelve un numero real redondeado a la cantidad de cifras
** decimales pedidas en el segundo parámetro 
*/
double redondeo(double numero, int cifras);

unsigned int menu(void);

int main(void)
{
    float num;
    int opcion;

    num = getfloat("\nIngrese un numero real:");

    opcion = menu();
    switch (opcion)
    {
    case 1:
        num = redondeo(num, 0);
        break;
    case 2:
        num = redondeo(num, 1);
        break;
    case 3:
        num = redondeo(num, 2);
        break;
    case 4:
        num = redondeo(num, 3);
        break;
    default:
        printf("Opción inválida\n");
        break;
    }
    if (opcion >= 1 && opcion <= 4)
        printf("El numero es %g\n", num);
    return 0;
}

unsigned int menu(void)
{
    int opcion;

    printf("\n1 - Redondeo al entero más cercano\n");
    printf("2 - Redondeo a la décima más cercana\n");
    printf("3 - Redondeo a la centésima más cercana\n");
    printf("4 - Redondeo a la milésima más cercana\n");

    do {
        opcion = getint("Ingrese una opción:");
    } while (opcion < 0);
    
    return opcion;
}

double
redondeo(double numero, unsigned int cifras)
{
    long factor;

    for (factor = 1; cifras; factor *= 10, cifras--)
        ;

    return floor(numero * factor + 0.5) / factor;
}

// Presentamos ahora una versión mejorada de la función main propuesta arriba.

int
main(void)
{
    float num;
    int opcion;

    num = getfloat("\nIngrese un numero real:");

    opcion = menu();
    if (opcion >= 1 && opcion <= 4)
        printf("El numero es %g\n", redondeo(num, opcion - 1));
    else
        printf("Opción inválida\n");

    return 0;
}
