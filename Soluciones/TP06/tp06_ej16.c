
int 
ascendenteODescendente(const int (m[])[COLS]) {
  int asc = 1, des = 1; // Por ahora es ascendente y descendente
  int anterior = m[0][0];
  // Recorro la matriz mientras sea ascendente o descendente
  for(int i = 0; i < FILS && (asc || des); i++) { 
    for(int j = 0; j < COLS && (asc || des); j++) {
      int actual = m[i][j];
      // Si era ascendente y hay uno menor al anterior, ya no es ascendente
      if(asc && actual < anterior) { // Preguntar sólo actual < anterior está bien
        asc = 0;
      }
      // Si era descendente y hay uno mayor al anterior, ya no es descendente
      if(des && actual > anterior) { // Preguntar sólo actual > anterior está bien
        des = 0;
      }
      anterior = actual;
    }
  }
  if(asc) {
    return 1;
  }
  if(des) {
    return -1;
  }
  return 0;
}