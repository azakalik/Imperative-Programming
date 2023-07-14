
// Depende de la función, la lista luego podría quedar inconsistente, ¿por qué?
void
map(listADT list, elemType (*fn)(elemType)) {
      nodeP aux = list->first;
      while ( aux != NULL) {
          aux->head = fn(aux->head);
          aux = aux->tail;
      }
}
