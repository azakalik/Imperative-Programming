double productoEsc(const double *vec1, const double *vec2, unsigned int dim)
{
    if (dim == 0)
        return 0.0;

    return *vec1 * *vec2 + productoEsc(vec1 + 1, vec2 + 1, dim - 1);
}
