#include "Probe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void init_list(List*l) {
    l->head=NULL;
}

Customer* create_customer(int id, const char* name, int age) {
    assert(name!=NULL);

    Customer* new_customer= malloc (sizeof(*new_customer));
    if (new_customer==NULL) {
        printf("Speicherfehler");
        return NULL;
    }
    new_customer->id=id;
    new_customer->age=age;

    strncpy(new_customer->name, name, sizeof(new_customer->name)-1);
    new_customer->name[sizeof(new_customer->name)-1]= '\0';
    new_customer->next=NULL;

    return new_customer;
}


void insert_front(List* l, Customer* new_customer) {
    assert(l!=NULL);
    assert(new_customer!=NULL);

    new_customer->next= l->head;
    l->head=new_customer;
}

void insert_back(List* l, Customer* new_customer) {
    if(l->head==NULL) {
        l->head=new_customer;
        return;
    }

    Customer* p_current=l->head;
    while(p_current->next!=NULL) {
        p_current=p_current->next;
    }
    p_current->next= new_customer;
}

Customer* find_customer(List* l, int id){
    assert(l!=NULL);

    Customer* p_current=l->head;
    while(p_current!=NULL) {
        if(p_current->id==id) {
            printf("%d;%s;%d\n", p_current->id, p_current->name, p_current->age);
            return p_current;
        }
        p_current=p_current->next;
    }
    return NULL;
}

int delete_customer(List* l, int id) {
    assert(l->head!=NULL);

    if(l->head==NULL) {
        printf("Liste leer");
    }

    //Wenn erster Knoten zu löschen ist
    if(l->head->id==id) {
        Customer* p_tmp=l->head;
        l->head=l->head->next;
        free(p_tmp);
        return 1;
    }

    //Wenn andere Knoten zu löschen sind
    Customer* p_current=l->head->next;
    Customer* p_current_prev=l->head;
    Customer*p_current_follow=l->head->next->next;

    while(p_current!=NULL) {
        if(p_current->id==id) {
            p_current_prev->next=p_current_follow->next;
            free(p_current);
            return 1;
        }
        p_current=p_current->next;
        p_current_follow=p_current_follow->next;
        p_current_prev=p_current_prev->next;
    }
    return 0;
}


void print_list(List* l) {
    assert(l!=NULL);

    if(l->head==NULL) {
        printf("Liste leer");
        return;
    }

    printf("Liste:\n");
    Customer* p_current=l->head;
    while(p_current!=NULL) {
        printf("%d;%s;%d\n" ,p_current->id, p_current->name, p_current->age);
        p_current=p_current->next;
    }
    printf("-------\n");
}

void free_list(List* l) {
    Customer* p_current=l->head;

    while(p_current!=NULL) {
        Customer* p_help= p_current;
        p_current=p_current->next;
        free(p_help);
    }
    l->head=NULL;
}

void read_file(List* l, const char* filename) {
    assert(l!=NULL);
    assert(filename!=NULL);

    FILE* p_read= fopen(filename, "r");
    if(p_read==NULL) {
        printf("Datei konnte nicht geöffnet werden\n");
        return;
    }
    char buffer [200];
    while(fgets(buffer, sizeof(buffer), p_read)!=NULL) {
        int id;
        char name[100];
        int age;

        buffer[strcspn(buffer, "\n")]='\0';

        if(sscanf(buffer, "%d;%99[^;];%d", &id, name, &age)==3) {
            Customer* c = create_customer(id, name, age);
            if(c!=NULL) {
                insert_back(l, c);
            }

        }
    }
    fclose(p_read);
}

void write_file(List* l, const char* filename) {
    assert(l!=NULL);
    assert(filename!=NULL);

    FILE* p_write= fopen(filename, "w");
    if(p_write==NULL) {
        printf("Datei konnte nicht geöffnet werden");
        return;
    }

    Customer* current= l->head;
    char buffer [200];
    
    while(current!=NULL) {
        snprintf(buffer, sizeof(buffer), "%d;%s;%d\n", current->id, current->name, current->age);

        fputs(buffer, p_write);
        current=current->next;
    }
    fclose(p_write);
}
