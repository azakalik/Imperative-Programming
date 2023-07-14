int apareados(const char *texto)
{
    if (*texto == 0)
        return 0;

    int aux = apareados(texto + 1);

    if (aux < 0)
        return aux; // quedaron parentesis que abren sin aparear

    return aux + (*texto == '(' ? -1 : 1);
}
