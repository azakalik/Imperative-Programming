#include <string.h>
#include <ctype.h>

#define NSVOCAL(c) (strchr("nNsSaeiouAEIOU",c)!=NULL )

// Hacemos coincidir el enum con la cantidad de sílabas contando desde el final
enum TIPOS_DE_PALABRAS {AGUDA=1, GRAVE, ESDRUJULA, SOBREESDRUJULA};

int llevaTilde(int silaba, char ultimaLetra);

int tildarPalabras(const char frase[]){
    int silaba=0;
    int llevanTilde = 0;
    int i=0;

    // Hacemos un do-while para no tener el caso especial de la última palabra
    do {
        if ( isalpha(frase[i]) && silaba==0) {
            silaba=1;
        } else if(frase[i]=='-'){
            silaba++;
        }else if(frase[i] == '|'){
            silaba = 1;
        }else if((frase[i]==' ' || frase[i]=='\0') && silaba != 0){   // Fin de la palabra no vacía
            llevanTilde += llevaTilde(silaba, frase[i-1]);
            silaba = 0;
        }
    } while(frase[i++]);

    return llevanTilde;
}

int llevaTilde(int silaba, char ultimaLetra){
    if( silaba == SOBREESDRUJULA || silaba == ESDRUJULA )
        return 1;
    if( silaba == AGUDA && NSVOCAL(ultimaLetra) )
        return 1;
    if( silaba == GRAVE && !NSVOCAL(ultimaLetra) )
        return 1;

    return 0;
}

// También podría ser

// int llevaTilde(int silaba, char ultimaLetra){
//     return ( silaba == SOBREESDRUJULA || silaba == ESDRUJULA )
//         || ( silaba == AGUDA && NSVOCAL(ultimaLetra) )
//         || ( silaba == GRAVE && !NSVOCAL(ultimaLetra) );
// }