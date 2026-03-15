#ifndef STACK_H
#define STACK_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void init_stack(Stack* s);
void push(Stack* s, int value);
void pop(Stack* s);
void print_stack(Stack* s);
int peek(Stack* s);

#endif /* STACK_H */