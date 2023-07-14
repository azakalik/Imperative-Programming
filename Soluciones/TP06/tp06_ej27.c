#define MAX 256

void eliminaCeros(char * s) {
int i, j=0;
  for(i=0; i < MAX; i++)
     if ( s[i] )
        s[j++] = s[i];
  
  s[j] = 0;

}

void analize(const char * text, char * chars) {
  // Inicializamos en cero
  for(int i=0; i < MAX; i++)
    chars[i]=0;

  for(int i=0; text[i]; i++)
    chars[text[i]] = text[i];

  eliminaCeros(chars);
}