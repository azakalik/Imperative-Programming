#include <stdio.h>
#include <math.h>
#include "getnum.h"

#define SIMPLIFICAR 1
#define SUMAR 2
#define SALIR 3

/* Función que lee una fracción de la entrada estándar */
void leerFrac(int *num, int *den);

/* Simplificación de la fracción representada por num y den */
void simplFrac(int *num, int *den);

/* Calcula la suma de dos fracciones representadas por num1 / den1, num2 / den2 
 * Deja el resultado en numS / denS 
 */
void sumarFrac(int num1, int num2, int den1, int den2, int *mumS, int *denS);

/* Devuelve el máximo común divisor de dos números */
int dcm(int num1, int num2);

/* Imprime una fracción */
void imprimeFrac(int num, int den);

/* Menú de opciones */
int menu(void);

int main(void) {
    int opcion;
    int num1, num2, den1, den2, numS, denS;

    do {
        opcion = menu();

        switch (opcion) {
        case SIMPLIFICAR:
            printf("Ingrese fraccion a simplificar\n");
            leerFrac(&num1, &den1);
            simplFrac(&num1, &den1);
            printf("Fraccion simplificada: ");
            imprimeFrac(num1, den1);
            break;
        case SUMAR:
            printf("Ingrese la primera fraccion\n");
            leerFrac(&num1, &den1);
            printf("Ingrese la segunda fraccion\n");
            leerFrac(&num2, &den2);
            sumarFrac(num1, num2, den1, den2, &numS, &denS);
            printf("Resultado: ");
            imprimeFrac(numS, denS);
            break;
        case SALIR:
            break;
        default:
            printf("\nOpción invalida");
            break;
        }
    } while (opcion != 3);

    return 0;
}

int menu(void) {
    int opcion;

    printf("\n1 - Simplificar una fracción");
    printf("\n2 - Sumar dos fracciones");
    printf("\n3 - Terminar");

    opcion = getint("\nElija una opción:");

    return opcion;
}

void leerFrac(int *num, int *den) {
    /* Leer numerador */
    *num = getint("Ingrese numerador: ");

    /* Leer denominador */
    while ((*den = getint("Denominador: ")) == 0)
        printf("El denominador no puede ser cero.\n");
    return;
}

void 
simplFrac(int * num, int * den)
{
	int valor;

	/* Divide el numerador y el denominador por el mcd */
	if (abs(( valor = dcm(*num, *den))) != 1)
	{
		*num /= valor;
		*den /= valor;
	}
}

void 
sumarFrac(int num1, int num2, int den1, int den2, int* numS, int* denS) {
	/* Calcula la suma */
	*denS = den1 * den2;
	*numS = *denS / den1 * num1 + *denS / den2 * num2;

	/* Simplifica la fracción de respuesta */
	simplFrac(numS, denS);
}

int
dcm ( int num1, int num2) {
	int auxi ;

	auxi = num1;
	while (auxi!=0)
	{
		num1 = num2;
		num2 = auxi;
		auxi = num1 % num2 ;
	}

	return num2;
}

void 
imprimeFrac(int num, int den) {
	
	printf("%s%d", (num*den >= 0)?"":"-", abs(num));
	if (abs(den)!=1)
		printf("/%d",abs(den));
	putchar('\n');	
}
