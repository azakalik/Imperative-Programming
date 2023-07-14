#include <stdio.h>
int main(void)
{
    int i;
    for (i = 3; i <= 23; i += 5)
        printf("%d,", i);
    putchar('\n');
    for (i = 20; i >= -10; i -= 6)
        printf("%d,", i);
    putchar('\n');
    for (i = 19; i <= 51; i += 8)
        printf("%d,", i);
    putchar('\n');
    return 0;
}