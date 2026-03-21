#include <stdio.h>
#include <string.h>
#include "Probe.h"

int main(void) {
    List customer_list;
    init_list(&customer_list);

    read_file(&customer_list, "customers.txt");

    printf("Liste nach dem Einlesen:\n");
    print_list(&customer_list);

    for (int i = 0; i < 4; i++) {
        int id;
        int age;
        char name[100];

        printf("\nNeuer Kunde %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &id);
        getchar();

        printf("Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Alter: ");
        scanf("%d", &age);
        getchar();

        Customer* c = create_customer(id, name, age);
        if (c != NULL) {
            insert_back(&customer_list, c);
        }

        printf("Aktuelle Liste:\n");
        print_list(&customer_list);
    }

    int search_id;
    printf("\nID zum Suchen: ");
    scanf("%d", &search_id);

    Customer* found = find_customer(&customer_list, search_id);
    if (found != NULL) {
        printf("Gefunden: ID=%d | Name=%s | Alter=%d\n",
               found->id, found->name, found->age);
    } else {
        printf("Kunde nicht gefunden.\n");
    }

    int delete_id;
    printf("\nID zum Loeschen: ");
    scanf("%d", &delete_id);

    if (delete_customer(&customer_list, delete_id)) {
        printf("Kunde geloescht.\n");
    } else {
        printf("Kunde nicht gefunden.\n");
    }

    printf("\nListe nach dem Loeschen:\n");
    print_list(&customer_list);

    write_file(&customer_list, "output.txt");
    free_list(&customer_list);

    return 0;
}