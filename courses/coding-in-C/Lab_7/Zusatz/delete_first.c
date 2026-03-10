#include "Übung.h"

void delete_first(List* list){
    if(list->head==NULL){
        printf("Liste bereits leer");
    }
    Node* tmp= list->head;
    list->head=tmp->next;
    free(tmp);
    //free(tmp->value);
}