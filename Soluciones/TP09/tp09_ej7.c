int busquedaBinaria(const int datos[], unsigned int dim, int num)
{
    if (dim == 0)
        return 0;

    if (datos[dim / 2] == num)
        return 1;

    if (datos[dim / 2] > num)
        return busquedaBinaria(datos, dim / 2, num);

    return busquedaBinaria(datos + dim / 2 + 1, dim - dim / 2 - 1, num);
}
