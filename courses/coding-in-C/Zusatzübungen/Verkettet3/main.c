#include "verkettet3.h"
#include <stdio.h>

int main () {
List l1;
init_list(&l1);
for(int i=0; i<10; i++) {
    Node* N = create_node(i, i*3.142);
    if((i%2)==0) {
        insert_front(&l1, N);
        } else {
            insert_back(&l1, N);
        }
    }
    print_list(&l1);
    
    for(int i=0; i<10; i++) {
        if((i%2)==0) {
            delete_node(&l1, i);
        }
    }

    printf("Nach dem Löschen gerade Ids\n");
    print_list(&l1);

    Node* gefunden =find_node(&l1, 5);
    if(gefunden==NULL) {
        printf("Gibt es nicht\n");
        return -1;
    }
    else {
        printf("Gefunden\n ID:%d; Value%d", gefunden->id, gefunden->value);
    }
    free_list(&l1);

    return 0;
}