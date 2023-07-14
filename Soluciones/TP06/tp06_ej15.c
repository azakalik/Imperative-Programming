#define ALTO 6
#define ANCHO 5

#define MIN(x,y)  ((x) < (y) ? (x) : (y))
#define MAX(x,y)  ((x) > (y) ? (x) : (y))

// Asumimos w es al menos 1
// Al ser una funcion auxiliar, ya sabemos que los parametros son validos
static int promedio(unsigned char m[ALTO][ANCHO], int i, int j, int w ) {
   int sum = 0, cant = 0;
   for ( int i2 = MAX(0,i-w); i2 <= MIN(ALTO-1,i+w); i2++ ) {
       for ( int j2 = MAX(0,j-w); j2 <= MIN(ANCHO-1,j+w); j2++ ) {
         cant++;
         sum += m[i2][j2];
       }
   }
   // cant no puede ser cero
   return sum / cant;
}

void suavizar(unsigned char imagen[ALTO][ANCHO], unsigned int w ) {
  if ( w < 3 || w % 2 == 0)
    return;
  // Debemos definir una matriz auxiliar, no se puede hacer sobre la misma matriz
  unsigned char aux[ALTO][ANCHO];

  for (int i=0; i < ALTO; i++) {
    for (int j=0; j < ANCHO; j++)
      aux[i][j] = promedio(imagen, i, j, w / 2);
  }

  // Ahora copiamos la auxiliar a la original
  for (int i=0; i < ALTO; i++) {
    for (int j=0; j < ANCHO; j++)
      imagen[i][j] = aux[i][j];
  }
}