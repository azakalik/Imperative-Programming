#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "getnum.h"
#include "random.h"

#define MAXNIVEL 10

void generaAleatorio(int incognita[], int digitos);
int elegirNivel(void);
void leerNumero(int numero[], int digitos);
int coincideNumero(int incognita[], int numero[], int digitos);
int cantidadBien(int incognita[], int numero[], int digitos);
int cantidadRegular(int incognita[], int numero[], int digitos);

int main(void)
{
    int incognita[9], numero[9];
    int digitos, nivel, i;
    int acierto = 0; /* Flag para indicar que el jugador adivino */

    randomize();

    nivel = elegirNivel();
    putchar('\n');

    /* Pedir al usuario la cantidad de dígitos (entre 1 y 9) */
    do
    {
        digitos = getint("Cantidad de digitos: ");
    } while (digitos <= 0 || digitos > 9);

    generaAleatorio(incognita, digitos);

    for (i = 1; i <= nivel && !acierto; i++)
    {
        leerNumero(numero, digitos);
        acierto = coincideNumero(incognita, numero, digitos);
    }
    if (acierto)
        printf("\nAdivinaste el numero en %d pasos\n", i - 1);
    else
    {
        printf("\nLo siento, el numero es ");
        for (i = 0; i < digitos; i++)
            printf("%d", incognita[i]);
        putchar('\n');
    }

    return 0;
}

void generaAleatorio(int incognita[], int digitos)
{
    /* Armamos un arreglo auxiliar con los números del 1 al 9 
** Cada número que sale se lo reemplaza por el último elemento y se "achica" 
** el arreglo. De esta forma aseguramos que en  cada oportunidad el número 
** elegido no salió anteriormente, haciendo eficiente el algoritmo
*/
    int arregloAux[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9, i, numAux;

    for (i = 0; i < digitos; i++)
    {
        numAux = randInt(0, n - 1);
        incognita[i] = arregloAux[numAux];
        arregloAux[numAux] = arregloAux[--n];
    }
}

int elegirNivel(void)
{
    int n;
    do
        n = getint("Cantidad de opciones: ");
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

int coincideNumero(const int incognita[], const int numero[], int digitos)
{
    int bien, regular;
    bien = cantidadBien(incognita, numero, digitos);

    if (bien == digitos)
        return 1;

    regular = cantidadRegular(incognita, numero, digitos);

    printf("Bien:    %d\n", bien);
    printf("Regular: %d\n", regular);

    return 0;
}

int cantidadBien(const int incognita[], const int numero[], int digitos)
{
    int i;
    int bien = 0;
    for (i = 0; i < digitos; i++)
        bien += (incognita[i] == numero[i]);
    return bien;
}

int cantidadRegular(const int incognita[], const int numero[], int digitos)
{
    int i, j;
    int regular = 0;

    for (i = 0; i < digitos; i++)
        for (j = 0; j < digitos; j++)
            if (i != j)
                regular += (incognita[i] == numero[j]);

    return regular;
}
