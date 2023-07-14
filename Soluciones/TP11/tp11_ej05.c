#include "tp11_ej05.h"
#include <stdio.h>
#include <stdlib.h>

/* ----- Definicion del tipo de dato -------- */
typedef struct complejoCDT {
    float real;
    float im;
    }complejoCDT;

/* ----- Operaciones disponibles sobre el TAD ------- */
complejoADT
nuevoComp (float real, float im) {
complejoADT nuevo;
if ((nuevo = malloc (sizeof (complejoCDT)))==NULL)
    return NULL;
nuevo->real = real;
nuevo->im = im;
return nuevo;
}

complejoADT
sumaComp (complejoADT num1, complejoADT num2) {
    complejoADT resultado;
    resultado = nuevoComp(num1->real + num2->real, num1->im + num2->im);
    return resultado;
}

complejoADT
restaComp (complejoADT num1, complejoADT num2) {
    complejoADT resultado;
    resultado = nuevoComp(num1->real - num2->real, num1->im - num2->im);
    return resultado;
}

complejoADT
multiplicaComp (complejoADT num1, complejoADT num2) {
    complejoADT resultado;
    float real;
    float im;
    real = num1->real * num2->real - num1->im * num2->im;
    im = num1->real * num2->im + num1->im * num2->real;
    resultado = nuevoComp(real,im);

    return resultado;
}

complejoADT
divideComp (complejoADT num1, complejoADT num2) {
    complejoADT resultado;
    float denominador;
    float real;
    float im;
    if (num2->real == 0 && num2->im == 0)
        return NULL;
    denominador = num2->real * num2->real + num2->im * num2->im;
    real = num1->real * num2->real + num1->im * num2->im;
    im = - num1->real * num2->im + num1->im * num2->real;
    real /= denominador;
    im /= denominador;
    resultado = nuevoComp(real, im);
    return resultado;
}

complejoADT
conjugadoComp (complejoADT num) {
    num->im = -(num->im);
    return num;
}

float
parteRealComp (complejoADT num) {
    return num->real;
}

float
parteImagComp (complejoADT num) {
    return num->im;
}

void
mostrarComp(complejoADT num) {
    if (num != NULL)
        printf("%.2f + %.2f i\n", num->real, num->im);
    else
        fprintf(stderr, "No existe numero\n");
}

void
liberaComp(complejoADT num) {
    free(num);
}
