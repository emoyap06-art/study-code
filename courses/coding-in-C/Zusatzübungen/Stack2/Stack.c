#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>


void init_stack(Stack* s) {
    s->top=NULL;
}
void push(Stack* s, int value) {
    Node* NewNode= malloc (sizeof (*NewNode));
    if (NewNode==NULL) {
    printf("Speicherfehler");
    return;
}
    NewNode->value=value;
    NewNode->next= s->top;
    s->top=NewNode;
}

void pop(Stack* s) {
    if(s->top==NULL) {
        printf("Stack is empty");
        return;
    }
    Node* p_tmp= s->top;
    s->top=s->top->next;
    free(p_tmp);
}

void print_stack(Stack* s) {
    Node* p_current=s->top;
    printf("Numbers in Stack:\n");
    while(p_current!=NULL) {
        printf("%d\n", p_current->value);
        p_current= p_current->next;
    }
    printf("---------\n");
    return;
}

int peek(Stack* s) {
    if(s->top==NULL) {
        printf("Empty");
        return -1;
    }

    int peek=s->top->value;
    return s->top->value;

}