#ifndef VERKETTET_H
#define VERKETTET_H

typedef struct Node {
    int id;
    float value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

void init_list(List* l);
Node* create_node(int id, float value);
void insert_front(List* l, Node* new_node);
void insert_back(List* l, Node* new_node);
Node* find_node(List* l, int id);
int delete_node(List* l, int id);
void print_list(List* l);
void free_list(List* l);

#endif
