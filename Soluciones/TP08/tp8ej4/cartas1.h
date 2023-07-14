#define CANT_FIGURAS 13
#define CANT_PALOS   4
#define CARTAS_MAZO  CANT_FIGURAS * CANT_PALOS
#define CARTAS_JUEGO 5

typedef struct carta {
    int numero;
    int palo;
} tipoCarta;

/* Arma un arreglo que representa un mazo de cartas francesas */
void llenarMazo(tipoCarta mazo[]);

/* Intercambia en forma aleatoria los elementos del arreglo mazo */
void mezclarMazo(tipoCarta mazo[]);
