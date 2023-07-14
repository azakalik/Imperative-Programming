void 
desordenaArreglo( int arreglo[], int dim) {
	int i, j, aux;

	randomize();

	for (i = 0; i < dim; i++) {
		j = randInt(0, dim-1);
		aux = arreglo[i];
		arreglo[i] = arreglo[j];
		arreglo[j] = aux;
	}
	return;
}
