int normalizar(const char *original, char *salida)
{
    int mayorUno = 1, potencia = 0, digitoSig = 0, huboPunto = 0;

    if (!numeroCorrecto(original))
        return 0;

    while (*original)
    {
        if (isdigit(*original))
        {
            if (digitoSig)
            {
                *salida++ = *original++;
                if (!huboPunto)
                    potencia++;
            }
            else if (*original != '0')
            {
                digitoSig = 1;
                *salida++ = *original++;
                *salida++ = '.';
            }
            else
            {
                if (!mayorUno)
                    potencia++;
                original++;
            }
        }
        else
        {
            huboPunto = 1;
            original++;
            if (!digitoSig)
            {
                mayorUno = 0;
                potencia = 1;
            }
        }
    }
    sprintf(salida, "E%c%02d", (mayorUno) ? '+' : '-', potencia);
    return 1;
}
