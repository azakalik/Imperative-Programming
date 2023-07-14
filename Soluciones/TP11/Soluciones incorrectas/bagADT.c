#include "bagADT.h"
#include <stdlib.h>

typedef struct node{
     elemType elem;
     struct node * tail;
     int count;
}TNode;

typedef TNode * TList;

typedef struct bagCDT{
    TList first;
    size_t size;
}bagCDT;

bagADT newBag()
{
    return calloc(1,sizeof(bagCDT));
}

void freeRec(TList first)
{
    freeRec(first->tail)
    free(first);
}

void freeBag(bagADT bag)
{
    freeRec(bag->first);
    free(bag);
} 

TList addRec(TList first,elemType elem,int * countElem)
{   	
    int c;
	if( first == NULL || (c=compare(first->head, elem)) > 0 ) {
		TList aux = malloc(sizeof( TNode ));

		aux->tail = first;
		aux->head = elem;
		aux->count = 1;
		*countElem = 1;
		return aux;
	}

	if( c < 0 )
		first->tail = addRec( first->tail, elem, countElem);
	else
		*countElem = ++(first->count);
	return first;
}

unsigned int
add( bagADT bag, elemType element) {
	int countElem ;
	bag->first = addRec(bag->first, element, &countElem);
	if (countElem == 1)	// es el primero
		bag->size++;
	return countElem;
}

TList searchElem(TList first,elemType elem,int *flag)
{
    int c=compare(first->elem,elem);
    if(first==NULL || c!=0)
        return NULL; 

    (*flag)=1;
    return first;
}

unsigned int count(const bagADT bag,elemType elem)
{   int flag=0;
    bag->first=searchElem(bag->first,elem,&flag);
    if(flag)
    {
        return bag->first->count;
    }
    return 0;
}
unsigned int size(const bagADT bag)
{
    return bag->size;
} 

elemType mostPopular(bagADT bag)
{   elemType ans;
    if(bag==NULL)
    {
        exit(1);
    } 

    TList aux=bag->first;
    int cant=aux->count;
    ans=aux->elem;
    aux=aux->tail;
    while(aux!=NULL)
    {
        if(aux->count > cant)
        {
            ans=aux->elem;
            cant=aux->count;
        }
        aux=aux->tail;
    }

    return ans;

}