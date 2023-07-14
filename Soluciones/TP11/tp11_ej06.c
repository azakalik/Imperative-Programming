elemType
get(listADT list, unsigned int idx) {
        int i;
        nodeP auxi;
        if ( idx >= list->size ) {
                fprintf(stderr, "Indice inválido al llamar a get");
                exit(1);
        }        

        auxi = list->first;
        for(i=0; i<idx; i++)
                auxi = auxi->tail;

        return auxi->head;
}

// Version recursiva
// Ya se valido antes que el indice sea valido, nunca llegaremos a NULL
static elemType getRec(TList first, unsigned int idx) {
    if ( idx == 0 )
       return first->head;
    return getRec(first->tail, idx-1);
}

elemType
get(listADT list, unsigned int idx) {
        if ( idx >= list->size ) {
                fprintf(stderr, "Indice inválido al llamar a get");
                exit(1);
        }        

        return getRec(list->first);
}