#include "Queue.h"
#include <stdio.h>

int main() {
    queue* q1= init_queue();

    print_queue(q1);
    dequeue(q1);
    
    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    enqueue(q1, 40);
    print_queue(q1);

    dequeue(q1);
    dequeue(q1);
    print_queue(q1);

    delete_queue(q1);
    print_queue(q1);

    return 0;

}