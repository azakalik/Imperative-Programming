#include <stdlib.h>

#define COLS 10
#define FILS 10
#define BLOQUE 5

typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB} Tdireccion;

struct posicion {
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
};

/*
 * Recibe una matriz de char "sopa" de FILS x COLS que representa la sopa de
 * letras, un diccionario ordenado alfabéticamente (vector de strings
 * constantes donde el último elemento es un string vacío). Retorne un vector
 * de tipo struct posicion que contiene las palabras del diccionario que se
 * encontraron en la sopa de letras, donde el último elemento del vector está
 * representado por el valor NULL en el campo palabra.
 */
struct posicion * 
resolverSopa(char ** diccionario, char sopa[][COLS]) {
	int i, j, k, x, direccionesEncontradas[D_AB + 1], cantDireccionesEncontradas, dir;
	char * palabra;
	struct posicion * res = NULL; 
	//Primero recorremos el diccionario
	for(x = 0, k = 0; diccionario[x][0] != 0; x++) {
		palabra = diccionario[x];
		//Por cada palabra recorremos la matriz (sopa)
		for(i = 0; i < FILS; i++) {
			for(j = 0; j < COLS; j++) {
			   /*
				* Si la primera letra de la palabra coincide con la letra en la
				* posición (i,j) de la sopa entonces corresponde buscar en
				* todas las direcciones desde allí.
				*/
				if(palabra[0] == sopa[i][j]) {
					cantDireccionesEncontradas = buscaPalabra(i, j, palabra, sopa,
                         direccionesEncontradas);

 

					for(dir = 0; dir < cantDireccionesEncontradas; dir++) {

						// Reservamos uno mas para la marca final
						if(k % BLOQUE == 0) {
							res = realloc(res,(k + BLOQUE + 1) * sizeof(*res));
						}

						//Encontramos una palabra en la sopa en una dirección
						struct posicion elem = {palabra, i, j,
                                  direccionesEncontradas[dir]};
						res[k++] = elem;
					}
				}
			}
		}
	}
	// Agregamos el último elemento y ajustamos el vector de respuesta 
    // a la dimensión final.
    // Si no encuentra ninguna palabra res es NULL
	if (res == NULL )
		res = malloc(sizeof(*res));
	struct posicion fin = {NULL, 0, 0, 0};
	res[k++] = fin; 
	res = realloc(res, k * sizeof(*res));
	return res;
}





/*
 * Busca la palabra "palabra" en las 8 direcciones desde
 * la posición i,j de la sopa "sopa".
 * Deja en "direcciones" todas las direcciones encontradas para esa palabra
 * y retorna en su nombre la dimensión de "direcciones"
 */
int

int
buscaPalabra(int i, int j, char * palabra, char sopa[][COLS], int direcciones[]) {
	int count = 0;
	if(buscaPalabraEnDir(i,j,1,0,palabra,sopa)) {
		direcciones[count++] = ABA;
	}
	if(buscaPalabraEnDir(i,j,1,1,palabra,sopa)) {
		direcciones[count++] = D_AB;
	}
	if(buscaPalabraEnDir(i,j,0,1,palabra,sopa)) {
		direcciones[count++] = DER;
	}
	if(buscaPalabraEnDir(i,j,-1,1,palabra,sopa)) {
		direcciones[count++] = D_AR;
	}
	if(buscaPalabraEnDir(i,j,-1,0,palabra,sopa)) {
		direcciones[count++] = ARR;
	}
	if(buscaPalabraEnDir(i,j,-1,-1,palabra,sopa)) {
		direcciones[count++] = I_AR;
	}
	if(buscaPalabraEnDir(i,j,0,-1,palabra,sopa)) {
		direcciones[count++] = IZQ;
	}
	if(buscaPalabraEnDir(i,j,1,-1,palabra,sopa)) {
		direcciones[count++] = I_AB;
	}
	return count;
}


/*
 * Recorre la sopa "sopa" desde la posición inicial (i,j) de a incrementos
 * deltaX en las filas y deltaY en las columnas para encontrar cada una
 * de las letras de la palabra "palabra". Retorna 1 si la palabra fue
 * encontrada en su totalidad y 0 sino.
 */
int 
buscaPalabraEnDir(int i, int j, int deltaX, int deltaY, char * palabra, char sopa[][COLS]) {
	int k, longitudPalabra = strlen(palabra);
	for(k = 0; k < longitudPalabra && i >= 0 && j >= 0 && i < FILS && j < COLS; k++) {
		if(palabra[k] != sopa[i][j]) {
			return 0;
		}
		i += deltaX;
		j += deltaY;
	}
	return k == longitudPalabra;
}
