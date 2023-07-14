//
// Created by BraveJero on 6/14/23.
//

#include "polyADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct polyCDT {
    int degree;
    float coef;
    struct polyCDT * tail;
} polyCDT;


polyADT newPolynomial(void) {
    return NULL;
}

int isEmpty(polyADT poly) {
    return poly == NULL;
}

static polyADT addTermRec(polyADT poly, float coef, int degree, int *exists) {
    if (isEmpty(poly) || poly->degree < degree) {
        polyADT newCoef = malloc(sizeof(polyCDT));
        newCoef->degree = degree;
        newCoef->coef = coef;
        newCoef->tail = poly;
        return newCoef;
    }
    if (poly->degree == degree) {
        *exists = 1;
        return poly;
    }
    poly->tail = addTermRec(poly->tail, coef, degree, exists);
    return poly;
}

int addTerm(polyADT *poly, float coef, int degree) {
    int exists = 0;
    *poly = addTermRec(*poly, coef, degree, &exists);
    return !exists;
}

/*
 * Suma los polinomios enviados como parametro y obtiene un nuevo polinomio.
 * En caso de error retorna NULL
 * */
polyADT addPolynomial(polyADT p, polyADT q) {
    if (p == NULL && q == NULL) return NULL;
    if (q == NULL) {
        return addPolynomial(q, p);
    }
    polyADT newCoef = malloc(sizeof(polyCDT));
    if (p == NULL || q->degree > p->degree) {
        newCoef->coef = q->coef;
        newCoef->degree = q->degree;
        newCoef->tail = addPolynomial(p, q->tail);
        return newCoef;
    }
    if (q->degree < p->degree) {
        newCoef->coef = p->coef;
        newCoef->degree = p->degree;
        newCoef->tail = addPolynomial(p->tail, q);
        return newCoef;
    }
    newCoef->coef = p->coef + q->coef;
    newCoef->degree = p->degree;
    newCoef->tail = addPolynomial(p->tail, q->tail);
    return newCoef;
}

