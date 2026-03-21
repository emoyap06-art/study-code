#include "Probe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_list(List* l) {
    l->head=NULL;
}

void add_task(List* l, int id, int priority, const char* text) {
    task* NewTask=malloc(sizeof (*NewTask));
    if(NewTask==NULL) {
        free(NewTask);
        printf("Speicherfehler");
        return;
    }
    NewTask->id= id;
    NewTask->priority= priority;
    strcpy(NewTask->text, text);
    NewTask->next=NULL;

    //Wenn zuvor leere Liste
    if(l->head==NULL) {
        l->head=NewTask;
        return;
    }
    //Wenn nicht leer
    task* p_current= l->head;
    while(p_current->next!=NULL) {
        p_current=p_current->next;
    }
    p_current->next=NewTask;
}

void remove_task(List* l){
    if(l->head==NULL) {
        printf("Liste leer");
        return;
    }

    task* p_help=l->head;
    l->head=l->head->next;
    free(p_help->text);
    free(p_help);
    return;
}

void print_list(List*l) {
    task* p_current=l->head;
    if(p_current==NULL) {
        printf("Liste leer");
    }
    while(p_current!=NULL) {
        printf("%d; %d; %s", p_current->id, p_current->priority, p_current->text);
        p_current=p_current->next;
    }
    printf("\n");
}

