#include "Übung.h"



int main() {
    List list_1;
    
    append(&list_1, 15);
    append(&list_1, 19);

    count_nodes(&list_1);
    Print_List(&list_1);
    Print_List(&list_1);

    printf("\n\n");

    delete_first(&list_1);
    count_nodes(&list_1);
    Print_List(&list_1);

    printf("\n\n");

    delete_first(&list_1);
    count_nodes(&list_1);
    Print_List(&list_1);

    return 0;
}