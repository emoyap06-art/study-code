#include "Queue.h"
#include <stdio.h>

int main () {
    Queue q1;
    init_queue(&q1);
    int next_id =1;

    print_queue(&q1);
    for(int i=0; i<10; i++) {
        if((i%2)==0) {
            enqueue(&q1, next_id++, 7);
            enqueue(&q1, next_id++, 8);
        } else {
            dequeue(&q1);
        }
        print_queue(&q1);
        printf("\n");
    }
    return 0;
}