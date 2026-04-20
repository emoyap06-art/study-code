typedef struct Node {
    int id;
    char text[50];
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

void init_list(List* l);

Node* create_node(int id, const char* text);

void push_back(List* l, Node* n);

void print_list(List* l);

void free_list(List* l);

int save_to_file(List* l, const char* filename);

int load_from_file(List* l, const char* filename);