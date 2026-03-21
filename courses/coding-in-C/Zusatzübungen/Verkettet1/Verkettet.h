#ifndef VERKETTET_H
#define VERKETTET_H

typedef struct node {
    int id;
    int priority;
    char* text;

    struct node* next;
} node;

typedef struct{
    node* head;
} list;


void init_list(list* l);
void add_task(list* l, int id, int priority, const char* text);
void remove_highest_priority(list* l);
void read_firtst(list* l, const char* filename);
void print_list(list* l);
void free_list(list* l);





#endif