#include <string.h>
#include <ctype.h>

#define ERROR 0
#define EXITO 1
#define CANT_VOCAL 5

/* Devuelve 0 si no es vocal, 1 si es 'a', 2 si es 'e', etc. */
int esVocal(char c) {
  static char * vMay = "AEIOU";
  char * p = strchr(vMay, toupper(c));
  if ( p == NULL)
     return 0;
  return p - vMay + 1;
}

int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n) {
  // usamos un vector donde en cada posicion se guarda el indice de la columna
  // correspondiente a la vocal. La otra posibilidad era usar cinco variables
  unsigned int pos[CANT_VOCAL] = {0};
  int ans = EXITO;
  
  int i, j;

  // Para eliminar las vocacles es el mismo algoritmo que para eliminar ceros
  // Solo que ademas de verificar si es vocal, tenemos que guardar la posicion original
  for(i=j=0; s[i]; i++) {
     int vocal = esVocal(s[i]);
     if ( vocal && pos[vocal-1] < n-1) { // es vocal pero ademas tenemos que ver si hay lugar en la columna
        m[pos[vocal-1]++][vocal-1] = i;
     } else {
       if ( vocal )
          ans = ERROR;  // era vocal pero no habia mas lugar
       s[j++] = s[i];
     }
  }
  s[j] = 0;
  // Completamos con -1 al final de cada columna
  for(i=0; i < CANT_VOCAL; i++) {
    m[pos[i]][i] = -1;
  }

  return ans;
}
