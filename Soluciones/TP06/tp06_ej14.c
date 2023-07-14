
/* fuciones auxiliares */
int pertenece(int elem, const int v[], unsigned int dim) {
    int i;
    for (i = 0; i < dim; i++)
        if (elem == v[i])
            return 1;

    return 0;
}

int contieneAux(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2) {
    int i, encontrado;
    for (i = 0, encontrado = 1; i < dim1 && encontrado; i++)
        encontrado = pertenece(v1[i], v2, dim2);
    
    return encontrado;
}

int contiene(const int v1[], int dim1, const int v2[], int dim2) {
    if (contieneAux(v1, dim1, v2, dim2))
        return 1;
    if (contieneAux(v2, dim2, v1, dim1))
        return 2;
    return 0;
}