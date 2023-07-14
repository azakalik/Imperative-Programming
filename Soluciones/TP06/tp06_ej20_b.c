// Otra versión posible sería chequear filas y columnas en una sola función, evitando recorrer dos veces la matriz. Luego de verificar los subcuadrados, se llamaría a esta función
// Además creamos el vector auxiliar con una posición más (un solo char) para evitar restar 1 todo el tiempo
int chequearFilCol(char m[][DIM]){
   for ( int i=0; i<DIM; i++) {
       char vFil[DIM+1] = {0};
       char vCol[DIM+1] = {0};
       for(int j = 0; j < DIM; j++){
           if(vFil[m[i][j]]++ == 1){
               return 0;
           if(vCol[m[j][i]]++ == 1){
               return 0;
   }
   return 1;
}



