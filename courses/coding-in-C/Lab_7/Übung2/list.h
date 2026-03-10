#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} List;

void init_list(List *list);
void push_front(List *list, int value);
void push_end(List* list, int value);
void print_list(List *list);
void delete_first(List* list);
void delete_last(List *list);
int summe_liste(List *list);
int count_nodes(List *list);
void delete_list(List *list);
int contains(List *list, int value);

#endif