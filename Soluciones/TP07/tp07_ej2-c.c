void leerBases(int *baseOrigen, int *baseDestino)
{
    int flag;
    do
    {
        printf("\nIngrese bases en formato <n>m: ");
        flag = scanf("<%d>%d", baseOrigen, baseDestino);
        BORRA_BUFFER;
        if (flag == 2 && (*baseOrigen < 2 || *baseOrigen > 10 ||
                          *baseDestino < 2 || *baseDestino > 10))
            flag = 0;
    } while (flag != 2);
}
