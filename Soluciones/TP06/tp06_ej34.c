#define ALIVE 1
#define DEAD 0

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

// Cantidad de celdas en 1 que rodean a cells[row][col]
unsigned char neighbors(char cells[FILS][COLS], int row, int col);

// Copia todos los elementos de from a to
void copyMat (char from[FILS][COLS], char to[FILS][COLS]);

int nextStep(char cells[FILS][COLS]){
    // Los cambios no se pueden realizar directamente sobre la misma matriz,
    // necesitamos una auxiliar
    char aux[FILS][COLS];

    int changes=0; // Indica si hubo cambios

    // Recorremos toda la matriz y la función neighbors nos devuelve la cantidad de células vecinas vivas
    for(int i=0 ; i<FILS ; i++){
        for(int j=0 ; j<COLS ; j++){
            unsigned char sum = neighbors(cells,i,j);
            aux[i][j] = cells[i][j] && sum == 2 || sum == 3;
            changes = changes || aux[i][j] != cells[i][j];
        }
    }
    
    // Copiamos la matriz auxiliar a la matriz de entrada, que es en la que debemos dejar los resultados.
    copyMat(aux,cells);
    return changes;
}

unsigned char
neighbors(char cells[FILS][COLS], int row, int col){
    int sum = 0;
    // Recorremos los 8 vecinos, teniendo cuidado de no tomar datos fuera de la matriz
    // Las macros MAX y MIN nos ayudan a no pasarnos de los bordes
    for(int i = MAX(0, row-1); i <= MIN(FILS-1, row+1); i++){
        for(int j = MAX(0,col-1) ; j <= MIN(COLS-1,col+1) ; j++){
            if( i!=row || j!=col ){     // No hay que considerar la célula actual
                sum+= cells[i][j] == ALIVE;
            }
        }
    }
    // Otra variante sería hacer todo el recorrido pero ignorar las posiciones fuera de la matriz, o sea
    // for(int i = row-1; i <= row+1; i++){
    //     for(int j = col-1 ; j <= col+1 ; j++){
    //         if( (i!=row || j!=col) && i>=0 && i<FILS && j>-0 && j<COLS ){   
    //             sum+=cells[i][j];
    //         }
    //     }
    // }
    return sum;
}

void
copyMat(char from[FILS][COLS], char to[FILS][COLS]){
    for (int i=0 ; i<FILS ; i++){
        for(int j=0 ; j<COLS ; j++){
            to[i][j]=from[i][j];
        }
    }
}
