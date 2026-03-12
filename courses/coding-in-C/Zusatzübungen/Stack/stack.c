#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * @brief Einen Stapel initialisieren
 * 
 * @param Stapel_1 Pointer zeigt auf den ersten Stapel
 */

stack* init_stack() {
    stack* s1= malloc(sizeof (*s1));
    if(s1==NULL) {
        printf("Speicherallokation fehlheschlagen");
        return NULL;
    }
    s1->top=NULL;
    return s1;
}

/**
 * 
 * @brief Neues Element auf Stapel legen
 * 
 * @param NewElement Neues Element, das auf den Stapel gelegt wird mit Wert value
 */

void push(stack* s1, int value) {
    stack_element* NewElement= malloc(sizeof (*NewElement));
    if(NewElement==NULL) {
        printf("Speicherallokation fehlgeschlagen\n");
        return;
    }
    NewElement->value  =value;
    NewElement->next= s1->top;
    s1->top = NewElement;
}

/**
 * @brief Oberstes element des Stacks soll entfenrt und ausgegeben werden
 * 
 * @param p_help Zur Zwischenspeicherung des ersten Wertes
 */
int pop(stack* s1) {
    if(s1->top==NULL) {
        printf("Liste ist leer");
        return -1;
    }

    stack_element* p_help= s1->top;
    int value = s1->top->value;
    s1->top= p_help->next;
    free(p_help);
    return value;
}

/**
 * 
 * @brief Erstes Element ausgeben, ohne zu löschen
 */

int peek(stack* s1) {
    if(s1->top==NULL){
        printf("Kein Wert vorhanden\n");
        return -1;
    }

    int value= s1->top->value;
    return value;
}

/**
 * 
 * @brief Stack Liste ausgeben
 * 
 */
void print_stack(stack* s1) {
    if(s1->top==NULL) {
        printf("Liste ist leer");
        return;
    }

    stack_element* p_current=s1->top;
    printf("Werte der Liste: \n");
    while(p_current!=NULL) {
        printf(" %d\n", p_current->value);
        p_current= p_current->next;
    }
    printf("-------------------\n");
}

void delete_stack(stack* s1) {
    while(s1->top!=NULL) {
        pop(s1);
    }
    free(s1);
}

