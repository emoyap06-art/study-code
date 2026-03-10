#include <stdio.h>
#include "/workspaces/study-code/courses/coding-in-C/Lab_7/Übung2/list.h"

int main (){

List list1;

init_list(&list1);
push_front(&list1, 10);
push_end(&list1, 20);
push_end(&list1, 30);

print_list(&list1);
summe_liste(&list1);
count_nodes(&list1);
delete_last(&list1);
print_list(&list1);
delete_first(&list1);
print_list(&list1);
delete_list(&list1);
print_list(&list1);

return 0;
}
