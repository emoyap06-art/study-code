#ifndef QUEUE_H
#define QUEUE_H


typedef struct job {
    int id;
    int pages;

    struct job* next;
} job;

typedef struct {
    job* head;
    job* tail;
} Queue;

void init_queue(Queue* q);
void enqueue(Queue* q, int id, int pages);
int dequeue(Queue* q);
void print_queue(Queue* q);

#endif