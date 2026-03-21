#include "verkettet3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_list(List* l) {
    l->head=NULL;
}

Node* create_node(int id, float value) {
    Node* new_node= malloc(sizeof(*new_node));
    if (new_node==NULL) {
        printf("Speicherfehler");
        return NULL;
    }
    new_node->id=id;
    new_node->value= value;
    new_node->next=NULL;
    return new_node;
}

void insert_front(List* l, Node* new_node) {
    new_node->next=l->head;
    l->head=new_node;
    
}

void insert_back(List* l, Node* new_node) {
    if(l->head==NULL) {
        l->head=new_node;
    }
    Node* p_current=l->head;
    while(p_current->next!=NULL) {
        p_current=p_current->next;
    }
    p_current->next=new_node;
}

Node* find_node(List* l, int id) {
    if(l->head==NULL) {
        printf("Liste leer\n");
        return NULL;
    }

    Node* p_current=l->head;
    while(p_current!=NULL) {
        if(p_current->id==id) {
            return p_current;
        }
        p_current=p_current->next;
    }
    return NULL;
}

int delete_node(List* l, int id) {
    if(l->head==NULL) {
        printf("Keine Elemete vorhanden\n");
        return -1;
    }

    //Element an erster Stelle
    if(l->head->id==id) {
        Node* p_tmp=l->head;
        l->head=l->head->next;
        free(p_tmp);
        return 1;
    }

    //Eelment nicht an erster Stelle

    Node* p_current_prev= l->head;
    Node* p_current=l->head->next;
    while(p_current!=NULL) {
        if(p_current->id=id) {
            p_current_prev->next=p_current->next;
            free(p_current);
            return 1;
        }
        p_current_prev=p_current;
        p_current=p_current->next;
    }
    printf("Diese ID konnte nicht gefunden werden\n");
    return -1;
}

void print_list(List* l) {
    if(l->head==NULL) {
        printf("Liste leer\n");
        return;
    }
    Node* p_current=l->head;
    printf("Liste:\n");
    while(p_current!=NULL) {
        printf("ID:%d \tValue:%f\n", p_current->id, p_current->value);
        p_current=p_current->next;
    }
}

void free_list(List* l) {
    if(l->head!=NULL) {
        Node* p_current=l->head;

        while(p_current!=NULL) {
            Node* p_help=p_current;
            p_current=p_current->next;
            free(p_help);
        }
        l->head=NULL;
    }
return;
}