#include <stdio.h>

#define DELTA ('a' - 'A')

int main(void)
{
    int car;
    int menor = 'z';
    int cantMay = 0, cantMin = 0;
    int eraMay = 0, esMay;

    /* Lee caracteres de la entrada estándar mientras no sea fin de entrada y
    *  sea una letra ( mayúscula o minúscula ) del alfabeto ingles 
    */
    while ((car = getchar()) >= 'A' && car <= 'Z' || car >= 'a' && car <= 'z' || car == ' ')
    {
        if (car != ' ')
        {
            if (esMay = (car >= 'A' && car <= 'Z'))
            {
                cantMay++;
                car += DELTA;
            }
            else
                cantMin++;

            if (car < menor)
            {
                menor = car;
                eraMay = esMay;
            }
        }
    }

    if (cantMin + cantMay > 0)
    {
        printf("\nLa letra menor era: %c\n Cantidad de mayúsculas: %d\n"
               "Cantidad de minúsculas: %d\n",
               eraMay ? menor - DELTA : menor, cantMay, cantMin);
    }
    else
        puts("\nNo se han ingresado letras");

    return 0;
}
