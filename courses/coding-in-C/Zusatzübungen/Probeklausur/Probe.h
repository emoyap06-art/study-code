#ifndef PROBE_H
#define PROBE_H


typedef struct task {
    int id;
    int priority;
    char* text;
    struct task* next;
}task;

typedef struct {
    task* head;
} List;

void init_list(List* l);
void add_task(List* l, int id, int priority, const char* text);
void remove_task(List* l);
void print_list(List*l);

void read_file(List* l, const char* filename);
void write_file(List* l, const char* filename);

#endif