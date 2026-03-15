#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_queue(Queue* q) {
    q->head=NULL;
    q->tail=NULL;
}

void enqueue(Queue* q, int id, int pages) {
    job* NewJob=malloc(sizeof (*NewJob));
    if (NewJob==NULL) {
        printf("Speicherfehler");
        return;
    }
    NewJob->id= id;
    NewJob->pages= pages;
    NewJob->next=NULL;

    //Hinzufügen, wenn Liste leer ist
    if(q->head==NULL && q->tail==NULL) {
        q->head= NewJob;
        q->tail=NewJob;
    } else {
    //Hinzufügen wenn Liste nicht leer ist
    q->tail->next=NewJob;
    q->tail=NewJob;
    }

}

int dequeue(Queue* q) {
    if(q->head==NULL) {
        printf ("Kein Jobs in Auftrag");
        return -1;
    }
    job* p_help= q->head;
    int id =p_help->id;
    int page= p_help->pages;

    q->head=q->head->next;

    if(q->head==NULL) {
        q->tail=NULL;
    }

    free(p_help);
    return id;
}

void print_queue(Queue* q) {
    job* p_current=q->head;
    if(p_current==NULL) {
        printf("List leer");
        return;
    }
    
    while(p_current!=NULL) {
        printf("ID: %d  Seite: %d", p_current->id, p_current->pages);
        p_current= p_current->next;
    }
}