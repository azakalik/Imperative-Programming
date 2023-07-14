#include <string.h>

int esPalindromo(const char *s, unsigned int dim)
{
    // Una palabra vacia o de una letra es capicua
    if (dim <= 1)
        return 1;
    else
        return (s[0] == s[dim - 1]) && esPalindromo(s + 1, dim - 2);  
        // Notar que se resta 2, pues se "sacan" tanto el primero como ultimo char
}

int palindromo(const char * s) {
  return esPalindromo(s, strlen(s));
}
