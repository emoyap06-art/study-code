#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_stack(stack* s) {
    s->top=NULL;
}

void push(stack* s, char value) {
    stack_element* NewChar= malloc(sizeof(*NewChar));
    if (NewChar==NULL) {
        printf("Speicherfehler");
        return;
    }
    NewChar->value= value;
    NewChar->next=NULL;

    //Auf Stack pushen
    NewChar->next=s->top;
    s->top=NewChar;
}

char pop(stack* s) {
    if(s->top==NULL) {
        printf("leer");
        return '\0';
    }
    stack_element* p_tmp=s->top;
    char value= p_tmp->value;
    s->top= s->top->next;
    free(p_tmp);
    return value;
}

int is_empty(stack*s) {
    return s->top ==NULL;
}
