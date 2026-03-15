#include "Stack.h"

int main () {

    Stack stack_1;
    init_stack(&stack_1);

    for(int i=0; i<10; i++) {
        if((i%2)==0) {
            Action* a1 = create_action(10);
            Action* a2 = create_action(20);
            push(&stack_1, a1);
            push(&stack_1, a2);
        } else {
        pop(&stack_1);
        }
        print_stack(&stack_1);
    }

    return 0;
}