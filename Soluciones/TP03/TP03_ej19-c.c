#include <stdio.h>
#define DIGITO '5'

int main(void)
{
    int c;
    int huboPunto = 0;
    int cntInt = 0;
    int cntDec = 0;

    printf("\nIngrese un número real: ");
    while (((c = getchar()) >= '0' && c <= '9') ||
           (c == '.' && !huboPunto))
    {
        if (c >= '0' && c <= '9')
        {
            if (c == DIGITO)
                (huboPunto) ? cntDec++ : cntInt++;
        }
        else
            huboPunto = 1;
    }
    printf("\nDigitos iguales a %c en parte entera: %d\n",
           DIGITO, cntInt);
    printf("Digitos iguales a %c en parte decimal: %d\n", DIGITO, cntDec);

    return 0;
}
