#include "test.h"
#include <stdio.h>

int main () {
    List l1;
    init_list(&l1);


Customer* C1 = create_customer(1, 10, "hans");
Customer* C2 = create_customer(2, 20, "günter");
Customer* C3 = create_customer(3, 30, "peter");
Customer* C4 = create_customer(4, 40, "alpereen");
Customer* C5 = create_customer(5, 50, "alparslan");
Customer* C6 = create_customer(6, 60, "metehan");

    
insert_front(&l1, C1);
insert_front(&l1, C2);
insert_back(&l1, C3);
insert_back(&l1, C4);
insert_at(&l1, C5, 2);
insert_at(&l1, C6, 5);

print_list(&l1);

Customer* found = find_customer(&l1, 1);
if(found != NULL) {
    printf("Gefunden: ID:%d AGE:%d NAME:%s\n", found->id, found->age, found->name);
}

delete_customer(&l1, 1);
print_list(&l1);

delete_customer(&l1, 3);
print_list(&l1);

delete_customer(&l1, 10);
print_list(&l1);


free_list(&l1);

return 0;

}