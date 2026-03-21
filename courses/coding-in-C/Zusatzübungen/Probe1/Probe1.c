#include "Probe1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


void init_list(List* l) {
    l->head=NULL;
}

Task* create_task(int id, int priority, const char* text) {
    Task* new_task = malloc(sizeof (*new_task));
    if(new_task==NULL) {
        printf("Speicherfehler");
        return;
    }
    new_task->id= id;
    new_task->priority= priority;
    strncpy(new_task->text, text, sizeof((new_task->next->text)-1));
    new_task->text[sizeof(new_task->text)-1] = '\0';
    new_task->next=NULL;

    return new_task;
}

void insert_front(List* l, Task* new_task) {
    if(l->head==NULL) {
        printf("Liste leer");
        return;
    }
    new_task->next=l->head;
    l->head=new_task;
}

void insert_back(List* l, Task* new_task) {
    if(l->head==NULL || new_task==NULL) {
        return;
    }
    Task* p_current= l->head;
    while(p_current->next!=NULL) {
        p_current=p_current->next;
    }
    p_current->next=new_task;
}

Task* find_task(List* l, int id) {
    if(l->head==NULL) {
        return;
    }
    Task* p_current= l->head;
    while(p_current!=NULL) {
        if(p_current->id== id) {
            return p_current;
        }
        p_current=p_current->next;
    }
}

int delete_task(List* l, int id) {
    assert(l!=NULL);
    Task* p_current= l->head;

    //Zu löschendes Element ist erstes element
    if(l->head->next->id==id) {
        l->head->next=l->head->next->next;
        return l->head->next;
    }
    
    //Zu löschendes Elemnt ist in Liste (ab 2.Element)
    Task* p_current_prev=l->head->next;
    Task* p_current_follow=l->head->next->next;

    while(p_current!=NULL) {
        if(p_current->id== id) {
            p_current_prev=p_current_follow;
            p_current=NULL;
            return p_current;
        }
        p_current=p_current->next;
        p_current_prev=p_current_prev->next;
        p_current_follow=p_current_follow->next;
    }  
}

void print_list(List* l) {
    assert(l!=NULL);

    Task* p_current=l->head;
    printf("Liste: \n");
    while(p_current!=NULL) {
        printf("ID:%d||Priorität:%d", p_current->id, p_current->priority);
        p_current=p_current->next;
    }
    printf("----------------\n");
}

void free_list(List* l) {
    assert(l!=NULL);

    Task* p_current = l->head;
        while(p_current!=NULL) {
            Task* p_temp=p_current;
            p_current=p_current->next;
            free(p_temp);
        }
    l->head=NULL;
}