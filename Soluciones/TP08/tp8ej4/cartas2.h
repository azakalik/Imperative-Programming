#ifndef __CARTAS2_H_
#define __CARTAS2_H_

#define CANT_FIGURAS   	13
#define CANT_PALOS  	4
#define CARTAS_MAZO    	CANT_FIGURAS * CANT_PALOS

/* Estructura que representa una carta */
typedef struct carta {
    int numero;
    int palo;
} tipoCarta;

/* La estructura tipoMazo encapsula el arreglo de cartas junto con un subíndice 
** (inicialmente en 0) que indica la primera carta disponible del mazo 
*/
typedef struct {
    tipoCarta cartas[CARTAS_MAZO];
    int primeraCarta;
}tipoMazo;

/* Crea un mazo de cartas (asignando un valor a cada carta y colocando el 
** índice del mazo en cero) y lo retorna en su nombre 
*/
tipoMazo armarMazo(void);

/* Intercambia en forma aleatoria las cartas del mazo */
void mezclarMazo(tipoMazo * pMazo);

/* Elimina del mazo las primeras "cant" cartas y las asigna en el arreglo juego
** Retorna en su nombre la cantidad de cartas que pudo repartir realmente 
*/
int repartir(tipoMazo * pMazo, int cant, tipoCarta juego[]);

/* Retorna la cantidad de cartas disponibles en el mazo */
int cantCartas(tipoMazo * pMazo);

#endif
