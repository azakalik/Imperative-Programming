void piramide(int *latas, int *h)
{
    if (*latas >= (*h + 1) * (*h + 1))
    {
        (*h)++;
        *latas -= *h * *h;
        piramide(latas, h);
    }
}
