#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "random.h"
#include "getnum.h"

#define PAUSA                       \
    {                               \
        while ((getchar()) != '\n') \
            ;                       \
    }

#define BOLILLAS 90
#define LONG_LINEA 5
#define LINEAS 3
#define MAX_JUGADORES 10

typedef int TipoLinea[LONG_LINEA];
typedef TipoLinea TipoCarton[LINEAS];

void generarCarton(TipoCarton carton);
int sacarBolilla(int bolillero[], int *cantBolillas);
int controlarCarton(TipoCarton carton, int bolilla);
void imprimirCarton(TipoCarton carton);
int buscarBolilla(TipoCarton carton, int bolilla);
int controlarLineas(TipoLinea linea);
int jugar(int bolillero[], TipoCarton cartones[], int n);

int main(void)
{
    TipoCarton cartones[MAX_JUGADORES];
    int bolillero[BOLILLAS];
    int i, jugadores;

    int bingo;

    /* setear la semilla */
    randomize();

    for (i = 0; i < BOLILLAS; i++)
        bolillero[i] = i + 1;

    /* Preguntar la cantidad de jugadores */
    do
    {
        jugadores = getint("Cantidad de jugadores (entre 1 y %d):",
                           MAX_JUGADORES);
    } while (jugadores < 1 || jugadores > MAX_JUGADORES);

    /* generar los cartones */
    for (i = 0; i < jugadores; i++)
        generarCarton(cartones[i]);

    bingo = jugar(bolillero, cartones, jugadores);

    for (i = 0; i < jugadores; i++)
        if (bingo & (1 << i))
            printf("El jugador %d hizo bingo\n", i + 1);

    return 0;
}

int jugar(int bolillero[], TipoCarton cartones[], int n)
{
    int huboLinea = 0, bolilla, cantBolillas = BOLILLAS;
    int lineas, resultado, i, bingo = 0;

    do
    {
        /* Imprimir los cartones de cada jugador */
        for (i = 0; i < n; i++)
        {
            printf("\nJugador %2d\n", i + 1);
            imprimirCarton(cartones[i]);
        }

        /* Extraer una bolilla */
        bolilla = sacarBolilla(bolillero, &cantBolillas);
        printf("Bolilla extraida: %d\n", bolilla);

        /* Controlar si alguno hizo linea */
        /* Otra opcion seria tener un vector auxiliar en donde 
		** v[I]= 1 o 0 si el jugador I hizo linea o no
		*/
        for (lineas = 0, i = 0; i < n; i++)
        {
            resultado = controlarCarton(cartones[i], bolilla);
            lineas |= resultado << i;

            /* Encendemos un bit en la variable bingo por cada jugador */
            if (resultado == 3)
                bingo |= 1 << i;
        }
        if (!huboLinea)
            for (i = 0; i < n; i++)
                if (lineas & (1 << i))
                {
                    printf("El jugador %2d hizo linea\n", i + 1);
                    huboLinea = 1;
                }
        PAUSA
    } while (bingo == 0);

    return bingo;
}
