#include <stdio.h>
#include "cartas2.h"
#include "getnum.h"

#define CANT_JUGADORES  2
#define CARTAS_JUEGO    5

/* Define la configuración obtenida por un jugador */
typedef enum {NADA=1, PAR, PIERNA, POKER} tipoJugada;
typedef struct {
    tipoJugada juego;
    int figura ;
} tipoConfiguraciones ;

/* Toda la información referida a un jugador */
typedef struct {
    tipoCarta juego[CARTAS_JUEGO];
    tipoConfiguraciones resultado;
    int puntaje;
} tipoJugador;


/********************* FUNCIONES DE BACK - END **************************/

/* Se encarga de crear el mazo, mezclarlo y colocar los puntajes de los jugadores en cero */
void inicializarJuego( tipoMazo * mazo, tipoJugador * jugadores);

/* Reparte 5 cartas a cada jugar y analiza que configuración obtuvo cada uno */
void jugarMano(tipoMazo * mazo, tipoJugador * jugadores);

/* Devuelve el valor de la configuración encontrada en un juego */
tipoConfiguraciones analizar(const tipoCarta juego[]);

/* Retorna el índice del jugador con mayor config., si hay empate retorna el primero de ellos */
int buscarGanador(const tipoJugador jugadores[]);



/********************* FUNCIONES DE FRONT - END *************************/

/* Imprime las cartas de todos los jugadores indicando que config. obtuvo cada uno */
void imprimirMano(const tipoJugador jugadores[]);

/* Imprime las cartas y la configuración obtenida por un jugador*/
void imprimirJuego(const tipoCarta juego[], tipoConfiguraciones resultado);

/* Imprime el o los jugadores con mayor configuración en una mano */
void imprimirGanadores(const tipoJugador jugadores[], int ganador);

/* Imprime el resultado final del juego */
void imprimirFinal(const tipoJugador jugadores[]);

int
main(void) {
    tipoMazo mazo;
    tipoJugador jugadores[CANT_JUGADORES];
    int ganador;

    inicializarJuego(&mazo, jugadores);

    do {
        jugarMano(&mazo, jugadores);
        ganador = buscarGanador(jugadores);

        imprimirMano(jugadores);

          /* si el indicado como ganador tiene alguna configuración */
        if (jugadores[ganador].resultado.juego != NADA )
            imprimirGanadores(jugadores, ganador);

    } while( cantCartas(&mazo)>= CARTAS_JUEGO * CANT_JUGADORES && yesNo("Desea continuar el juego ?") == 1);

    imprimirFinal(jugadores);

    return 0;
}

void
inicializarJuego( tipoMazo * mazo, tipoJugador * jugadores) {
    memset(jugadores, 0, sizeof(tipoJugador) * CANT_JUGADORES);

    *mazo = armarMazo();
    mezclarMazo(mazo);
}

void
jugarMano(tipoMazo * mazo, tipoJugador * jugadores) {
    int i;

    /* se reparten cartas y se analiza lo obtenido por cada jugador */
    for (i = 0; i < CANT_JUGADORES; i++)
    {
        repartir(mazo, CARTAS_JUEGO, jugadores[i].juego);
        jugadores[i].resultado = analizar(jugadores[i].juego);
    }
}

int
buscarGanador(const tipoJugador jugadores[])
{
    int i, ganador = 0; /* Se postula como ganador al primero */

    for (i=1; i < CANT_JUGADORES; i++)
	/* Si el jugador actual tiene mayor cantidad de cartas iguales o tiene la misma cantidad 
** pero de un número mayor, se lo marca como ganador 
*/
	if (jugadores[i].resultado.juego > jugadores[ganador].resultado.juego ||
       (jugadores[i].resultado.juego == jugadores[ganador].resultado.juego &&
       jugadores[i].resultado.figura > jugadores[ganador].resultado.figura) )
            ganador = i;

    return ganador;
}

tipoConfiguraciones
analizar(const tipoCarta juego[]) {
    int i, j;
    tipoConfiguraciones total ={NADA,0}, parcial;

    for (i = 0; i < CARTAS_JUEGO-1 && total.juego <= PAR; i++) {
        parcial.juego = NADA;
        parcial.figura = 0;
        for(j = i+1; j<CARTAS_JUEGO; j++)
            if (juego[i].numero == juego[j].numero) {
                parcial.juego++;
                parcial.figura = juego[j].numero;
            }

        /* Si se encuentra un juego de mayor valor al que tenía o uno del mismo valor pero
          ** con una figura mas alta, se guarda 
  */
        if (total.juego < parcial.juego || (total.juego == parcial.juego && total.figura < parcial.figura))
            total = parcial;
    }
    return total;
}


void
imprimirMano(const tipoJugador jugadores[]) {
    int i;

    for (i = 0; i<CANT_JUGADORES; i++) {
        printf ("\nJugador %d\n", i+1);
        imprimirJuego(jugadores[i].juego,jugadores[i].resultado);
    }
}

void
imprimirJuego(const tipoCarta juego[], tipoConfiguraciones resultado) {
    int i;
    static char *cFiguras[] = {"Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve", "Diez", "J", "Q", "K", "As"};
    static char *cPalos[] = {"Diamante", "Trebol", "Corazon", "Pique"};
    static char *cResultados[] = {"Nada", "Par", "Pierna", "Poker"};

    for (i=0; i<CARTAS_JUEGO; i++)
        printf("%s %s\n", cFiguras[juego[i].numero], cPalos[juego[i].palo]);
    printf("\nEl resultado es: %s", cResultados[resultado.juego-1]);
    if (resultado.juego != NADA)
        printf(" de %s", cFiguras[resultado.figura]);
    putchar('\n');
}

void
imprimirGanadores(const tipoJugador jugadores[], int ganador) {
    int i;

    /* el siguiente ciclo se hace para el caso en que haya empate */
    printf ("\nGanadores\n");
    for (i = 0; i < CANT_JUGADORES; i++)
        if(jugadores[i].resultado.juego==jugadores[ganador].resultado.juego && jugadores[i].resultado.figura==jugadores[ganador].resultado.figura) {
            printf ("Jugador %d\n",i+1);
            jugadores[i].puntaje++;
        }
}

void
imprimirFinal(const tipoJugador jugadores[]) {
    int i;

    printf("\nPUNTAJE FINAL:\n");
    for(i = 0; i< CANT_JUGADORES; i++)
        printf("Jugador %d = %d puntos\n", i+1, jugadores[i].puntaje);
}

