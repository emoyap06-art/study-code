#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_list(List *l) {
    l->head=NULL;
}

Customer* create_customer(int id, int age, const char *name) {
    Customer* new_customer = malloc(sizeof(*new_customer));
    if(new_customer==NULL) {
        printf("Speicherfehler");
        return NULL;
    }
    new_customer->id=id;
    new_customer->age=age;
    strncpy(new_customer->name, name, strlen(name)+1);
    new_customer->next=NULL;
    return new_customer;
}

void insert_front(List *l, Customer *new_customer) {
    new_customer->next=l->head;
    l->head=l->head->next;
}

void insert_back(List *l, Customer *new_customer) {
    if(l->head==NULL) {
        l->head=new_customer;
        return;
    }
    Customer* p_current=l->head;
    while(p_current->next!=NULL) {
        p_current=p_current->next;
    }
    p_current->next=new_customer;
    return;
}

int insert_at(List *l, Customer *new_customer, int position) {
    if(position<0) {
        printf("Falsche Eingabe\n");
        return -1;
    }

    else if(position==0) {
        insert_front(l, new_customer);
    } 
    Customer* p_current=l->head;
    int i=0;
    while(p_current!=NULL && i<position-1) {
        p_current=p_current->next;
        i=i++;
    }
    if(p_current==NULL) {
        return -1;
    }
    new_customer->next=p_current->next;
    p_current->next=new_customer;
    return 1;
}   

Customer* find_customer(List *l, int id) {
    Customer* p_current=l->head;
    while(p_current!=NULL) {
        if(p_current->id==id) {
            return p_current;
        }
        p_current=p_current->next;
    }
    printf("Nicht gefunden\n");
    return p_current;
}

int delete_customer(List *l, int id){
    if(l->head==NULL) {
        printf("Nichts zu löschen\n");
        return -1;
    }

    //an erster Stelle
    if(l->head->id==id) {
        Customer* p_tmp=l->head;
        l->head=l->head->next;
        free(p_tmp);
        return 1;
    }

    Customer* p_current=l->head->next;
    Customer* p_current_prev= l->head;
    while(p_current!=NULL){
        if(p_current->id==id) {
            p_current_prev->next=p_current->next;
            free(p_current);
            return 1;
        }
        p_current_prev=p_current;
        p_current=p_current->next;
    }
    printf("ID nicht gefunden\n");
    return -1;
}

void print_list(List *l) {
    if(l->head==NULL) {
        printf("Liste leer\n");
        return;
    }

    Customer* p_current=l->head;
    while(p_current!=NULL) {
        printf("ID:%d\tAGE:%d\tNAME:%s", p_current->id, p_current->age, p_current->name);
        p_current=p_current->next;
    }
}

void free_list(List *l) {
    Customer* p_current=l->head;
    while(p_current!=NULL) {
        Customer* p_tmp=p_current;
        p_current=p_current->next;
        free(p_tmp);
    }
    l->head=NULL;
}