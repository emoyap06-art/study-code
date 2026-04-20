#include "test.h"
#include <stdio.h>

int main () {
    List l1;
    init_list(&l1);

    Node* n1=create_node(0);
    Node* n2=create_node(1);
    Node* n3=create_node(2);
    Node* n4=create_node(3);
    Node* n5=create_node(4);
    Node* n6=create_node(5);

    push_front(&l1, n1);
    push_front(&l1, n2);
    push_back(&l1, n3);
    push_back(&l1, n4);

    insert_after(&l1, 1, n5);
    insert_after(&l1, 0, n6);

    delete_value(&l1, 0);
    print_list(&l1);
    free_list(&l1);

    return 0;


}