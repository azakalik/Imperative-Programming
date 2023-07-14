#include <stdlib.h>
#include <time.h>
#include "cartas2.h"

tipoMazo
armarMazo(void) {
    int i;
    tipoMazo mazo;

    mazo.primeraCarta = 0;
    for ( i = 0; i < CARTAS_MAZO; i++) {
         mazo.cartas[i].numero = i % CANT_FIGURAS;
         mazo.cartas[i].palo = i / CANT_FIGURAS;
    }
    return mazo;
}

void
mezclarMazo(tipoMazo * pMazo) {
    int i, posicion;
    tipoCarta auxiliar;

    srand(time(NULL));

    /* Para realizar la mezcla se reemplaza cada carta por
    ** otra elegida al azar del resto del mazo 
    */
    for(i=pMazo->primeraCarta; i<CARTAS_MAZO; i++) {
        auxiliar = pMazo->cartas[i];
        posicion = rand() % CARTAS_MAZO;
        pMazo->cartas[i] = pMazo->cartas[posicion];
        pMazo->cartas[posicion] = auxiliar;
    }
    return;
}

int
repartir(tipoMazo * pMazo, int cant, tipoCarta juego[]) {
    int i;

    /* Asigno las primeras cartas disponibles del mazo al jugador */
    for(i=0;i<cant && pMazo->primeraCarta < CARTAS_MAZO; i++)
        juego[i] = pMazo->cartas[pMazo->primeraCarta++];
    return i;
}

int
cantCartas(tipoMazo * pMazo) {
    return CARTAS_MAZO - pMazo->primeraCarta;
}
