#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack(Stack* p_stack) {
    if(p_stack==NULL) {
        return;
    }
    p_stack->p_top=NULL;
}

Action* create_action(int id) {
    Action* p_action=NULL;
    p_action =malloc(sizeof (*p_action));
    if (p_action==NULL) {
        printf("Speichefehler");
        return NULL;
    }
    p_action->id= id;
    p_action->p_next=NULL;

    return p_action;
}

/*
int pop (Stack* p_stack){
    if(p_stack->p_top==NULL) {
        printf("Noch keine Aktion durchgeführt");
        return -1;
    }
    Action* p_tmp = p_stack->p_top;
    int id = p_tmp->id;
    p_stack->p_top=p_stack->p_top->p_next;
    p_tmp->p_next=NULL;
    free(p_tmp);
    return id;
}
*/

void pop(Stack* p_stack) {
    if(p_stack==NULL || p_stack->p_top==NULL) {
        printf("Noch keine Aktion durchgefphrt");
        return;
    }
    Action* p_tmp= p_stack->p_top;
    p_stack->p_top=p_tmp->p_next;
    free(p_tmp);

}
void push(Stack* p_stack, Action* p_action) {
    if(p_stack==NULL || p_action==NULL) {
        return;
    }
    p_action->p_next=p_stack->p_top;
    p_stack->p_top=p_action;
}

void print_stack(Stack* p_stack) {
    if(p_stack==NULL || p_stack->p_top==NULL) {
        printf("Erst Aktion hinzufügen");
        return;
    }
    printf("Ids:\n");
    Action* p_current= p_stack->p_top;
    while(p_current!=NULL) {
        printf("%d\n", p_current->id);
        p_current=p_current->p_next;
    }
    printf("---------------\n");
}
