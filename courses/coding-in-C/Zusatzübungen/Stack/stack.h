#ifndef STACK_H
#define STACK_H

typedef struct stack_element {
    int value;
    struct stack_element* next;
} stack_element;

typedef struct stack {
    stack_element *top;
} stack;

stack* init_stack();
void push(stack* s1, int value);
int pop(stack* s1);
int peek(stack* s1);
void print_stack(stack* s);
void delete_stack(stack* s);

#endif 