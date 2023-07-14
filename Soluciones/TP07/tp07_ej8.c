/* Simulador de Bingo para dos jugadores */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "random.h"

/* La siguiente macro lee caracteres hasta que recibe un ENTER */
#define PAUSA                       \
    {                               \
        while ((getchar()) != '\n') \
            ;                       \
    }

#define BOLILLAS 90
#define LONG_LINEA 5
#define LINEAS 3

typedef int TipoLinea[LONG_LINEA];
typedef TipoLinea TipoCarton[LINEAS];

void generarCarton(TipoCarton carton);
int sacarBolilla(int bolillero[], int *cantBolillas);
int controlarCarton(TipoCarton carton, int bolilla);
void imprimirCarton(TipoCarton carton);
int buscarBolilla(TipoCarton carton, int bolilla);
int controlarLineas(TipoLinea linea);
int jugar(int bolillero[], TipoCarton carton1, TipoCarton jugador2);

int main(void)
{
    TipoCarton carton1, carton2;
    int bolillero[BOLILLAS];
    int i;

    int bingo;

    randomize();

    for (i = 0; i < BOLILLAS; i++)
        bolillero[i] = i + 1;

    generarCarton(carton1);
    generarCarton(carton2);

    bingo = jugar(bolillero, carton1, carton2);

    for (i = 1; i <= 2; i++)
        if (bingo & i)
            printf("El jugador %d hizo bingo\n", i);

    return 0;
}

int jugar(int bolillero[], TipoCarton carton1, TipoCarton carton2)
{
    int huboLinea = 0;
    int bolilla;
    int cantBolillas = BOLILLAS;
    int lineas1, lineas2;
    int bingo = 0;

    do
    {
        printf("\nJugador 1\n");
        imprimirCarton(carton1);
        printf("\nJugador 2\n");
        imprimirCarton(carton2);

        /* Extraer una bolilla */
        bolilla = sacarBolilla(bolillero, &cantBolillas);
        printf("Bolilla extraida: %d\n", bolilla);

        /* Controlar si alguno o los dos hizo linea */
        lineas1 = controlarCarton(carton1, bolilla);
        lineas2 = controlarCarton(carton2, bolilla);
        if (!huboLinea)
        {
            if (lineas1 > 0)
                printf("El jugador 1 hizo linea\n");
            if (lineas2 > 0)
                printf("El jugador 2 hizo linea\n");
            huboLinea += lineas1 + lineas2;
        }

        /* Encendemos un bit en la variable bingo por cada jugador
		** De esta forma podemos controlar si ambos hicieron bingo
		** con una sola variable 
          */
        bingo = (lineas1 == 3) | 2 * (lineas2 == 3);

        PAUSA
    } while (bingo == 0);

    return bingo;
}

void generarCarton(TipoCarton carton)
{
    int i, j;
    int n;
    int aux = BOLILLAS - 1;
    int arregloAux[BOLILLAS];

    /* Usamos un vector auxiliar para no repetir numeros.
	** En cada paso lo que se genera en forma aleatoria es el INDICE del vector
	** y no el valor de la bolila. Cada vez que se genera el indice, tomamos
 	** el valor almacenado en esa posicion, se copia el ultimo elemento a esa 
 	** posicion y se decrementa en uno la cantidad de elementos. 
 	** De esta forma es imposible que los numeros se repitan y nos aseguramos
 	** que se ejecute en forma eficiente.
 	*/
    for (i = 0; i < BOLILLAS; i++)
        arregloAux[i] = i + 1;

    for (i = 0; i < LINEAS; i++)
        for (j = 0; j < LONG_LINEA; j++)
        {
            n = randInt(0, aux);
            carton[i][j] = arregloAux[n];
            arregloAux[n] = arregloAux[aux--];
        }
}

int sacarBolilla(int bolillero[], int *cantBolillas)
{
    int aux;
    int bolilla;

    aux = randInt(1, *cantBolillas) - 1;
    (*cantBolillas)--;
    bolilla = bolillero[aux];
    bolillero[aux] = bolillero[*cantBolillas];

    return bolilla;
}

int controlarCarton(TipoCarton carton, int bolilla)
{
    int lineasCompletas = 0;

    if (buscarBolilla(carton, bolilla))
    {
        int i;
        for (i = 0; i < LINEAS; i++)
            lineasCompletas += controlarLineas(carton[i]);
    }
    return lineasCompletas;
}

void imprimirCarton(TipoCarton carton)
{
    int i, j;
    putchar('\n');
    for (i = 0; i < LINEAS; i++)
    {
        for (j = 0; j < LONG_LINEA; j++)
            if (carton[i][j])
                printf("%d\t", carton[i][j]);
            else
                printf("%c\t", 'X');
        printf("\n");
    }
}

int buscarBolilla(TipoCarton carton, int bolilla)
{
    int i, j;
    int esta = 0;
    for (i = 0; i < LINEAS && !esta; i++)
        for (j = 0; j < LONG_LINEA && !esta; j++)
            if (carton[i][j] == bolilla)
            {
                esta = 1;
                carton[i][j] = 0;
            }
    return esta;
}

int controlarLineas(TipoLinea linea)
{
    int i;
    int aciertos;
    for (i = 0, aciertos = 0; i < LONG_LINEA; i++)
        aciertos += (linea[i] == 0);
    return (aciertos == LONG_LINEA);
}
