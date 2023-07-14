#define EPSILON 0.000000001

double
raizNR(double valorAnterior, int iter, double x)
{
    /* Contemplamos el caso de querer calcular la raiz de cero */
    if (fabs(valorAnterior) < EPSILON)
        return 0;

    if (iter == 0)
        return valorAnterior;

    valorAnterior = (valorAnterior + (x / valorAnterior)) / 2;

    return raizNR(valorAnterior, iter - 1, x);
}
