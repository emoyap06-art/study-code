#include "tasks.h"
#include <stdio.h>

int main () {
    TaskList l1;
    init_list(&l1);

    for(int i=0; i<12; i++) {
        if((i%3)==0) {
            Task* T1= create_task(i, i, "learn");
            Task* T2= create_task(i+1, i+1, "eat");
            insert_back(&l1, T1);
            insert_back(&l1, T2);
        } 
        else if((i%2)==0) {
            find_task(&l1, 1);
        } 
        else if((i%2)==1) {
            remove_task(&l1, 1);
        }
        print_list(&l1);
    }
    save_to_file(&l1, "Datei.txt");
    TaskList l2;
    init_list(&l2);

    load_from_file(&l2, "Datei.txt");
    print_list(&l2);


    free_list(&l1);
    free_list(&l2);
    return 0;


}