int sumaVec(const int *vector, unsigned int dim)
{
    if (dim == 0)
        return 0;

    return *vector + sumaVec(vector + 1, dim - 1);
}
