#include "Stack.h"
#include <stdio.h>
#include <string.h>


int main() {

    stack s1;
    init_stack(&s1);
    char text [100];

    printf("Geben Sie Klammern ein:\n");
    scanf(" 99%s", &text); 

    for(int i=0; i< strlen(text); i++) {
        if(text[i] == '(') {
            push(&s1, '(');
        } else if (text[i]== ')') {
            if(is_empty(&s1)) {
                ("Falsche Eiingabe");
                return 0;
            }
            pop(&s1);
        }
    }

    if(is_empty(&s1)) {
        printf("Klammern korrekt");
    } else {
        printf("Fehlerhafte Klammen");
    }

    return 0;
}