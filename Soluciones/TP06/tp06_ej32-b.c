int normalizar(const char *original, char *salida)
{
    int mayorUno = 1, potencia = 0, j = 0, sumarPotencia = 1;

    salida[j] = 0;

    while (*original == '0')
        original++;

    if (*original != '.' && !isdigit(*original))
        return 0;

    if (*original == '.')
    {
        original++;
        for (mayorUno = 0, potencia = 1; *original == '0'; original++)
            potencia++;
        sumarPotencia = 0;
    }

    salida[j] = *original++;

    if (*original != 0)
        salida[++j] = '.';

    while (*original != 0)
    {
        if (*original == '.')
        {
            if (!sumarPotencia)
            {
                salida[0] = 0;
                return 0;
            }
            sumarPotencia = 0;
        }
        else
        {
            if (!isdigit(*original))
            {
                salida[0] = 0;
                return 0;
            }
            salida[++j] = *original;
        }

        if (sumarPotencia)
            potencia++;

        original++;
    }

    while (j >= 0 && salida[j] == '0')
        j--;

    if (j >= 0 && salida[j] == '.')
        j--;

    sprintf(salida + j + 1, "E%c%02d", (mayorUno) ? '+' : '-', potencia);

    return 1;
}
