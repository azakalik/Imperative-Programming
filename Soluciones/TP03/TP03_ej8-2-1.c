#include <stdio.h>
#include <limits.h>
int main(void)
{
    printf("\nUsando las constantes de limits.h\n");
    /* tipos signados */
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char max= %d\n", SCHAR_MAX);
    printf("signed short min= %d\n", SHRT_MIN);
    printf("signed short max= %d\n", SHRT_MAX);
    printf("signed int min= %d\n", INT_MIN);
    printf("signed int max= %d\n", INT_MAX);
    printf("signed long min= %ld\n", LONG_MIN);
    printf("signed long max= %ld\n", LONG_MAX);
    /* tipos sin signo */
    printf("unsigned char max = %u\n", UCHAR_MAX);
    printf("unsigned short max = %u\n", USHRT_MAX);
    printf("unsigned int max = %u\n", UINT_MAX);
    printf("unsigned long max = %lu\n", ULONG_MAX);
    printf("\nHaciendo cálculos\n");
    /* tipos signados */
    printf("signed char min = %d\n",
           (signed char)((unsigned char)1 << (sizeof(char) * 8) - 1));
    printf("signed char max = %d\n",
           (signed char)((unsigned char)~0 >> 1));
    printf("signed short min = %d\n",
           (short)((unsigned short)1 << (sizeof(short) * 8) - 1));
    printf("signed short max = %d\n", (short)((unsigned short)~0 >> 1));
    printf("signed int min = %d\n",
           (int)((unsigned int)1 << (sizeof(int) * 8) - 1));
    printf("signed int max = %d\n", (int)((unsigned int)~0 >> 1));
    printf("signed long min = %ld\n",
           (long)((unsigned long)1 << (sizeof(long) * 8) - 1));
    printf("signed long max = %ld\n", (long)((unsigned long)~0 >> 1));
    /* tipos sin signo */
    printf("unsigned char max = %u\n", (unsigned char)~0);
    printf("unsigned short max = %u\n", (unsigned short)~0);
    printf("unsigned int max = %u\n", (unsigned int)~0);
    printf("unsigned long max = %lu\n", (unsigned long)~0);
    return 0;
}