#define DIMMAX 10

void
traspuesta( int matriz[][DIMMAX], int dim) {
	int i, j, aux;

	for (i = 0; i < dim; i++)
		for (j = 0; j < i; j++) {
			aux = matriz[i][j];
			matriz[i][j] = matriz[j][i];
			matriz[j][i] = aux;
		}
	return;
}