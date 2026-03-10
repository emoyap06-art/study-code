#ifndef Übung_H
#define Übung_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;


void append(List* list, int value);
void Print_List(List* list);
void delete_first(List* list);
int count_nodes(List* list);

#endif /* Übung_H */