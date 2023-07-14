#include <stdlib.h>
#include <stdio.h>

int
main(void) {

        char * p = malloc(10);

        // En la siguiente linea estaba accediendo a un byte fuera del bloque reservado
        for(int i=0; i < 10; i++)
                p[i] = i * 10;

        // En la siguiente linea estaba accediendo a un byte fuera del bloque reservado
        for(int i=0; i < 10; i++)
                printf("%d\n", p[i]);

        // Faltaba liberar la memoria reservada
        free(p);

        return 0;
}
