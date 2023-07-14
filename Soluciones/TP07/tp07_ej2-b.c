#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BORRA_BUFFER while (getchar() != '\n')

/* Máxima cantidad de dígitos de un número */
#define MAX_DIGIT 40

/* Lee de la entrada estándar con el formato <n>m, donde n y m son números
** entre 2 y 10 y devuelve esos valores como parámetros 
*/
void leerBases(int *baseOrigen, int *baseDestino);

/* Lee en un string un número entero en una base determinada
** si el número ingresado es 0 devuelve 0, 1 en caso contrario 
*/
int leerNumero(char numero[], int base);

/* Recibe un string con dígitos de una base y lo convierte a otra base, dejando el 
** resultado en otro string. En caso de poder convertir devuelve 1, 0 si no 
*/
int convierte(char entrada[], int baseOrigen, int baseDestino,
              char salida[]);

/* Recibe un string en cualquier base [2..10] y pasa a base 10 */
int pasaABase10(char entrada[], int base, char salida[]);

/* Recibe un string en base 10 y lo pasa a cualquier base [2..10] */
int pasaDeBase10(char entrada[], int base, char salida[]);

int main(void)
{
    char entrada[MAX_DIGIT+1], salida[MAX_DIGIT];
    int base1, base2;

    leerBases(&base1, &base2);

    while (leerNumero(entrada, base1))
    {
        if (convierte(entrada, base1, base2, salida))
            printf("\nEl numero convertido es %s\n", salida);
        else
            printf("\nNumero fuera del rango representable\n");
    }
    return 0;
}

void leerBases(int *baseOrigen, int *baseDestino)
{
    int aux1, aux2, cant;
    do
    {
        printf("\nIngrese bases en formato <n>m: ");
        cant = scanf("<%d>%d", &aux1, &aux2);
        BORRA_BUFFER;
        if (cant == 2 && (aux1 < 2 || aux1 > 10 || aux2 < 2 || aux2 > 10))
            cant = 0;
    } while (cant != 2);

    *baseOrigen = aux1;
    *baseDestino = aux2;
}

int leerNumero(char numero[], int base)
{
    int flag, i;
    char formato[6];

    /* Armar el string de formato para leer un máximo de caracteres
	** Formato tendrá por ejemplo el siguiente contenido:  "%4s" o "%6s", etc */
    sprintf(formato, "%%%ds", MAX_DIGIT);
    do
    {
        printf("Ingrese un entero en base %d (0 para terminar): ", base);
        flag = scanf(formato, numero);
        BORRA_BUFFER;
        if (flag)
        {
            for (i = 0; numero[i] && flag; i++)
                if (numero[i] < '0' || numero[i] >= base + '0')
                    flag = 0;
        }
        if (!flag)
            printf("Ingreso incorrecto de datos\n");
    } while (flag != 1);

    /* si el numero es 0, se considera finalizada la entrada */
    flag = strcmp(numero, "0") == 0 ? 0 : 1;
    return flag;
}

int convierte(char entrada[], int baseOrigen, int baseDestino, char salida[])
{
    char intermedio[MAX_DIGIT];
    int flag;

    /* Primero convierte a base 10 y luego a la base deseada */
    if (flag = pasaABase10(entrada, baseOrigen, intermedio))
        flag = pasaDeBase10(intermedio, baseDestino, salida);
    return flag;
}

int pasaABase10(char entrada[], int base, char salida[])
{
    int i;
    long auxiliar = 0, anterior = 0, potencia = 1;

    /* Convierte el número de entrada a una variable numérica en base 10
	** Con anterior se valida que el cálculo de auxiliar no genere overflow 
*/
    for (i = strlen(entrada) - 1; i >= 0 && anterior <= auxiliar; i--)
    {
        anterior = auxiliar;
        auxiliar += potencia * (entrada[i] - '0');
        potencia *= base;
    }

    if (anterior <= auxiliar)
    {
        sprintf(salida, "%ld", auxiliar); /* paso a string */
        return 1;
    }
    else
        return 0;
}

int pasaDeBase10(char entrada[], int base, char salida[])
{
    long auxiliar;
    int i, j, digito;
    char aux;

    auxiliar = atol(entrada);

    /* Guardar los restos en orden inverso al correcto */
    for (i = 0; auxiliar >= base && i < MAX_DIGIT; i++)
    {
        digito = auxiliar % base;
        auxiliar /= base;
        salida[i] = digito + '0';
    }
    if (i == MAX_DIGIT)
        return 0; /* No alcanza la longitud del string */

    salida[i] = auxiliar + '0';
    salida[i + 1] = 0;

    /* Invertir el string de resultado */
    for (j = 0; j <= i / 2; j++)
    {
        aux = salida[j];
        salida[j] = salida[i - j];
        salida[i - j] = aux;
    }
    return 1;
}
