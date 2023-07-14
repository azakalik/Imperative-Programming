/* Biblioteca para obtener el promedio de 3 enteros */

static int fAuxiliar (int n, int m, int p);

float
promedio3 (int n, int m, int p) {
    return fAuxiliar(n, m, p) / 3.0;
}

static int
fAuxiliar (int n, int m, int p) {
    return n + m + p;
}
