#include <stdio.h>
#include <math.h>
#include "getnum.h"

#define SIMPLIFICAR 1
#define SUMAR 2
#define SALIR 3

typedef int Fraccion[2];
#define NUM(f) f[0]
#define DEN(f) f[1]

/* Función que lee una fracción de la entrada estándar */
void leerFrac(Fraccion frac);

/* Simplificacion de la fraccion  */
void simplFrac(Fraccion frac);

/* Calcula la suma de dos fracciones representadas por frac1, frac2 
 * Deja el resultado en frac3 
 */
void sumarFrac(const Fraccion frac1, const Fraccion frac2, Fraccion frac3);

/* Devuelve el máximo común divisor de dos números */
int dcm(int num1, int num2);

/* Imprime una fracción */
void imprimeFrac(const Fraccion frac);

/* Menú de opciones */
int menu(void);

int main(void) {
    int opcion;
    Fraccion f1, f2, f3;

    do {
        opcion = menu();

        switch (opcion) {
        case SIMPLIFICAR:
            printf("Ingrese fraccion a simplificar\n");
            leerFrac(f1);
            simplFrac(f2);
            printf("Fraccion simplificada: ");
            imprimeFrac(f1);
            break;
        case SUMAR:
            printf("Ingrese la primera fraccion\n");
            leerFrac(f1);
            printf("Ingrese la segunda fraccion\n");
            leerFrac(f2);
            sumarFrac(f1, f2, f3);
            printf("Resultado: ");
            imprimeFrac(f3);
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

void leerFrac(Fraccion frac) {
    /* Leer numerador */
    NUM(frac) = getint("Ingrese numerador: ");

    /* Leer denominador */
    while ((DEN(frac) = getint("Denominador: ")) == 0)
        printf("El denominador no puede ser cero.\n");
    return;
}

void 
simplFrac(Fraccion frac)
{
	int valor;
  valor = dcm(NUM(frac), DEN(frac));

	/* Divide el numerador y el denominador por el mcd */
	if (abs(valor) != 1)
	{
		NUM(frac) /= valor;
		DEN(frac) /= valor;
	}
}

void 
sumarFrac(const Fraccion f1, const Fraccion f2, Fraccion f3) {
	/* Calcula la suma */
	DEN(f3) = DEN(f1) * DEN(f2);
	NUM(f3) = DEN(f3) / DEN(f1) * NUM(f1) + DEN(f3) / DEN(f2) * NUM(f2);

	/* Simplifica la fracción de respuesta */
	simplFrac(f3);
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
imprimeFrac(const Fraccion f) {
	
	printf("%s%d", (NUM(f)*DEN(f) >= 0)?"":"-", abs(NUM(f)));
	if (abs(DEN(f))!=1)
		printf("/%d",abs(DEN(f)));
	putchar('\n');	
}
