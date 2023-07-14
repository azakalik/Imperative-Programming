#include <stdio.h>
#include <math.h>
#include "getnum.h"

/* Macro que pide un denominador distinto de cero */
#define LEER_DENOM_NO_CERO(denom)                              \
    {                                                          \
        do                                                     \
        {                                                      \
            denom = getint("");                                \
            if (denom == 0)                                    \
                printf("El denominador no puede ser cero.\n"); \
        }                                                      \
        \ 
 							while (denom == 0);                \
    }

/* Imprime la simplificación de la fracción representada por num y den */
void simplFrac(int num, int den);

/* Imprime la suma de dos fracciones representadas por num1 y den1, y num2 y den2 */
void sumarFrac(int num1, int num2, int den1, int den2);

/* devuelve el divisor común máximo de dos números */
int dcm(int num1, int num2);

int menu(void);

int main(void)
{
    int opcion;
    int num1, num2, den1, den2;

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
            num1 = getint("\nIngrese el numerador:");
            printf("\nIngrese el denominador:");
            LEER_DENOM_NO_CERO(den1)
            simplFrac(num1, den1);
            break;
        case 2:
            num1 = getint("\nIngrese el numerador de la 1ra. fracción:");
            printf("\nIngrese el denominador de la 1ra. fracción:");
            LEER_DENOM_NO_CERO(den1)
            num2 = getint("\nIngrese el numerador de la 2da. fracción:");
            printf("\nIngrese el denominador de la 2da. fracción:");
            LEER_DENOM_NO_CERO(den2)
            sumarFrac(num1, num2, den1, den2);
            break;
        case 3:
            break;
        default:
            printf("\nOpción invalida");
            break;
        }
    } while (opcion != 3);

    return 0;
}

int menu(void)
{
    int opcion;

    printf("\n1 - Simplificar una fracción");
    printf("\n2 - Sumar dos fracciones");
    printf("\n3 - Terminar");

    opcion = getint("\nElija una opción:");

    return opcion;
}

void simplFrac(int num, int den)
{
    int numAux, denAux;
    int valor;

    numAux = num;
    denAux = den;

    /* divide el numerador y el denominador por el dcm, hasta que este se haga 1 */
    if (abs((valor = dcm(num, den))) != 1)
    {
        num /= valor;
        den /= valor;
    }

    printf("\n%d/%d simplificada es %s%d", numAux, denAux,
           (num * den >= 0) ? "" : "-", abs(num));
    if (abs(den) != 1)
        printf("/%d\n", abs(den));
    return;
}

void sumarFrac(int num1, int num2, int den1, int den2)
{
    int numCom, denCom;
    int valor;

    /* Calcula la suma */
    denCom = den1 * den2;
    numCom = denCom / den1 * num1 + denCom / den2 * num2;

    /* simplifica la fracción de respuesta */
    if (abs((valor = dcm(numCom, denCom))) != 1)
    {
        numCom /= valor;
        denCom /= valor;
    }

    printf("\n%d/%d + %d/%d = %s%d/%d", num1, den1, num2, den2,
           (numCom * denCom < 0) ? "-" : "", abs(numCom), abs(denCom));
    return;
}

int dcm(int num1, int num2)
{
    int auxi;

    auxi = num1;
    while (auxi != 0)
    {
        num1 = num2;
        num2 = auxi;
        auxi = num1 % num2;
    }

    return num2;
}

/*
Una de las críticas que se puede hacer al código anterior, es que sumarFrac repite el código de simplFrac, 
ya que también simplifica la suma de las fracciones. Podría cambiarse el código de sumaFrac como se muestra debajo, 
pero en este caso la impresión de los carteles no sería la correcta. 

void 
sumarFrac(int num1, int num2, int den1, int den2)
{
	int numCom,denCom;
	int valor;
 
	/* Calcula la suma * /
	denCom = den1 * den2;
	numCom = denCom / den1 * num1 + denCom / den2 * num2;
 
	simplFrac(numCom, denCom);
 
return;
}

