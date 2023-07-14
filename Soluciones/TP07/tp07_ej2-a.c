#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"

#define TRUE 1
#define FALSE 0

/* Lee de la entrada estándar con el formato <n>m, donde n y m son números
** entre 2 y 10 y devuelve esos valores como parámetros 
*/
void leerBases(int *baseOrigen, int *baseDestino);

/* lee un número entero en una base determinada */
int leerNumero(int base);

/* Recibe un número entero con dígitos de una base y lo convierte a otra base,
** dejando el resultado en otro numero.
*/
int convierte(int entrada, int baseOrigen, int baseDestino);

/* Recibe un número positivo en cualquier base [2..10] y pasa a base 10 */
int pasaABase10(int entrada, int base);

/* Recibe un número positivo en base 10 y lo pasa a cualquier base [2..10] */
int pasaDeBase10(int entrada, int base);

int main(void)
{
    int base1, base2, numero, salida;

    leerBases(&base1, &base2);

    while (numero = leerNumero(base1))
    {
        salida = convierte(numero, base1, base2);
        printf("\nEl numero convertido es %d\n", salida);
    }
    return 0;
}

void leerBases(int *baseOrigen, int *baseDestino)
{
    int aux1, aux2, flag;
    do
    {
        printf("\nIngrese bases en formato <n>m: ");
        flag = scanf("<%d>%d", &aux1, &aux2);
        BORRA_BUFFER;
        if (flag == 2 && (aux1 < 2 || aux1 > 10 || aux2 < 2 || aux2 > 10))
            flag = 0;
    } while (flag != 2);

    *baseOrigen = aux1;
    *baseDestino = aux2;
}
int leerNumero(int base)
{
    int flag, aux, respuesta;

    do
    {
        respuesta = getint("Ingrese un entero en base %d (0 para terminar): ",
                           base);
        flag = TRUE;
        aux = abs(respuesta);
        while (aux > 0 && flag)
        {
            if (aux % 10 >= base)
                flag = FALSE;
            aux /= 10;
        }
        if (!flag)
            printf("Ingreso incorrecto de datos\n");
    } while (!flag);

    return respuesta;
}

int convierte(int entrada, int baseOrigen, int baseDestino)
{
    int intermedio, signo = 1;

    if (baseOrigen == baseDestino)
        return entrada;

    if (entrada < 0)
    {
        signo = -1;
        entrada *= signo;
    }

    /* Primero convierte a base 10 y luego a la base deseada */
    intermedio = pasaABase10(entrada, baseOrigen);
    intermedio = pasaDeBase10(intermedio, baseDestino);
    return intermedio * signo;

    /* Otra forma, return pasaDeBase10(paseABase10(entrada, baseOrigen), baseDestino); */
}

int pasaABase10(int entrada, int base)
{
    long auxiliar = 0, anterior = 0, potencia = 1;

    /* Convierte el numero de entrada a una variable numérica en base 10
	** Con "anterior" se valida que el calculo de "auxiliar" no genere overflow.
  */
    while (entrada > 0 && anterior <= auxiliar)
    {
        anterior = auxiliar;
        auxiliar += potencia * (entrada % 10);
        potencia *= base;
        entrada /= 10;
    }
    if (anterior <= auxiliar)
        return auxiliar;
    else
        return 0;
}
int pasaDeBase10(int entrada, int base)
{
    int digito, salida = 0;
    int potencia = 1;

    while (entrada > 0)
    {
        digito = entrada % base;
        entrada /= base;
        salida += digito * potencia;
        potencia *= 10;
    }

    return salida;
}
