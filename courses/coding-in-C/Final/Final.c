#include "Final.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_list(List* l) {
    l->head=NULL;
}

Node* create_node(int id, const char* text) {
    Node* n= malloc(sizeof *n);
    if(n==NULL) {
        printf("Speicherfehler\n");
        return NULL;
    }
    n->id=id;
    strncpy(n->text, text, sizeof(n->text)-1);
    n->text[sizeof(n->text)-1] = '\0';
    n->next=NULL;
    return n;
}

void push_back(List* l, Node* n) {
    if(l->head==NULL) {
        l->head=n;
    }
    Node* p_current=l->head;
    while(p_current->next!=NULL) {
        p_current=p_current->next;
    }
    p_current->next=n;
}

void print_list(List* l) {
    if(l->head==NULL) {
        printf("Liste leer\n");
        return;
    }
    Node* p_current=l->head;
    printf("Liste:\n");

    while(p_current!=NULL) {
        printf("ID:%d\tText:%s\n", p_current->id, p_current->text);
        p_current=p_current->next;
    }
}

void free_list(List* l) {
    Node* p_current=l->head;
    while(p_current!=NULL) {
        Node* p_tmp=p_current;
        p_current=p_current->next;
        free(p_tmp);
    }
    l->head=NULL;
    return;
}

int save_to_file(List* l, const char* filename) {
    FILE* p_file= fopen(filename, "w");
    if(p_file==NULL) {
        printf("Fehhler beim Öffnen\n");
        return -1;
    }

    Node* p_current =l->head;
    //Nun müssen der Inhalt der Knoten zwischengespeichert werden und dann zeilenweise in eine Datei geschrieben werden
    char buffer[256];

    while(p_current!=NULL) {
        sprintf(buffer, "%d;%s", p_current->id, p_current->text);
        fputs(buffer, p_file);
        p_current=p_current->next;
    }
    fclose(p_file);
    return 1;
}


int load_from_file(List* l, const char* filename) {
    FILE* p_file = fopen(filename, "r");
    if(p_file == NULL) {
        printf("Fehler beim Oeffnen\n");
        return -1;
    }

    char buffer[256];

    while(fgets(buffer, sizeof(buffer), p_file) != NULL) {
        int id;
        char text[50];

        buffer[strcspn(buffer, "\n")] = '\0';

        if(sscanf(buffer, "%d;%49[^\n]", &id, text) == 2) {
            Node* n = create_node(id, text);
            push_back(l, n);
        }
    }

    fclose(p_file);
    return 1;
}