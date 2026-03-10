#include "Übung.h"

void Print_List(List* list){
    Node* current =list->head;

    if(list->head==NULL){
        printf("Liste ist Leer. Zum Hinzufügen 'append'. verwenden\n\n");
    }
    while(current!=NULL){
        printf("%d  \n", current->value);
        current=current->next;
    }
}