#include <stdio.h>
#include "getnum.h"
int main(void)
{
    int i, j, lado;
    do
        lado = getint("Ingrese el lado del cuadrado:");
    while (lado <= 0);
    /* Con dos ciclos anidados */
    for (i = 1; i <= lado; i++)
    {
        for (j = 1; j <= lado; j++)
            putchar('*');
        putchar('\n');
    }
    putchar('\n');
    /* con un único ciclo */
    for (i = 1; i <= lado * lado; i++)
    {
        putchar('*');
        if (i % lado == 0)
            putchar('\n');
    }
    return 0;
}