#include "stack.h"
#include <stdio.h>

int main () {
    stack* s1 = init_stack();

    push(s1, 10);
    push(s1, 30);
    push(s1, 30);
    print_stack(s1);

    pop(s1);
    print_stack(s1);
    peek(s1);

    delete_stack(s1);
    print_stack(s1);

    return 0;
}
