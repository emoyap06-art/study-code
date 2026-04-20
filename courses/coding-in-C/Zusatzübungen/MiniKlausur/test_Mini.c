#include <assert.h>
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==Unit-Tests==*/

void test_init_list() {
    List p;
    init_list(&p);

    assert(p.head==NULL);
}

void test_push_front() {
    List p;
    init_list(&p);
    Node* N1= create_node(10);

    assert(p.head==NULL);
    
    push_front(&p, N1);
    assert(p.head==N1);
    assert(N1->next==NULL);
}

int delete_value_before_pushing_() {
    List p;
    init_list(&p);
 
    delete_value(&p, 1);
    assert(p.head==NULL);
}

int main () {
    test_init_list();
    test_push_front();
    delete_value_before_pushing_();

    printf("Alle Tests erfolgreich bestanden");
    return 0;

}
