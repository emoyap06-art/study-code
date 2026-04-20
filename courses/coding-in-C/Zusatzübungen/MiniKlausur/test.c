#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_list(List* l) {
    l->head=NULL;
}

Node* create_node(int value) {
    Node* n=malloc(sizeof(*n));
    if(n==NULL) {
        printf("Speicherfehler\n");
        return NULL;
    }
    n->value=value;
    n->next=NULL;
    return n;
}

void push_front(List* l, Node* n) {
    n->next=l->head;
    l->head=n;
    return;
}

void push_back(List* l, Node* n) {
    if(l->head==NULL) {
        l->head->next=n;
        return;
    }

    Node* p_current=l->head;
    while(p_current->next!=NULL) {
        p_current=p_current->next;
    }
    p_current->next=n;
    return;
}

int insert_after(List* l, int target, Node* n) {
    if(target<0) {
        printf("Falsche Eingabe\n");
        return -1;
    }
    if(target==0) {
        l->head->next=n;
    }
    if(target>0) {
        int i=0;
        Node* p_current=l->head;
        while(p_current!=NULL && i<target) {
            p_current=p_current->next;
            i++;
        }
        if(p_current==NULL) {
            printf("Speichern an der Stelle nicht möglich\n");
            return -1;
        }
        n->next=p_current->next;
        p_current->next=n;
        printf("Gespeichert an Stelle: &d", target);
        return 0;
    }
}

int delete_value(List* l, int value) {
    if(l->head==NULL) {
        printf("Liste bereits leer");
        return -1;
    }
    //An erster stelle
    if(l->head->value==value) {
        Node* p_tmp=l->head;
        l->head=l->head->next;
        free(p_tmp);
        return 1;
    }

    Node* p_current_prev= l->head;
    Node* p_current=l->head->next;
    while(p_current!=NULL) {
        if(p_current->value==value) {
            p_current_prev->next=p_current->next;
            free(p_current);
            return 1;
        }
        p_current_prev=p_current;
        p_current=p_current->next;
    }
    if(p_current==NULL) {
        printf("Kein Element gefunden");
        return -1;
    }
}

void print_list(List* l) {
    if(l->head==NULL) {
        printf("Liste leer\n");
        return;
    }

    Node* p_current=l->head;
    while(p_current!=NULL) {
        printf("Werte: %d\n", p_current->value);
        p_current=p_current->next;
    }
    return;
}

void free_list(List *l) {
    Node* p_current=l->head;
    while(p_current!=NULL) {
        Node* p_tmp= p_current;
        p_current=p_current->next;
        free(p_tmp);
    }
    l->head=NULL;
}