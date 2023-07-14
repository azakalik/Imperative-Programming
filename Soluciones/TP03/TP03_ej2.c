#include <stdio.h>
int main(void)
{
    int a, b;
    printf("Ingresar dos caracteres (sin espacios entre ambos): ");
    a = getchar();
    b = getchar();
    if (a > b)
        printf("\nEl caracter '%c' es mayor al caracter '%c'\n", a, b);
    else if (a < b)
        printf("\nEl caracter '%c' es menor al caracter '%c'\n", a, b);
    else
        printf("\nEl caracter '%c' es igual al caracter '%c'\n", a, b);
    return 0;
}