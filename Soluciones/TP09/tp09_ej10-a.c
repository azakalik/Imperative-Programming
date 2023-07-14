void invierte(const char *origen, char *destino)
{
    if (*origen)
    {
        *(destino + strlen(origen) - 1) = *origen;
        invierte(origen + 1, destino);
    }
}
