// Rta dada por ChatGPT

#include <stdio.h>
#define VOLUMEN(r) (4.0/3.0*3.14159*(r)*(r)*(r))

int main()
{
    int radio;
    printf("Radio\tVolumen\n");
    for(radio=1; radio<=10; radio++){
        printf("%d\t%.2f\n", radio, VOLUMEN(radio));
    }
    return 0;
}

/*
Explicación:

La macro VOLUMEN se define para calcular el volumen de una esfera dada su radio r. La fórmula utilizada es (4.0/3.0*3.14159*(r)*(r)*(r)).
En la función main, se declara una variable radio y se imprime una cabecera para la tabla que se va a mostrar.
Se utiliza un bucle for para iterar a través de los radios del 1 al 10. Dentro del bucle, se utiliza printf para imprimir el radio actual y el volumen calculado utilizando la macro VOLUMEN.
Se retorna 0 para indicar que el programa ha finalizado correctamente.
*/