#ifndef STACK_H
#define STACK_H

typedef struct stack_element {
    char value;

    struct stack_element* next;
} stack_element;

typedef struct {
    stack_element* top;
} stack;

void init_stack(stack* s);
void push(stack* s, char value);
char pop(stack* s);
int is_empty(stack*s);

#endif