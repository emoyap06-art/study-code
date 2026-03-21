#ifndef PROBE1_H
#define PROBE1_H


typedef struct task {
    int id;
    int priority;;
    char text[100];

    struct task* next;
} Task;

typedef struct {
    Task* head;
} List;

void init_list(List* l);
Task* create_task(int id, int priority, const char* text);
void insert_front(List* l, Task* new_task);
void insert_back(List* l, Task* new_task);
Task* find_task(List* l, int id);
int delete_task(List* l, int id);
void print_list(List* l);
void free_list(List* l);

void read_file(List* l, const char* filename);
void write_file(List* l, const char* filename);


#endif
