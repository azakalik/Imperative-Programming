#include <stdlib.h>

int suma(int numero)
{
    if (numero == 0)
        return 0;

    return abs(numero % 10) + suma(numero / 10);
}

/* Si la funcion trabajara solo con numeros positivos se podria definir
** de la siguiente forma 
*/
int sumaPos(int numero)
{
    if (numero < 10)
        return numero;

    return numero % 10 + sumaPos(numero / 10);
}
