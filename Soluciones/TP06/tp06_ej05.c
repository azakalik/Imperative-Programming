int
eliminaRepOrden( const int original[], int dimOrig, int resultado[]) {
	int dimResult = 0;
	int i;
	
	if (dimOrig > 0) {
		resultado[0] = original[0];
		for (i = 1, dimResult = 1; i < dimOrig; i++)
			if (original[i] != original[i-1])
				resultado[dimResult++] = original[i];
	}
	return dimResult;
}

/* Otra versión, también correcta: comparar contra el último elemento copiado. */

int
eliminaRepOrden( const int original[], int dimOrig, int resultado[]) {
	int dimResult = 0;
	int i;
	
	if (dimOrig > 0) {
		resultado[0] = original[0];
		for (i = 1, dimResult = 1; i < dimOrig; i++)
			if (original[i] != resultado[dimResult-1])
				resultado[dimResult++] = original[i];
	}
	return dimResult;
}
