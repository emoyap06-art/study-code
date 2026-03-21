#ifndef VERKETTET_H
#define VERKETTET_H

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct {
    node* head;
} list;

void init_list(list* l);
void insert_front(list* l, int value);
void insert_back(list* l, int value);
void insert_at(list* l, int value, int position);
node* find(list* l, int value);
void delete_value(list* l, int value);
void print_list(list* l);
void free_list(list* l);

#endif
