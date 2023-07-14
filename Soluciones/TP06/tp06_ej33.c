#include <ctype.h>

// Incluimos la biblioteca de numeros aleatorios vista en clase 
#include "random.h"

void crearAlfabeto(char alfa[]);

void codificar(const char *fuente, char alfa[], char *destino);

void decodificar(const char *fuente, char alfa[], char *destino);

/* Funcion auxiliar que busca un caracter en el alfabeto */
static int posicionAlfa(char alfa[], int letra);

/* Funcion auxiliar que mezcla los elementos de un arreglo */
static void desordenaArreglo(char arreglo[], int dim);

void crearAlfabeto(char alfa[])
{
    int i;

    for (i = 0; i < MAX; i++)
        alfa[i] = 'A' + i;
    desordenaArreglo(alfa, MAX);
    return;
}

static void
desordenaArreglo(char arreglo[], int dim)
{
    int i, j, aux;
    static int primerRandom = 0;
    if ( !primerRandom ) {
        randomize();
        primerRandom = 1;
    }
    for (i = 0; i < dim; i++)
    {
        j = randInt(0, dim);
        aux = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = aux;
    }
    return;
}

void codificar(const char *fuente, char alfa[], char *destino)
{
    while (*fuente)
        if (isalpha(*fuente))
        {
            *destino++ = alfa[toupper(*fuente) - 'A'];
            fuente++;
        }
        else
            *destino++ = *fuente++;

    *destino = 0;
    return;
}

void decodificar(const char *fuente, char alfa[], char *destino)
{
    while (*fuente)
        if (isalpha(*fuente))
        {
            /* Se debe buscar la letra en el alfabeto */
            *destino++ = posicionAlfa(alfa, toupper(*fuente)) + 'A';
            fuente++;
        }
        else
            *destino++ = *fuente++;

    *destino = 0;
    return;
}

static int
posicionAlfa(char alfa[], int letra)
{
    int i;
    for (i = 0; alfa[i] != letra && alfa[i]; i++)
        ;

    /* Si no se encontro, devolver -1 */
    return (alfa[i] != '\0') ? i : -1;
}
