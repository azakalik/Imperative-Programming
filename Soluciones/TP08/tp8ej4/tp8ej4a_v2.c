#include <stdio.h>
#include "cartas2.h"
#define CARTAS_JUEGO 5

/* este tipo permite definir el juego obtenido por un jugador */
typedef enum {NADA=1, PAR, PIERNA, POKER} tipoJugada;
typedef struct {
    tipoJugada juego;
    int figura ;
    } tipoConfiguraciones ;

/* Devuelve el valor de la configuraciรณn encontrada en el arreglo juego */
tipoConfiguraciones analizar(const tipoCarta juego[]);

/* Imprime el conjunto de cartas y la configuraciรณn obtenida */
void imprimirJuego(const tipoCarta juego[], tipoConfiguraciones resultado);

int
main(void) {
    tipoMazo mazo;
    tipoCarta juego[CARTAS_JUEGO];
    tipoConfiguraciones resultado;

    mazo = armarMazo();
    mezclarMazo(&mazo);
    repartir(&mazo, CARTAS_JUEGO, juego);
    resultado = analizar(juego);
    imprimirJuego(juego,resultado);

    return 0;
}

tipoConfiguraciones
analizar(const tipoCarta juego[]) {
    int i, j;
    tipoConfiguraciones total = {NADA,0}, parcial;

    for (i = 0; i < CARTAS_JUEGO-1 && total.juego <= PAR; i++)
    {
        parcial.juego = NADA;
        parcial.figura = 0;
        for(j = i+1; j < CARTAS_JUEGO; j++)
            if (juego[i].numero == juego[j].numero)
            {
                parcial.juego++;
                parcial.figura = juego[j].numero;
            }
   /* Si obtengo un juego de mayor valor que el que tengo o uno del mismo valor pero
    ** con una figura mรกs alta lo guardo 
   */
        if (total.juego < parcial.juego || (total.juego == parcial.juego && total.figura < parcial.figura))
            total = parcial;
    }
    return total;
}

void
imprimirJuego(const tipoCarta juego[], tipoConfiguraciones resultado) {
    int i;
    static char *cFiguras[] = {"Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve", "Diez", "J", "Q", "K", "As"};
    static char *cPalos[] = {"Diamante", "Trebol", "Corazon", "Pique"};
    static char *cResultados[] = {"Nada", "Par", "Pierna", "Poker"};

    printf("\nSu juego es: \n");
    for (i = 0; i < CARTAS_JUEGO; i++)
        printf("%s %s\n", cFiguras[juego[i].numero], cPalos[juego[i].palo]);
    printf("\nEl resultado es: %s", cResultados[resultado.juego-1]);
    if (resultado.juego != NADA)
        printf(" de %s", cFiguras[resultado.figura]);
    putchar('\n');
}