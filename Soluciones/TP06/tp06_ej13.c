#define MAX 10

/* sin restricciĂłn de ciclos anidados */
void
productoMat( const int m1[][MAX], const int m2[][MAX], int m3[][MAX], int dim) {
	int i,j,k;

	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			for( k = 0, m3[i][j] = 0; k < dim; k++)
				m3[i][j] += m1[i][k] * m2[k][j];
}

/* Otra forma modularizada */
int
filaPorCol(const int fila[], const int mat2[][MAX], int col, int dim) {
	int i;
	int total = 0;

	for(i = 0; i < dim; i++)
		total += fila[i]* mat2[i][col];
	return total;
}

void 
productoMat( const int m1[][MAX], const int m2[][MAX], int m3[][MAX], int dim) {
	int i,j;

	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			m3[i][j] = filaPorCol(m1[i], m2, j, dim);

	return;
}

/* Otra forma modularizada */
void
multVector( const int vec[], const int matriz[][MAX], int vecFinal[], int dim) {
	int j, k;
	for (j = 0; j < dim; j++)
		for( k = 0, vecFinal[j] = 0; k < dim; k++)
			vecFinal[j] += vec[k] * matriz[k][j];
}

void
productoMat( const int m1[][MAX], const int m2[][MAX], int m3[][MAX], int dim) {
	int i;

	for (i = 0; i < dim; i++)
		multVector(m1[i], m2, m3[i], dim);
}