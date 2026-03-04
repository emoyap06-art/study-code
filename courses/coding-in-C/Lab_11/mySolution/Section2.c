#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_Elemente{
    int Information1;
    char Information2[20];

    struct Stack_Elemente *pnext;
} Stack_Elemente;

typedef struct Stack{
    Stack_Elemente* head;
} Stack;

Stack* Stack_Initialisieren() {
    Stack* S= malloc(sizeof *S);
    S->head = NULL;
    return S;
}

void push(Stack *S, int Information1) {
    Stack_Elemente* pNew= malloc(sizeof *pNew);
    pNew->Information1 = Information1;
    pNew->pnext = S->head;
    S->head = pNew;
}

int pop(Stack *S){
    Stack_Elemente* tmp;
    int Information1= S->head->Information1;;
    S->head = S->head->pnext;
    free(tmp);
    return Information1;
}

void Delete_Stack(Stack* S) {
    while(S->head!=NULL) {
        pop(S);
    }
    free(S);
}

void print(Stack* S) {
    Stack_Elemente* tmp=S->head;
    printf("Stack: \n");
    while(tmp!=NULL) {
        printf("%d\n", tmp->Information1);
        tmp= tmp->pnext;
    }
    printf("------------\n");
}

int top(Stack* S) {
    if(S->head ==NULL) {
        printf("Stack is empty\n");
        return -1;
    } else {
        printf("Top element: %d\n", S->head->Information1);
        return S->head->Information1;
        }
}

int main() {

    Stack* S= Stack_Initialisieren();

    push(S,4);
    push(S,12);
    push(S,7);
    print(S);
    top(S);

    pop(S);
    pop(S);
    print(S);
    top(S);

    push(S,10);
    print(S);
    top(S);

    Delete_Stack(S);

    return 0;
}
