#include <stdlib.h>
#include <time.h>
#include "cartas1.h"

void
llenarMazo(tipoCarta mazo[]) {
    int i;

    for ( i = 0; i < CARTAS_MAZO; i++) {
         mazo[i].numero = i%CANT_FIGURAS;
         mazo[i].palo = i/CANT_FIGURAS;    
    }
    return;
}

void
mezclarMazo(tipoCarta mazo[]) {
    int i, posicion;
    tipoCarta auxCarta;

    srand(time(NULL));

    for(i=0; i<CARTAS_MAZO; i++) {
        auxCarta = mazo[i];
        posicion = rand() % CARTAS_MAZO;
        mazo[i] = mazo[posicion];
        mazo[posicion] = auxCarta;
    }
    return;
}
