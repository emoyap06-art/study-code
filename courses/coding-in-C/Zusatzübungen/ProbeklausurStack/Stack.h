#ifndef STACK_H
#define STACK_H

typedef struct Action {
    int id;

    struct Action* p_next;
} Action;

typedef struct {
    Action* p_top;
} Stack;

void init_stack(Stack* p_stack);
Action* create_action(int id);
void pop(Stack* p_stack);
void push(Stack* p_stack, Action* p_action);
void print_stack(Stack* p_stack);

#endif