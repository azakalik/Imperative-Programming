int numeroCorrecto(const char *numero)
{
    int huboPunto = 0, respuesta = 1;

    while (respuesta && *numero)
    {
        if (*numero == '.')
            if (huboPunto)
                respuesta = 0;
            else
                huboPunto = 1;
        else
            respuesta = isdigit(*numero);

        numero++;
    }
    return respuesta;
}

char *
CopiaOriginal(const char *original)
{
    char *aux;
    int i;

    /* Se reserva espacio para la copia */
    if ((aux = malloc(strlen(original) + 1)) == NULL)
        return NULL;

    /* Se ignoran los ceros a izquierda antes del punto */
    while (*original == '0')
        original++;

    /* Se hace la copia */
    strcpy(aux, original);

    /* Se ignoran los ceros a derecha después del punto (al final)*/
    i = strlen(aux) - 1;
    while (i >= 0 && aux[i] == '0')
        aux[i--] = 0;

    /* Se elimina el punto si quedó al final */
    if (i >= 0 && aux[i] == '.')
        aux[i] = 0;

    return aux;
}

int normalizar(const char *original, char *salida)
{
    int mayorUno; /* Indica si el número es mayor(o igual) o menor que uno */
    int potencia = 0, j = 0;
    char *num, *prim, *punto;

    /* Inicializa la salida con el string vacio */
    salida[j] = 0;

    /* Si el número no es correcto, no se puede hacer una copia o la copia es string vacio */
    if (!numeroCorrecto(original) ||
        ((num = CopiaOriginal(original)) == NULL) || !*num)
        return 0;

    /* Se busca la posición del punto, si no está se lo supone al final de la cadena */
    punto = strchr(num, '.');
    if (punto == NULL)
        punto = num + strlen(num);

    /* Se busca el primer dígito significativo */
    prim = strpbrk(num, "123456789");

    /* La potencia depende de la posición del punto y el primer dígito significativo */
    if ((mayorUno = (*num != '.')))
        potencia = punto - prim - 1;
    else
        potencia = prim - num;

    /* Se copian los dígitos */
    salida[j++] = *prim++;
    if (*prim)
    {
        for (salida[j++] = '.'; *prim; prim++)
        {
            if (*prim != '.')
                salida[j++] = *prim;
        }
    }

    /* Se arma la expresión final, con la potencia normalizada */
    sprintf(salida + j, "E%c%02d", (mayorUno) ? '+' : '-', potencia);
    free(num);
    return 1;
}
