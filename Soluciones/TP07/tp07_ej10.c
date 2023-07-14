#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "random.h"

/* Macro para vaciar el buffer */
#define BORRA_BUFFER while (getchar() != '\n')

/* Cantidad máxima de errores */
#define ERRORES 8
/* Longitud máxima de una palabra */
#define LARGO_PALABRA 20

/* Función que recibe una palabra y una letra 
** En caso de que la letra pertenezca a la palabra, marca en el arreglo
** marcas las posiciones en las que figura y devuelve el valor 1. 
**/
int verificaLetra(char palabra[], char letra, short marcas[]);

/* Función que imprime las letras que ya se adivinaron */
void imprimePalabra(char palabra[], short marcas[]);

/* Función que lee una letra del alfabeto inglés */
char leerLetra(void);

/* Devuelve 1 si la palabra esta completa, 0 en caso contrario. Una palabra está completa 
** si todas sus letras están marcadas. Otra forma de escribirla sería pasando solamente 
** marcas y la cantidad de elementos, definiéndola de la siguiente forma:
**      int palabraCompleta(short marcas[], int n)
** invocarla de la siguiente forma:
**      if (palabraCompleta(marcas, strlen(palabra));
**/
int palabraCompleta(char palabra[], short marcas[]);

int main(void)
{
    char diccionario[][LARGO_PALABRA] = {"occidente", "explorar",
                                         "calvinista", "autista", "ausencia", "dependencia", "cefalopodo",
                                         "mendigo", "sinusitis", "eficiencia", "borrador"};
    char letra, *palabra;
    int errores = 0, cantPalabras;
    short marca[LARGO_PALABRA] = {0};

    cantPalabras = sizeof(diccionario) / LARGO_PALABRA;

    /* Inicializar semilla para números aleatorios */
    randomize();

    /* Elegir una palabra al azar */
    palabra = diccionario[randInt(0, cantPalabras - 1)];

    printf("\nBienvenido al juego del ahorcado\n");
    printf("Solamente se aceptaran letras del alfabeto ingles\n");

    do
    {
        imprimePalabra(palabra, marca);
        letra = leerLetra();
        if (!verificaLetra(palabra, letra, marca))
        {
            errores++;
            if (ERRORES - errores > 0)
                printf("\nERROR\tPosibilidades:%d\n", ERRORES - errores);
        }
        putchar('\n');
    } while (errores < ERRORES && !palabraCompleta(palabra, marca));

    if (errores == ERRORES)
        printf("\n\nLo siento, la palabra era %s\n", palabra);
    else
        printf("\n\nFelicitaciones\n\n");

    return 0;
}
char leerLetra(void)
{
    char letra;
    do
    {
        printf("Ingrese una letra: ");
        letra = tolower(getchar());
        if ( letra != '\n')
            BORRA_BUFFER;
    } while (!islower(letra));
    return letra;
}

int verificaLetra(const char palabra[], char letra, short marcas[])
{
    int i, pertenece = 0;

    /* Se debe recorrer toda la palabra, pues una letra puede aparecer más de una vez */
    for (i = 0; palabra[i]; i++)
        if (palabra[i] == letra)
        {
            pertenece = 1;
            marcas[i] = 1;
        }
    return pertenece;
}

void imprimePalabra(const char palabra[], const short marcas[])
{
    int i;

    for (i = 0; palabra[i]; i++)
    {
        if (marcas[i])
            putchar(palabra[i]);
        else
            putchar('_');
        putchar(' ');
    }
    putchar('\n');
}
int palabraCompleta(const char palabra[], const short marcas[])
{
    int i, completa = 1;

    for (i = 0; palabra[i] && completa; i++)
        if (marcas[i] == 0)
            completa = 0;

    return completa;
}
