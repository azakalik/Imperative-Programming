#include <stdio.h>

int main(void)
{
    long i = 1;

    /* Ejecutar el ciclo mientras los números que se obtienen sean múltiplos 
    ** de 10. Dejarán de ser múltiplos cuando el resultado esté fuera del rango
    */
    while ((i *= 10) % 10 == 0)
        printf("%ld\n", i);

    return 0;
}
