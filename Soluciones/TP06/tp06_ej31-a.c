#include <string.h>

int strend(const char *s, const char *t)
{
    int ls, lt;

    /* Se calcula la longitud de las cadenas */
    ls = strlen(s);
    lt = strlen(t);

    if (lt > ls) /* Si la cadena t es mas larga, es falso */
        return 0;

    for (ls--, lt--; lt >= 0 && s[ls] == t[lt]; ls--, lt--)
        ;

    return (lt == -1);
}

/* Version mas simple */
int strend(const char *s, const char *t) {
    int ls, lt;

    /* Se calcula la longitud de las cadenas */
    ls = strlen(s);
    lt = strlen(t);

    if (lt > ls) /* Si la cadena t es mas larga, es falso */
        return 0;
    return  strcmp(s + ls - lt, t) == 0;
    /* La funcion tambien podria ser unicamente la siguiente linea
        return strcmp(s + strlen(s) - strlen(t), t) == 0;
    ** pero podria dar error de acceso a memoria invalida si lt > ls 
    */
}

