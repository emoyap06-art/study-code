#ifndef TEST_H
#define TEST_H

typedef struct Customer {
    int id;
    int age;
    char name[50];
    struct Customer *next;
} Customer;

typedef struct {
    Customer *head;
} List;

void init_list(List *l);

Customer* create_customer(int id, int age, const char *name);

void insert_front(List *l, Customer *new_customer);

void insert_back(List *l, Customer *new_customer);

int insert_at(List *l, Customer *new_customer, int position);

Customer* find_customer(List *l, int id);

int delete_customer(List *l, int id);

void print_list(List *l);

void free_list(List *l);

#endif 