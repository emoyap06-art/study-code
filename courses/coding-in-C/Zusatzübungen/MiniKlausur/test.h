typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

void init_list(List* l);
Node* create_node(int value);
void push_front(List* l, Node* n);
void push_back(List* l, Node* n);
int insert_after(List* l, int target, Node* n);
int delete_value(List* l, int value);
void print_list(List* l);
void free_list(List *l);
