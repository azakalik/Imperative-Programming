#define EPSILON 0.000001

/* Calcula la maxima diferencia entre dos valores consecutivos de un arreglo de reales */

double 
maxDiferencia(const double arreglo[]) {
    double dif= 0.0;

    if ( fabs(arreglo[0]) > EPSILON )
    		for (int j=1; fabs(arreglo[j]) > EPSILON; j++)
        		if (fabs(arreglo[j] - arreglo[j-1]) > dif )
            		dif = fabs(arreglo[j] - arreglo[j-1]);

    return dif;
}

/* Otra version correcta */

double 
maxDiferencia(const double arreglo[]) {
double dif=0, difAux;
	int j=0;

if ( fabs(arreglo[0]) > EPSILON )
 		while (fabs(arreglo[++j]) > EPSILON)
			if ( (difAux = fabs(arreglo[j] - arreglo[j-1])) > dif)
				dif = difAux;
return dif;
}
