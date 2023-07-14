#define COLS 4

// La única diferencia con el ejercicio anterior es en la funcion que debe verificar
// si los elementos de un vector estan en otro


// La vieja y conocida pertenece o belongs
int pertenece(int elem, const int v[], unsigned int dim) {
  for (int i=0; i < dim; i++)
     if ( v[i] == elem)
        return 1;
  return 0;
}

// Para cada elemento en v1 llamamos a una funcion que nos dice si esta en v2
static int contiene(const int v1[], const int v2[], unsigned int dim) {
  for (int i=0; i < dim ; i++) {
    if ( !pertenece(v1[i], v2, dim))
      return 0;
  }
  return 1;
}

static int vecEnMatriz(const int v[], const int (m[])[COLS], unsigned int fils) {
  // Debemos ver si v esta contenido dentro de alguna de las filas de m
  // Apenas encontramos que v "pertenece" a m retornamos 1. El razonamiento es
  // muy parecido al de buscar un elemento en un vector
  for(int i=0; i < fils; i++) {
    if ( contiene(v, m[i], COLS))
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