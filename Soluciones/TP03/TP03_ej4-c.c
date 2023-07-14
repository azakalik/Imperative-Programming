#include <stdio.h>
#include "getnum.h"
int main(void)
{
    if (x < 3)
    {
        printf("x<3");
        if (z < 5)
            printf("x<3 y z<5");
    }
    else
        printf("x >= 3");
}