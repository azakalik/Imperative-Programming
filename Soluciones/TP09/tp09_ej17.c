#include <ctype.h>

int bienformado(const char * s) {
  if ( *s == 0)
    return 0;
  int aux = bienformado(s+1);
  if ( isdigit(*s) ) {
    if ( aux==0)
      return *s - '0';
    return -1;
  }
  // si es una letra. Si aux es cero o negativo, seguira siendo negativo
  if ( isalpha(*s))
    return aux - 1;
  // no es digito ni letra
  return -1;
}

int bienformado2(const char * s) {
  if ( *s == 0)
    return 0;
  int aux = bienformado2(s+1);
  if ( aux < 0)  // está mal formado
     return aux;
  if ( aux == 0) {
     if ( isdigit(*s))
        return *s-'0';
     else
        return -1;
  }
  // es >0, tengo que estar en una letra
  if ( isalpha(*s))
    return aux - 1;
  return -1;
}

