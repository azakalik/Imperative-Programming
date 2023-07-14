#include <stdio.h>
#define TOPE 100

int main(void)
{
    int i, j, invertido, cantCiclos = 0;
    int numDec, numAux, numAct;
    int uno, cinco, diez;

    printf("%-20s%-20s\n", "Num. Decimal", "Num. Romano");
    for (numDec = 1; numDec <= TOPE; numDec++)
    {
        numAux = numDec;
        printf("%-20d", numDec);
        /*
		** Se invierten los dígitos para poder analizar desde el dígito
		** de mayor peso hacia el de menor peso
		*/
        invertido = 0;
        cantCiclos = 0;
        while (numAux > 0)
        {
            invertido = invertido * 10 + (numAux % 10);
            numAux /= 10;
            cantCiclos++;
        }
        numAux = invertido;

        /* Se analiza cada dígito, empezando por el mayor */
        for (i = cantCiclos - 1; i >= 0; i--)
        {
            switch (i) /* Se preparan los caracteres necesarios para la posición */
            {
            case 0:
                uno = 'I';
                cinco = 'V';
                diez = 'X';
                break;
            case 1:
                uno = 'X';
                cinco = 'L';
                diez = 'C';
                break;
            case 2:
                uno = 'C';
                cinco = 'D';
                diez = 'M';
                break;
            }

            numAct = (numAux % 10); /* dígito para analizar */
            numAux = numAux / 10;   /* el resto, en la vuelta siguiente */

            /* Si el dígito involucra una "resta" */
            if (numAct == 4 || numAct == 9)
                printf("%c%c", uno, numAct == 4 ? cinco : diez);
            else /* Si solo se suma */
            {
                if (numAct >= 5)
                {
                    printf("%c", cinco);
                    numAct -= 5;
                }
                for (j = 0; j != numAct; j++)
                    printf("%c", uno);
            }
        }
        putchar('\n');
    }
    return 0;
}
