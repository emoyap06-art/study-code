#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Queueu namens s1 init.
 * 
 * @param q1 erste Queue schleife
 */
queue* init_queue(){
    queue* q1= malloc(sizeof(*q1));
    if(q1==NULL) {
        printf("Speicherallokation fehlgeschlagen");
        return q1;
    }
    q1->head=NULL;
    q1->tail=NULL;

    return q1;
}

void enqueue(queue* q1, int value) {
    queue_elem* NewElem= malloc(sizeof(*NewElem));
    if(NewElem==NULL) {
        printf("Speicherallokation fehlgeschlagen");
        return;
    }
    NewElem->value =value;
    NewElem->p_next=NULL;


    if(q1->tail==NULL && q1->head==NULL) {
        q1->head=NewElem;
        q1->tail=NewElem;
    }

    if(q1->tail!=NULL) {
        q1->tail->p_next=NewElem;
        q1->tail=NewElem;
    }  
    return;
}

/**
 * 
 * @brief Elemente am Anfang der List enfernen
 * 
 * @param p_tmp Hilfsoininter, der auf Head der List zeigt, damit dieser während des Löschvorgangs nicht abhanden kommt
 */
int dequeue(queue* q1) {
    if(q1->head==NULL && q1->tail==NULL) {
        printf("Liste bereits leer\n");
        return -1;
    }
    queue_elem* p_tmp = q1->head;
    int value = p_tmp->value;
    q1->head = p_tmp->p_next;

    free(p_tmp);
    return value;
}

/**
 * @brief Die Liste soll ausgegeben werden
 * 
 * @parama p_current zeigt auf das aktuelle Element
 */
void print_queue(queue* q1) {
    if(q1->head==NULL) {
        printf("Liste ist leer\n");
        return;
    }
    printf("\nListe:\n");
    queue_elem* p_current= q1->head;
    while(p_current!=NULL) {
        printf("%d\n", p_current->value);
        p_current= p_current->p_next;
    }
    printf("-------------------");
}

/**
 * 
 * @brief gesamt Liste löschen
 * 
 * 
 */
void delete_queue(queue* q1) {

    while(q1->head!=NULL) {
        dequeue(q1);
    }
    free(q1);
}

