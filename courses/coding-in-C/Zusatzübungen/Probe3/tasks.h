#ifndef TASKS_H
#define TASKS_H


typedef struct Task {
    int id;
    int priority;
    char text[100];
    struct Task *next;
} Task;

typedef struct {
    Task *head;
} TaskList;

void init_list(TaskList *list);

Task* create_task(int id, int priority, const char *text);

void insert_back(TaskList *list, Task *new_task);

Task* find_task(TaskList *list, int id);

int remove_task(TaskList *list, int id);

void print_list(TaskList *list);

void free_list(TaskList *list);

int text_length(const char *text);

int save_to_file(TaskList *list, const char *filename);

int load_from_file(TaskList *list, const char *filename);

#endif