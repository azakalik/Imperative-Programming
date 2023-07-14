void invierte(int matriz[][MAX], int dim, int fil, int col, int n)
{
    if(n == dim)
        return;
    if(n == 0)
        matriz[fil][col]=!matriz[fil][col];//para que no lo resuelva varias veces.
	//sigue con los vértices de cada cuadrado (si existe)
    if(fil + n < dim)
    {
        if (n + col < dim)
            matriz[fil+n][col+n]=!matriz[fil+n][col+n];
        if (col - n >= 0)
            matriz[fil+n][col-n]=!matriz[fil+n][col-n];
    }
    if(fil - n < dim)
    {
        if (n + col < dim)
            matriz[fil-n][col+n]=!matriz[fil-n][col+n];
        if (col - n >= 0)
            matriz[fil-n][col-n]=!matriz[fil-n][col-n];
    }
    invierte(matriz, dim, fil, col, n+1);

}
void reemplazo(int matriz[][MAX], int dim, int fil, int col)
{
    invierte(matriz,dim,fil,col,0);
}
