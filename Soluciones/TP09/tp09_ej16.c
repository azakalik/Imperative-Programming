int orden(const int v[])
{
    // No es un caso base, es validación. Sería más eficiente hacerlo
    // en una función “wrapper” pero no cumpliría con la consigna
    if (v[0] == -1 || v[1] == -1)
        return 0;

    // Este es el caso base. Cuando hay dos elementos determino si
    // están ordenados o no
    if (v[2] == -1)
    {
        if (v[0] < v[1])
            return 1;
        if (v[0] > v[1])
            return -1;
        return 0; // son iguales, no está ordenado
    }

    int ordenResto = orden(v + 1);

    // Si el resto del vector no está ordenado…
    if (ordenResto == 0)
        return 0;

    // Si el resto está ordenado ascendente, el elemento actual
    // debe ser menor al primer elemento del resto del vector
    if (ordenResto == 1)
        return v[0] < v[1];

    // El resto del vector está ordenado descendentemente
    if (v[0] > v[1])
        return -1;
    return 0;
}
