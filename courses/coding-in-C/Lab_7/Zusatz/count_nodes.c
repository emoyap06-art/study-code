#include "Übung.h"


int count_nodes(List* list){
    int count=0;

    Node* current= list->head;
    while(current!=NULL) {
        count++;
        current=current->next;
    }
    printf("Anzahl Elemente: %d\n", count);
    return count;
}