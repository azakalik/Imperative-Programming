#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cartas1.h"

typedef enum {NADA=1, PAR, PIERNA, POKER} tipoConfiguraciones;

/* Devuelve el valor de la configuraciรณn correspondiente al arreglo juego */
void analizar(const tipoCarta juego[]);

int
main(void) {
    tipoCarta mazo[CARTAS_MAZO];
    
    llenarMazo(mazo);
    mezclarMazo(mazo);
    analizar(mazo);
 
    return 0;
}

void
analizar(const tipoCarta juego[]) {
    int i, j;
    static char *cFiguras[] = {"Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve", "Diez", "J", "Q", "K", "As"};
    static char *cPalos[] = {"Diamante", "Trebol", "Corazon", "Pique"};
    static char *cResultados[] = {"Nada", "Par", "Pierna", "Poker"};

    tipoConfiguraciones total=NADA, parcial;

    for (i = 0; i < CARTAS_JUEGO-1; i++) {
        parcial = NADA;
        for(j = i+1; j<CARTAS_JUEGO; j++)
            if (juego[i].numero == juego[j].numero)
                parcial++;

        if (total < parcial)
            total = parcial;
    }

    printf("\nSu juego es: \n");
    for (i = 0; i < CARTAS_JUEGO; i++)
        printf("%s %s\n", cFiguras[juego[i].numero], cPalos[juego[i].palo]);

    printf("El resultado es: %s\n", cResultados[total-1]);
}
