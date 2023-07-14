#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "getnum.h"
#include "random.h" /* Utiliza la biblioteca random desarrollada en clase teórica */

#define PAUSA                       \
    {                               \
        while ((getchar()) != '\n') \
            ;                       \
    }
#define DIGITOS 5
#define MAXNIVEL 10

void generaAleatorio(int incognita[]);
int elegirNivel(void);
void leerNumero(int numero[]);
int coincideNumero(int incognita[], int numero[]);
int cantidadBien(int incognita[], int numero[]);
int cantidadRegular(int incognita[], int numero[]);

int main(void)
{
    int incognita[DIGITOS], numero[DIGITOS];
    int acierto = 0; /* Flag para indicar que el jugador adivinó */
    int paso, i, nivel;

    randomize();

    nivel = elegirNivel();

    generaAleatorio(incognita);

    for (paso = 0; paso < nivel && !acierto; paso++)
    {
        printf("Queda%s %d oportunidad%s\n", (nivel - paso > 1) ? "n" : "",
               nivel - paso, (nivel - paso > 1) ? "es" : "");
        leerNumero(numero);
        acierto = coincideNumero(incognita, numero);
    }
    if (acierto)
        printf("\nAdivinaste el numero en %d pasos\n", paso);
    else
    {
        printf("\nLo siento, el numero es ");
        for (i = 0; i < DIGITOS; i++)
            printf("%d", incognita[i]);
        printf("\n");
    }

    return 0;
}

void generaAleatorio(int incognita[])
{
    /* Armamos un arreglo auxiliar con los números del 1 al 9 
** Cada número que sale se lo reemplaza por el último elemento y se "achica" 
** el arreglo. De esta forma aseguramos que en cada oportunidad el número 
** elegido no salió anteriormente, haciendo eficiente el algoritmo.
*/
    int arregloAux[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9, i, numAux;

    for (i = 0; i < DIGITOS; i++)
    {
        numAux = randInt(0, n - 1);
        incognita[i] = arregloAux[numAux];
        arregloAux[numAux] = arregloAux[--n];
    }
    return;
}

int elegirNivel(void)
{
    int n;
    do
        n = getint("\nIngrese cantidad de chances: ");
    while (n < 1 || n > MAXNIVEL);
    return n;
}

void leerNumero(int numero[])
{
    int i, j, num, numOK;

    do
    {
        num = getint("Ingrese un numero de %d dígitos del 1 al 9 sin repetir:",
                     DIGITOS);
        for (i = DIGITOS - 1, numOK = 1; i >= 0 && numOK; i--, num /= 10)
        {
            numero[i] = num % 10;
            if (numero[i] == 0)
                numOK = 0;
            else
                for (j = DIGITOS - 1; j > i && numOK; j--)
                    if (numero[i] == numero[j])
                        numOK = 0;
        }
    } while (!numOK || num != 0);
    /*Si num!=0 entonces el número tenía dígitos de más */

    return;
}
int coincideNumero(const int incognita[], int numero[])
{
    int bien, regular;
    bien = cantidadBien(incognita, numero);

    if (bien == DIGITOS)
        return 1;

    regular = cantidadRegular(incognita, numero);

    printf("Bien:    %d\n", bien);
    printf("Regular: %d\n", regular);

    return 0;
}

int cantidadBien(const int incognita[], int numero[])
{
    int i;
    int bien = 0;
    for (i = 0; i < DIGITOS; i++)
        bien += (incognita[i] == numero[i]);
    return bien;
}

int cantidadRegular(const int incognita[], int numero[])
{
    int i, j;
    int regular = 0;

    for (i = 0; i < DIGITOS; i++)
        for (j = 0; j < DIGITOS; j++)
            if (i != j)
                regular += (incognita[i] == numero[j]);

    return regular;
}
