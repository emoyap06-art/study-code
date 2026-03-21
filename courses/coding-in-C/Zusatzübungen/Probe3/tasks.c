#include "tasks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_list(TaskList *list) {
    list->head=NULL;
}

Task* create_task(int id, int priority, const char *text) {
    Task* NewTask= malloc(sizeof(*NewTask));
    if(NewTask==NULL) {
        printf("Speicherfehler");
        return NULL;
    }
    NewTask->id=id;
    NewTask->priority=priority;
    strncpy(NewTask->text, text, sizeof(NewTask->text)-1);
    NewTask->text[sizeof(NewTask->text)-1] = '\0';
    NewTask->next=NULL;

    return NewTask;
}

void insert_back(TaskList *list, Task *new_task) {
    if(list->head==NULL) {
        list->head=new_task;
        return;
    }
    Task* p_current= list->head;
    while(p_current->next!=NULL) {
        p_current=p_current->next;
    }
    p_current->next=new_task;
}

Task* find_task(TaskList *list, int id) {
    if(list->head==NULL) {
        printf("Lisre leer\n");
        return NULL;
    }
    Task* p_current= list->head;
    while(p_current!=NULL) {
        if(p_current->id==id) {
            return p_current;
        }
        p_current=p_current->next;
    }
    return NULL;
}

int remove_task(TaskList *list, int id) {
    if(list->head==NULL) {
        printf("Liste leer");
        return -1;
    }
    //Falls Element am Anfang
    if(list->head->id==id) {
        Task* p_help= list->head;
        list->head=list->head->next;
        free(p_help);
        return 1;
    }
    Task* p_current= list->head->next;
    Task* p_current_prev= list->head;
    while(p_current!=NULL) {
        if(p_current->id==id) {
            p_current_prev->next=p_current->next;
            free (p_current);
            return 1;
        }
        p_current=p_current->next;
        p_current_prev=p_current_prev->next;
    }
    return -1;
}

void print_list(TaskList *list) {
    if(list->head==NULL) {
        printf("Liste leer");
        return;
    }

    Task* p_current=list->head;
    while(p_current!=NULL) {
        printf("ID:%d; Prio:%d; Name:%s\n", p_current->id, p_current->priority, p_current->text);
        p_current=p_current->next;
    }
}

void free_list(TaskList *list) {
    Task* p_current = list->head;
    while(p_current!=NULL) {
        Task* p_tmp= p_current;
        p_current=p_current->next;
        free(p_tmp);
        
    }
    list->head=NULL;
}

int text_length(const char *text) {
    int length= strlen(text);
    return length;
    
}

int save_to_file(TaskList *list, const char *filename) {
    FILE* p_file= fopen(filename, "w");
    if (p_file==NULL) {
        printf("Datei konnte nicht geöffnet werden");
        return -1;
    }

    Task* p_current=list->head;
    char text [256];

    while(p_current!=NULL) {
        sprintf(text, "%d;%d;%s\n", p_current->id, p_current->priority, p_current->text);

        fputs(text, p_file);
        p_current=p_current->next;
    }
    fclose(p_file);
    return 1;
}

int load_from_file(TaskList *list, const char *filename) {
    
    FILE* p_file2= fopen(filename, "r");
    if(p_file2==NULL) {
        printf("Datei konnte nicht geöffnet werden");
        return -1;
    }

    char buffer [256];

    while(fgets(buffer, sizeof(buffer), p_file2)!=NULL) {
        int id;
        int priority;
        char text [100];

        buffer[strcspn(buffer, "\n")]='\0';

        if(sscanf(buffer, "%d;%d;%99[^\n]", &id, & priority, text)==3) {
            Task *t= create_task(id, priority, text);
            insert_back(list, t);
        }
    }
    fclose(p_file2);
    return 1;
}