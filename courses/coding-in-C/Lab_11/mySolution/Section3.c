#include <stdio.h>
#include <stdlib.h>

typedef struct queue_elem{
    int Inform1;

    struct queue_elem * pnext;
} queue_elem;

typedef struct queue {
    queue_elem* head;
    queue_elem* tail;
} queue;

queue* queue_init() {
    queue* q =malloc(sizeof *q);
    q->head=NULL;
    q->tail=NULL;
    return q;
}

void enqueue(queue* q, int a) {
    queue_elem* el= malloc(sizeof *el);
    el->Inform1=a;
    el->pnext=NULL;
    if((q->head && q->tail)==NULL) {
        q->head =el;
        q->tail=el;
    } else {
        q->tail->pnext = el;
        q->tail =el;
    }
}

int dequeue(queue* q) {
    if(q->head == NULL && q->tail == NULL) {
        printf("Leer");
        return-1;
    } else {
        queue_elem* out= q->head;
        q->head = out->pnext;
        out->pnext =NULL;
        int ausgabe = out->Inform1;
        free(out);
        return ausgabe;
    }
}

void queue_löschen(queue* q) {
    while(q->head!=NULL){
        dequeue(q);
    }
free(q);
}

void print(queue* q) {
    queue_elem* tmp= q->head;
    printf("Queue:\n") ;
    while(tmp != NULL) {
        printf("%d\n", tmp->Inform1);
        tmp= tmp->pnext;
    }
}

int main() {

    queue* queue1 = queue_init();
    enqueue(queue1, 10);
    enqueue(queue1, 20);
    print(queue1);

    dequeue(queue1);
    print(queue1);

    return 0;
}