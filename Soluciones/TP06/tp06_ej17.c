#define N 4
#define M 5

int armaNumero(const int vec[], int dim) {
  int num =0;
  for(int i=0; i < dim; i++) {
    if ( vec[i] < 0 || vec[i] > 9)
       return -1;
    num *= 10;
    num += vec[i];
  }
  return num;
}

int armaFilas(int mat[][M], int vec[]) {
  int dim =0;
  for ( int i=0; i < N; i++ )  {
    int num = armaNumero(mat[i], M);
    if ( num >= 0)
        vec[dim++] = num;
  }
  return dim;
}