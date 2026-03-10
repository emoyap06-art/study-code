    #include "Übung.h"

    void append(List* list, int value){
    
    Node* NewNode= malloc(sizeof(*NewNode));
    if(NewNode==NULL) {
        printf("Speicherallokation fehlgeschlagen");
        return;
    }
    NewNode->value = value;
    NewNode->next=NULL;

  if(list->head==NULL){
    list->head=NewNode;
    return;
  }

  if(list->head!=NULL){
    Node* current = list->head;
    while(current->next!=NULL){
        current= current->next;
     }
    current->next=NewNode;
    }
}