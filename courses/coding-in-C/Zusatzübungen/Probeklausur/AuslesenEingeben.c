#include "Probe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(List* l, const char* filename) {
    FILE* p_file= fopen(filename, "r");
    if(p_file==NULL) {
        printf("Datei konnte nicht geöffnete werden");
        return;
    }
    char line [300];
    int id;
    int priority;
    char text[200];

    while(fgets(line, sizeof(line), p_file)!= NULL) {
        line[strcspn(line, "\n")] = '\0';

        if (scanf(line, "%d;%d;%199[^\n]", &id, &priority, text)==3) {
            add_task(1, id, priority, text);
        }
    }
    fclose(p_file);
}

void write_file(List* l, const char* filename) {
    FILE* p_file2= fopen(filename, "w");
    if(p_file2==0) {
        printf("Datei konnte nicht geöffnet werden");
        return;
    }

    char buffer[256];
    task* p_current=l->head;

    while(p_current!=NULL) {
        sprintf(buffer, sizeof (buffer), "%d;%d;%s\n", p_current->id, p_current->priority, p_current->text);
        fputs(buffer, p_file2);
        p_current=p_current->next;
    }
    fclose(p_file2);
}
