#define MAX 10

void diagonal(int matriz[][MAX], int dim, int fil, int col, int despFil, int despCol);
void reemplazo(int matriz[][MAX], int dim, int fil, int col);
void reemplazo2(int matriz[][MAX], int dim, int fil, int col);


void reemplazo(int matriz[][MAX], int dim, int fil, int col)
{
    if (fil < 0 || fil >= dim || col < 0 || col >= dim)
        return;

    matriz[fil][col] = !matriz[fil][col];
    diagonal(matriz, dim, fil + 1, col + 1, 1, 1);
    diagonal(matriz, dim, fil - 1, col + 1, -1, 1);
    diagonal(matriz, dim, fil + 1, col - 1, 1, -1);
    diagonal(matriz, dim, fil - 1, col - 1, -1, -1);
}

// En este caso en vez de hacer 4 llamadas creamos una "matriz de desplazamiento"
void reemplazo2(int matriz[][MAX], int dim, int fil, int col)
{
    if (fil < 0 || fil >= dim || col < 0 || col >= dim)
        return;
    static int mov[4][2] = {{1,1}, {-1,1}, {1,-1}, {-1,-1}};
    
    matriz[fil][col] = !matriz[fil][col];
    for(int i=0; i < 4; i++)
        diagonal(matriz, dim, fil + mov[i][0], col + + mov[i][1], + mov[i][0], mov[i][1]);
}

void diagonal(int matriz[][MAX], int dim, int fil, int col, int despFil, int despCol)
{
    if (fil >= 0 && fil < dim && col >= 0 && col < dim)
    {
        matriz[fil][col] = !matriz[fil][col];
        diagonal(matriz, dim, fil + despFil, col + despCol, despFil, despCol);
    }
}
