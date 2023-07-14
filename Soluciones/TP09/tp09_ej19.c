// Retorna la primera aparicion de alguno de los caracteres de chars
char * strpbrkRec(const char * target, const char * chars) {
  // Si no hay mas caracteres a buscar, entonces no esta
  if ( *chars==0 || *target==0)
     return NULL;
  
  if ( *target == *chars )
     return target;
  char * ans = strpbrkRec(target, chars+1); 
  if ( ans == NULL) // probamos con la siguiente posicion, a ver si esta
     return strpbrkRec(target+1, chars);
  return ans;
}
