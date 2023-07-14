#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "phrasesADT.h"

typedef struct phrase {
    size_t len;              // Guardamos la longitud, para no usar strlen
    char * s;
} phrase;

struct phrasesCDT {
    size_t keyLow;
    size_t keyHigh;
    size_t size;     // cantidad de frases almacenadas
    phrase * phrases;
};

phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo) {
    if ( keyTo < keyFrom) {
        return NULL;
    }
    phrasesADT aux = malloc(sizeof (struct phrasesCDT));
    aux->keyLow = keyFrom;
    aux->keyHigh = keyTo;
    aux->size = 0;
    aux->phrases = calloc(keyTo-keyFrom+1, sizeof(phrase));
    return aux;
}

void freePhrases(phrasesADT ph) {
    for(size_t i=0; i < ph->keyHigh - ph->keyLow + 1; i++) {
        free(ph->phrases[i].s);
    }
    free(ph->phrases);
    free(ph);
}

#define BLOCK 20

// Recibe un string (puede ser NULL), la cantidad de bytes ya reservados y de ser necesario va creando mas espacio
// Si estamos trabajando con strings extensos no seria eficiente usar
// directamente strlen y malloc, por lo que copiamos de a bloques
static char * copy(char * s, const char *newS, size_t * len ) {
    char * ans = s;
    
    size_t reserved = *len;
    size_t i;
    for (i = 0; newS[i] != 0; i++) {
        // Si ya usamos todo el string original, entonces agrandamos
        if ( i == reserved) {
            reserved += BLOCK;
            ans = realloc(ans, reserved);
        }
        ans[i] = newS[i];
    }
    ans = realloc(ans, i+1);     // liberamos lo que usamos de mas
    ans[i]=0;
    *len = i; 
    return ans;
}

int put(phrasesADT ph, size_t key, const char * phrase) {
    if ( key < ph->keyLow || key > ph->keyHigh) {
        return 0;
    }
    size_t i = key - ph->keyLow;
    if ( ph->phrases[i].s == NULL) {
        ph->size++;
    }
    ph->phrases[i].s = copy(ph->phrases[i].s, phrase, &(ph->phrases[i].len));
    
    return 1;
}

char * get(const phrasesADT ph, size_t key) {
    if ( key < ph->keyLow || key > ph->keyHigh) {
        return 0;
    }
    size_t i = key-ph->keyLow;
    if ( ph->phrases[i].s == NULL) {
        return NULL;
    }
    char * ans = malloc(ph->phrases[i].len +1);
    strcpy(ans, ph->phrases[i].s);
    return ans;
}

size_t size(const phrasesADT ph) {
    return ph->size;
}

// Funcion auxiliar para usar tanto en concat como en concatAll
static char * copyPhrases(phrase v[], size_t from, size_t to) {
    // tenemos la longitud de cada una, podemos hacer reallocs por cada frase y strcpy de cada una
    char * ans = NULL;
    size_t total = 0;
    for(size_t i=from; i<=to; i++) {
        size_t add = v[i].len;
        if ( add > 0) {
            ans = realloc(ans, total + add + 1);
            // podriamos usar strcat pero seria ineficiente, ya sabemos donde esta el final
            strcpy(ans + total, v[i].s);
            total += add;
        }
    }
    if (total==0) {
        ans = malloc(1);
        *ans=0;
    }
    return ans;
}


char * concatAll(const phrasesADT ph) {
    return copyPhrases(ph->phrases, 0, ph->keyHigh - ph->keyLow);
}

char * concat(const phrasesADT ph, size_t from, size_t to) {
    if ( from < ph->keyLow || to > ph->keyHigh || from > to) {
        return NULL;
    }
    return copyPhrases(ph->phrases, from - ph->keyLow, to - ph->keyLow);
}