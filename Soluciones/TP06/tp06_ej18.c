#define COLS 4

// Nota: ver los comentarios a las funciones "de abajo hacia arriba" (comenzando con sonAmigas y terminando con contieneOrden)
// para entender cuál fue el razonamiento

// La idea es la misma que la interseccion de vectores ordenados, solo que debemos
// verificar que todos los elementos de v1 esten en v2, pero la forma de 
// recorrer los vectores es muy similar a la interseccion
static int contieneOrden(const int v1[], const int v2[], unsigned int dim) {
  int i, j;
  for (i=0, j=0; i < dim && j < dim; ) {
    if ( v1[i] < v2[j] )  // Si es menor, no va a estar despues
      return 0;
    if ( v1[i] == v2[j]) {
      i++; // no incrementamos j, porque puede haber elementos repetidos en v1
    }
    else // v1[i] > v2[j]  -> puede estar mas adelante
      j++;
  }
  // Si llegue al final, quiere decir que todos los elementos estaban
  return i==dim;
}

static int vecEnMatriz(const int v[], const int (m[])[COLS], unsigned int fils) {
  // Debemos ver si v esta contenido dentro de alguna de las filas de m
  // Apenas encontramos que v "pertenece" a m retornamos 1. El razonamiento es
  // muy parecido al de buscar un elemento en un vector
  for(int i=0; i < fils; i++) {
    if ( contieneOrden(v, m[i], COLS))
       return 1;
  }
  return 0;
}

static int esAmiga(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 ) {
  // Verificar que todas las filas de m1 esten en m2
  for(int i=0; i < fils1; i++) {
    if ( ! vecEnMatriz(m1[i], m2, fils2))
      return 0;
  }
  return 1;

}

int sonAmigas(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 ) {

  // Como hay que verificar m1 contra m2 y luego m2 contra m1, realizamos una funcion auxiliar que haga todo el trabajo, y la llamamos primero para m1.
  if ( esAmiga(m1, fils1, m2, fils2))
    return 1;   // Si esAmiga no hace falta hacer nada mas
  if ( esAmiga(m2, fils2,m1, fils1))
    return 2;
  return 0;

}