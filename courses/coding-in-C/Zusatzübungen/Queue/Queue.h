#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_elem {
    int value;

    struct queue_elem* p_next;
} queue_elem;

typedef struct queue {
    queue_elem* head;
    queue_elem* tail;
} queue;

queue* init_queue();
void enqueue(queue* q1, int value);
int dequeue(queue* q1);
void print_queue(queue* q1);
void delete_queue(queue* q1);

#endif