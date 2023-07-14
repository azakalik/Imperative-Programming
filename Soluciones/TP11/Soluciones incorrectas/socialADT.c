// Si se lo compila con el flag de sanitize aborta con el mensaje "The signal is caused by a READ memory access."
// Sin el flag aborta por segmentation fault

#include "socialADT.h"
#include <stdlib.h>
#include <string.h>

typedef struct friend {
        char  name[21];
        struct friend * tail;
}friend;

typedef friend * TFriend;


typedef struct person {
        TFriend first;
        char name[21];
        size_t cantFriend;
        struct person * tail;
}person;

typedef person * TPerson;


typedef struct socialCDT {
        TPerson first;
        size_t cantPerson;
}socialCDT;


/* Crea un nuevo TAD vacío */
socialADT newSocial(void){
        return calloc (1,sizeof(socialCDT));
}



/* Almacena una nueva persona. Si la persona existe, no hace nada
** Guarda una copia del nombre, no simplemente el puntero
*/

static TPerson addPersonRec(TPerson first, const char * name,int * flag){

        int c;

        if (first==NULL ||(c= strcmp(first->name,name)) > 0){   //no lo encontro
                TPerson new=calloc(1,sizeof(person));   //hago calloc asi no queda basura en friend
                strcpy(new->name,name);
                new->tail=first;
                *flag=1;        //lo pude guardar
                return new;
        }

        if (c==0)
                return first;

first->tail=addPersonRec(first->tail,name,flag);
return first;
}



void addPerson(socialADT soc, const char * name){
        int flag=0;

        soc->first=addPersonRec(soc->first,name,&flag);
        if (flag)
                soc->cantPerson++;
}





/* Si existe una persona con ese nombre, agrega la nueva relación
** Si la persona no existe, no hace nada
** Si related ya estaba relacionado, lo agrega repetido
** Almacena una copia de related, no simplemente el puntero
**
 */

static TFriend addFriend (TFriend first, const char * related) {

        int c;

        if (first==NULL ||(c= strcmp(first->name,related)) >= 0){       //no lo encontro o va en ese lugar
                TFriend new=malloc(sizeof(friend));     //le doy espacio
                strcpy(new->name,related);
                new->tail=first;
                return new;
        }


first->tail=addFriend(first->tail,related);
return first;
}




void addRelatedRec(TPerson firstP, const char * name, const char * related){
                int c;

                if (firstP==NULL || (c=strcmp(firstP->name,name))>0)
                        return;
                if(c==0){
                        firstP->first=addFriend(firstP->first,related);
                        firstP->cantFriend++;
                        return;
                }
addRelatedRec(firstP->tail,name,related);
}




void addRelated(socialADT soc, const char * name, const char * related){

        addRelatedRec(soc->first,name,related);
}



/* Retorna una copia de los nombres relacionados con una persona
** en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si la persona no existe, retorna un vector que sólo tiene a NULL como
** elemento
 */

static char ** relatedRec(TPerson firstP, const char * person){
        int c;

        if (firstP==NULL || (c=strcmp(firstP->name, person))>0){        //no existe la persona
                char ** new = malloc(sizeof(char*));
                new[0]=NULL;
                return new;
        }

        if(c==0){
                char ** resp=malloc((firstP->cantFriend + 1) * sizeof(char*));
                TFriend actual=firstP->first;
                int i;
                for ( i=0 ; i<firstP->cantFriend; i++){
                        strcpy(resp[i],actual->name);   //guardo el nombre
                        actual=actual->tail;
                }
                resp[i]=NULL;
                return resp;
        }

    return relatedRec(firstP->tail,person);
}


char ** related(const socialADT soc, const char * person){
        return relatedRec(soc->first,person);
}



/* Retorna una copia de los nombres de las personas en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si no hay personas, retorna un vector que sólo tiene a NULL como
** elemento
 */
char ** persons(const socialADT soc){
        int i;

        if (soc->cantPerson==0){
                char ** new = malloc(sizeof(char*));
                new[0]=NULL;
                return new;
        }

        char ** new=malloc((soc->cantPerson + 1) * sizeof(char*));
        TPerson actual=soc->first;


        for (i=0 ; i<soc->cantPerson ; i++){
                strcpy(new[i],actual->name);
                actual=actual->tail;
        }

new[i]=NULL;
return new;
}



/* Libera todos los recursos reservados por el TAD */

static void freeFriend (TFriend first) {

        if (first==NULL)
                return;
        freeFriend(first->tail);
        free(first);
}

static void freePerson(TPerson firstP){
        if (firstP==NULL)
                return;
        freePerson(firstP->tail);
        freeFriend(firstP->first);
        free(firstP);
}




void freeSocial(socialADT soc){
        freePerson(soc->first);
        free(soc);
}

