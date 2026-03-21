#ifndef PROBE_H
#define PROBE_H

typedef struct customer {
    int id;
    char name [100];
    int age;
    struct customer* next;
} Customer;

typedef struct {
    Customer* head;
} List;

void init_list(List*l);
Customer* create_customer(int id, const char* name, int age);

void insert_front(List* l, Customer* new_customer);
void insert_back(List* l, Customer* new_customer);

Customer* find_customer(List* l, int id);
int delete_customer(List* l, int id);

void print_list(List* l);
void free_list(List* l);

void read_file(List* l, const char* filename);
void write_file(List* l, const char* filename);

#endif