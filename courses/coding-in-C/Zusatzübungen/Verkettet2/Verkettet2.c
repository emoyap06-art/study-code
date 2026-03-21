#include "Verkettet2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_list(list* l) {
    l->head=NULL;
}

void insert_front(list* l, int value) {
    node* NewNode = malloc(sizeof (*NewNode));
    if(NewNode==NULL) {
        prinrf("Speicherfehler");
        return;
    }

    NewNode->value=value;
    NewNode->next=NULL;

    NewNode->next= l->head;
    l->head=NewNode;
}

void insert_back(list* l, int value) {
    node* NewNode= malloc(sizeof (*NewNode));
    if(NewNode==NULL) {
        printf("Speicherfehhler");
        return;
    }
    NewNode->value=value;
    NewNode->next=NULL;

    if(l->head==NULL) {
        l->head=NewNode;
        return;
    }

    node* p_current=l->head;
    while(p_current->next!=NULL) {
        p_current=p_current->next;
    }
    p_current->next=NewNode;
}

void insert_at(list* l, int value, int position) {
}

void insert_at(list* l, int value, int position) {
    if(position<=0 || l->head==NULL) {
        insert_front(l, value);
        return;
    }

    node* NewNode= malloc(sizeof (*NewNode));
    if(NewNode==NULL) {
        printf("Speicherfehhler");
        return;
    }
    NewNode->value=value;
    NewNode->next=NULL;

    //an n-ter Stelle
    node* current= l->head;
    for(int i=0; i<position-1; i++) {
        current=current->next;
    }  
    NewNode->next= current->next;
    current->next=NewNode;
}

node* find(list* l, int value) {
    node* p_help= l->head;
    int Position=0;
    while(p_help!=NULL && p_help->value!=value) {
        p_help=p_help->next;
        Position++;
    }
    if(p_help==NULL) {
        printf("Element nicht in der Liste vorhanden\n");
        return NULL;
    }

    if(p_help!=NULL) {
        printf("Wert '%d' ist in Liste an Position %d\n", p_help->value, Position);
        return p_help;
    }
}
void delete_value(list* l, int value) {
    if(l->head==NULL) {
        printf("Liste leer\n");
        return;
    }

    //element an erster Stelle
if(l->head->value==value) {
    node* p_tmp=l->head;
    l->head=l->head->next;
    free(p_tmp);
    printf("Element mit Wert %d entfernt\n", value);
    return 0;
}

node* prev =l->head;
node* curr= l->head->next;

int Position =0;
while(curr!=NULL && curr->value!=value) {
    curr=curr->next;
    prev=curr;
    Position++;
}
if(curr==NULL) {
    printf("Element nicht in der Liste vorhanden\n");
    return;
}

prev->next=curr->next;
free(curr);
printf("Element %d enfernt", value);

}

void print_list(list* l) {
    node* p_current=l->head;
    printf("Werte:\n");
    while(p_current!=NULL) {
        printf("%d", p_current->value);
        p_current=p_current->next;
    }
    printf("\n");
}

void free_list(list* l) {
    node* p_current=l->head;
    while(p_current!=NULL) {
        node* p_tmp= p_current;
        p_current=p_current->next;
        free(p_tmp);
    }
    l->head=NULL;
}