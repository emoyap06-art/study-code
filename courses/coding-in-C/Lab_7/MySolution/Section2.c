#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    double value;

    struct node* p_next;
} node;

/*typedef struct node_list {
    node *p_head;
} node_list;
*/

node *newNode(double value) {
    node* newNode= malloc(sizeof (*newNode));
    if(newNode == NULL){
        printf("Fehler beim erstellen des Speichers");
        return NULL;
    }
    
    newNode->value =value;
    newNode->p_next = NULL;
    return newNode;
}

int main() {

    srand(time(NULL));

    node* head = NULL;
    node* second = NULL;

    for(int i=0; i<50; i++) {
        node* p_help =newNode(rand());
        p_help->p_next = head;
        head=p_help;
    }

    //Array erstellen
    int array[51];
    for (int i=0; i<50; i++) {
        array[i] = rand();
    }
    //Array 1 nach rechts shiften
    for(int i= 50; i>3; i--) {
        array[i]= array[i-1];
    }
    //Random Zahl an 4.Stelle im Array positionieren
    int insert_random_number= rand();
    array[3]= insert_random_number;

    //Random Zahl an dritte Stelle in Liste positionieren
    second= head->p_next;
    node* p_help2= newNode(insert_random_number);
    p_help2->p_next= second->p_next;
    second->p_next= p_help2;
 
    for(int i=0; i<51; i++) {
        printf("Array: %d\n", array[i]);
    }
    printf("\n\n");

    node* counter;
    counter = head;
    while(counter!=NULL) {
        printf("Liste: %2.f\n", counter->value);
        counter = counter->p_next;
    }
    free(second);
    free(p_help2);
    free(head);
    free(counter);

    return 0;
}