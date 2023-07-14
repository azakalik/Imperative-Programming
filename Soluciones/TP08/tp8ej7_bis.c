#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define COLS 7
#define FILS 6
#define BLOQUE 10

typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB} Tdireccion;

typedef struct posicion {
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
} posicion;

int buscaEnDireccion(const char *palabra, char sopa[][COLS], size_t f, size_t c, int inc_f, int inc_c) {
    int idx = 0;
    size_t i = f;
    size_t j = c;
    while ( palabra[idx] != 0 && i >= 0 && i < FILS && j >=0 && j < COLS && palabra[idx]==sopa[i][j] ) {
        i += inc_f;
        j += inc_c;
        idx++;
    }
    return palabra[idx]==0;
}

posicion * buscaPalabra(const char *palabra, char sopa[][COLS], size_t f, size_t c, posicion * res, size_t *idx) {
    static int vec_mov[][2]= { {0,1}, {0, -1}, {1,0}, {-1,0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1} }; 
    for (int i=DER; i <= D_AB; i++) {
        if ( buscaEnDireccion(palabra, sopa, f, c, vec_mov[i][0], vec_mov[i][1])) {
            if ( *idx % BLOQUE == 0)
                res = realloc( res, (*idx + BLOQUE) * sizeof(*res));
            posicion aux = {palabra, f, c, i};
            res[*idx] = aux;
            (*idx)++;
        }
    }
    return res;
        
}

posicion * buscaLetra( char sopa[][COLS], const char *palabra, posicion * res, size_t *idx) {
    for (size_t i=0; i < FILS; i++) {
        for (size_t j=0; j < COLS; j++) {
            if ( sopa[i][j] == palabra[0]) {
                res = buscaPalabra(palabra, sopa, i, j, res, idx);
            }
        }
    }
    return res;
}

posicion * resolverSopa(char *diccionario[], char sopa[][COLS]) {
    posicion * resp = NULL;
    size_t idx=0;
    
    for(int i=0; diccionario[i][0] != 0; i++) {
        resp = buscaLetra(sopa, diccionario[i], resp, &idx);
    }
    
    resp = realloc(resp, (idx + 1) * sizeof(posicion));
    
    resp[idx] = (posicion) {NULL,0,0,0};
    
    return resp;
}


// NOTA: depende del orden en que realizan la busqueda, el testeo puede dar diferente
//       en esta prueba asumimos que se recorre el diccionario, y cada palabra se busca en la sopa de 
//       letras.
int main(void) {
  char * diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};
   
  char sopa[FILS][COLS] =
     {{'X','X','X','O','X','X','X'},
      {'A','P','A','C','Y','Y','O'},
      {'Z','E','Z','R','Z','C','X'},
      {'E','R','R','O','R','X','X'},
      {'X','R','I','O','I','E','X'},
      {'X','O','X','X','O','X','X'}};
  
  struct posicion * res = resolverSopa(diccionario, sopa);
  // La cantidad de palabras encontradas debe ser 9
  int expected = 9;
  int count = 0;
  while ( res[count].palabra != NULL)
     printf("%s\n", res[count++].palabra);
  assert(count == expected);

  assert(strcmp(res[0].palabra,"ARRE")==0);
  assert(res[0].fila==1);
  assert(res[0].columna==2);
  assert(res[0].direccion==D_AB);

  assert(strcmp(res[3].palabra,"ORCO")==0);
  assert(res[3].fila==3);
  assert(res[3].columna==3);
  printf("%d\n", res[3].direccion);
  assert(res[3].direccion==ARR);
  
  assert(strcmp(res[4].palabra,"ORCO")==0);
  assert(res[4].fila==4);
  assert(res[4].columna==3);
  assert(res[4].direccion==D_AR);

  assert(strcmp(res[6].palabra,"REA")==0);
  assert(res[6].fila==3);
  assert(res[6].columna==2);
  assert(res[6].direccion==I_AR);

  printf("OK\n");
  return 0;
}
