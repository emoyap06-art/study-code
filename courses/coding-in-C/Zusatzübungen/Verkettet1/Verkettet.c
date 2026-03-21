#include "Verkettet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_list(list* l) {
    l->head=NULL;
}

void add_task(list* l, int id, int priority, const char* text) {
    node* NewNode=malloc(sizeof (*NewNode));
    if(NewNode==NULL) {
        printf("Speicherfehler");
        return;
    }

    NewNode->id= id;
    NewNode->priority= priority;
    NewNode->text= malloc(strln(NewNode+1));
    if (NewNode==NULL) {
        printf("Speichefehler");
        free(NewNode);
        return;
    }
    strcpy(NewNode->text, text);
    NewNode->next=NULL;

    if(l->head==NULL) {
        l->head=NewNode;
        return;
    }
    node* p_current=l->head;
    while(p_current->next!=NULL) {
        p_current=p_current->next;
    }
    p_current->next=NewNode;
}

void remove_highest_priority(list* l) {
    if(l->head==NULL) {
        printf("Liste leer");
        return;
    }
    node* p_help=l->head;
    int id= p_help->id;
    char* text; strcpy(p_help->text, text);

    l->head=l->head->next;
    free(p_help->text);
    return;
}

void read_firtst(list* l, const char* filename) {
    FILE* p_file= fopen(filename, "r");
    if (p_file==NULL) {
        printf("Datei konnte nicht geöffnet werden");
        return;
    }
    char buffer[300];
    int id;
    int priority;
    char text[300];
    while(fgets(buffer, sizeof (buffer), p_file)!=NULL) {
        buffer[strcspn(buffer, "\n")]= '\0';

        if(sscanf(buffer, "%d;%d;%199[^\n]", &id, &priority, text)==3) {
            add_task(l, id, priority, text);
        }
    }
    fclose(p_file);
}

void print_list(list* l) {
    if(l->head==NULL) {
    printf("Leer");
    return;
}

    node* p_current= l->head;
    while(p_current!=NULL) {
        printf("ID:%d  | Priority:%d.  |  Text:%s", p_current->id, p_current->priority, p_current->text);
        p_current=p_current->next;
    }
    printf("\n");
}

void free_list(list *l) {
    node* p_current;

    while(p_current!=NULL) {
        node* p_next = p_current->next;
        free(p_current->next);
        free(p_current);
        p_current= p_next;
    }
    l->head=NULL;
}