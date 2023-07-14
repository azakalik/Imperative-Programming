#include <stdio.h>
#include "getnum.h"

/* Si el caracter es una letra minúscula devuelve la mayúscula, 
** sino devuelve el mismo caracter */
int minToMay(int letra);

/* Si el caracter es una letra mayúscula, devuelve la minúscula 
** sino devuelve el mismo caracter */
int mayToMin(int letra);

/* Devuelve la letra siguiente en forma circular. Si no es una letra retorna el
** caracter recibido
*/
int letraSig(int letra);

/* Devuelve el caracter siguiente */
int carSig(int letra);

/* Retorna la opción de menú elegida por el usuario */
int menu(void);

int main(void)
{
    int c, resp;
    int opcion;

    do
    {
        printf("\nIngrese un caracter (EOF para terminar):");
        c = getchar();

        if (c != EOF)
        {
            opcion = menu();

            switch (opcion)
            {
            case 1:
                resp = minToMay(c);
                break;
            case 2:
                resp = mayToMin(c);
                break;
            case 3:
                resp = carSig(c);
                break;
            case 4:
                resp = letraSig(c);
                break;
            default:
                resp = 0;
                printf("Opción inválida\n");
            }
            if (resp != 0)
                printf("Respuesta: %c (%3d)\n", resp, resp);
        }
    } while (c != EOF);
    return 0;
}

int menu(void)
{
    int opcion;

    printf("\n1 - Convertir a mayúsculas\n");
    printf("2 - Convertir a minúsculas\n");
    printf("3 - Caracter siguiente\n");
    printf("4 - Siguiente letra\n");

    opcion = getint("Ingrese una opcion:");
    return opcion;
}

int minToMay(int letra)
{
    if (letra >= 'a' && letra <= 'z')
        letra -= 'a' - 'A';
    return letra;
}

int mayToMin(int letra)
{
    if (letra >= 'A' && letra <= 'Z')
        letra += 'a' - 'A';
    return letra;
}

int carSig(int letra)
{
    return letra + 1;
}

/* La imposición de 4 líneas nos obliga a esforzarnos y escribir en forma
** no muy clara una función de 3 líneas.
** Un código más claro, de 6 líneas, podría ser:
 
int 
letraSig(int letra)
{
	if ( (letra>='A' && letra<='Z' || letra>='a' && letra <= 'z')
 	if ( letra == 'z' || letra == 'Z')
 	  	letra -= ( 'Z' - 'A');
 	else
		letra = carSig(letra);
return letra;
}
*/
int letraSig(int letra)
{
    if (!(letra >= 'A' && letra <= 'Z' || letra >= 'a' && letra <= 'z'))
        return letra;
    return (letra == 'z' || letra == 'Z') ? letra - ('Z' - 'A')
                                          : carSig(letra);
}
