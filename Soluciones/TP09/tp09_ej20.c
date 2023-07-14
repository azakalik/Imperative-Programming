#define DIM 9

void setTaboo(char sudoku[DIM][DIM], size_t r, size_t c, size_t taboo[]) {
  // Marcamos como invalidos los que aparecen en la fila f y en la columna c
  for(size_t i=0; i < DIM; i++) {
    taboo[sudoku[r][i]] = 1;
    taboo[sudoku[i][c]] = 1;
  }
  // Ahora la submatriz
  size_t row = r / 3 * 3;
  size_t col = c / 3 * 3;
  for (size_t i=row; i < row + 3; i++) {
     for (size_t j=col; j < col +3; j++) {
       taboo[sudoku[i][j]] = 1;
     }
  }
}

int solverRec(char sudoku[DIM][DIM], size_t r, size_t c) {
  size_t j=c;
   for (size_t i=r; i < DIM; i++) {
     for (; j < DIM; j++) {
       if ( sudoku[i][j]==0) {
           // Ver que numeros puedo usar en [i][j]
           // Podriamos hacer una funcion que retorne un vector con los numeros validos, 
           // pero teniendo en cuenta que son 9, usaremos un vector estatico que marque los numeros que no se pueden usar
           // Incluimos el cero, para simplificar su uso
           size_t taboo[DIM+1] = {0};
           setTaboo(sudoku, i, j, taboo);
           for(int e=1; e <= DIM; e++) {
             if ( !taboo[e]) {
               // Probamos con este, si tiene solucion, ya esta, sino probamos con el que sigue
               sudoku[i][j] = e;
               if ( solverRec(sudoku, i, j)) {
                  return 1;
               }
               // deshacemos, no fue solucion
               sudoku[i][j] = 0;
             }
           }
           // Probamos con todos y ninguno sirvio para esta casilla
           return 0;
       }
     }
     j = 0;
   }
   return 1;
}

int sudokuSolver(char matriz[DIM][DIM]) {
  // Para cada casilla libre debemos probar con todas las posibilidades
  // Completar la casilla libre con uno de los posibles numeros validos y probar con el resto de las casillas libres. Si con esa posiblidad no tiene solucion, hacer lo mismo con la siguiente posibilidad. 
  // Para no tener que recorrer siempre la matriz desde el principio, usamos una funcion auxiliar que indica a partir de que casilla comnenzar a recorrer
  return solverRec(matriz, 0, 0);
}

