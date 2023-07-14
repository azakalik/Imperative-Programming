#define MAXCOL 10

/*
** Nota: no es la mejor forma de solucionar este problema ya que realiza muchos intercambios.
**       Pero el algoritmo ideal es algo que podrán hacer en futuras materias (por ejemplo EDA)
*/

/* Función que intercambia los valores de dos filas */
void
intercambiaFilas(int fila1[],int fila2[], int col) {
    int i, aux;

	for (i = 0; i < col; i++) {	/* Recorre todas las columnas */
		aux = fila1[i];
		fila1[i] = fila2[i];
		fila2[i] = aux;
	}
	return;
}

/* Ordena por el método de burbujeo (bubble sort) */
void
ordenaMatriz (int matriz[][MAXCOL], int fil, int col, int colOrd) {
	int i,j;
	
	colOrd--;	/* Resto uno porque la 1era. columna debe ser la 0 */
	for (i=0; i < fil-1 ; i++)
		for (j=0; j<fil-1-i; j++) /* Cada ciclo interno tiene una vuelta menos */
			if (matriz[j][colOrd]>matriz[j+1][colOrd])
				intercambiaFilas(matriz[j], matriz[j+1], col);
	return;
}


/* Otra solución -selection sort- más eficiente para matrices que usar el método de burbujeo */
void
ordenaMatriz (int matriz[][MAXCOL], int fil, int col, int colOrd) {
	int i, j, menor = 0;
	
	colOrd--;
	for (i = 0; i < fil-1 ; i++) {  /* Recorro las filas comenzando por la 0 */
		menor = i;	  /* Busco la menor, que es la que debería quedar allí */
		for (j = menor+1; j<fil; j++)
			if (matriz[j][colOrd] < matriz[menor][colOrd])
				menor = j;

		if (i != menor)   /* Si la menor no está bien ubicada, la ubico */
			intercambiaFilas(matriz[i], matriz[menor], col);
	}
	return;	
}