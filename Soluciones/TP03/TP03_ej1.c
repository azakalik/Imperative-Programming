#include <stdio.h>
int main(void)
{
    int letra;
    printf("Ingresar un caracter: ");
    letra = getchar();
    if (letra >= 'A' && letra <= 'Z')
        printf("\nEs una letra mayúscula\n");
    else if (letra >= 'a' && letra <= 'z')
        printf("\nEs una letra minúscula\n");
    else
        printf("\nNo es una letra\n");
    return 0;
}