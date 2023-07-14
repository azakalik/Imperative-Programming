#include <stdlib.h>

/* Devuelve un número entero aleatorio dentro del intervalo [izq, der] */
int aleatorio(int izq, int der)
{
    return izq + (der - izq + 1) * (rand() / ((double)RAND_MAX + 1));
}
