// En esta version hacemos un solo ciclo, con cuidado de no
// seguir copiando sobre el string que haya finalizado
void deleteChars( char str1[], char str2[] ){
  int i = 0, j = 0, count1 = 0, count2 = 0;
  while( str1[i] || str2[j] ){
    if( str1[i] == str2[j] ){
      i++; j++;
    }
    else{
      if( str1[i] )
        str1[count1++] = str1[i++];
      if( str2[j] )
        str2[count2++] = str2[j++];
    }
  }
  str1[count1] = 0; str2[count2] = 0;
}

// Esta es similar a la anterior, pero usando punteros 
void deleteChars2(char v1[], char v2[]) {
    char i=0, j=0, *p1=v1, *p2=v2;
    while ( *p1 != 0 || *p2 != 0) {
        if (*p1==*p2){
            p1++;
            p2++;
        } else {
            if (*p1 != 0)
                v1[i++]=*p1++;
            if (*p2 != 0)
                v2[j++]=*p2++;  
        }
    }
    v1[i]=0;
    v2[j]=0;
}

// En esta version salimos del ciclo cuando se termina alguno de los dos
// Luego del ciclo copiamos los caracteres que restan
void deleteChars3( char str1[], char str2[] ){
  int i = 0, j = 0, count1 = 0, count2 = 0;
  while( str1[i] && str2[j] ){
    if( str1[i] == str2[j] ){
      i++; j++;
    }
    else{
        str1[count1++] = str1[i++];
        str2[count2++] = str2[j++];
    }
  }
  while(str1[count1++] = str1[i++]) // copiamos hasta el cero inclusive
     ;
  while(str2[count2++] = str2[j++])
     ;
  
}
