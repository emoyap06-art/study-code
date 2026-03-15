#include "Stack.h"

int main () {
    Stack stack1;
    init_stack(&stack1);

    push(&stack1, 5);
    push(&stack1, 8);

    printf("Top value: %d\n", peek(&stack1));

    pop(&stack1);

    printf("Top value: %d\n", peek(&stack1));

    push(&stack1, 3);
    print_stack(&stack1);

    return 0;
}