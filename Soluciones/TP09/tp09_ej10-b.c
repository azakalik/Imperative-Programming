
int invierte(const char *origen, char *destino)
{
    int n;
    if (*origen == 0) {
         return 0;
    }
    n = invierte(origen +1, destino);
    destino[n] = *origen;
    return n +1;
}
