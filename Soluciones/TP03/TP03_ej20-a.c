#include <stdio.h>

#define EPSILON 0.0000001

int main(void)
{
    long factorial = 1;
    float e = 1, anterior = 0;
    int i = 1, j;

    printf("%-10s %10s\n", "N", "e");
    while (e - anterior > EPSILON)
    {
        printf("%-10d %10.7f\n", i, e);
        anterior = e;
        e += 1.0 / factorial;
        i++;
        for (j = 2, factorial = 1; j <= i; j++)
            factorial *= j;
    }
    return 0;
}
