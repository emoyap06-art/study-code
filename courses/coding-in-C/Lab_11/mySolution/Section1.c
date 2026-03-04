#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List_Elemente {
    int Information1;
    char Information2[10];
    struct List_Elemente *pnext;
} List_Elemente;

typedef struct {
    List_Elemente* head;
} List;

void Einfügen(List_Elemente* pNew , List* list) {

    List_Elemente* tmp;
    tmp = list-> head;
    
    while(tmp->pnext!=NULL) {
        tmp= tmp->pnext;
    }
    tmp->pnext = pNew;
}

void Löschen(List_Elemente* pDel, List* list) {
    List_Elemente* tmp;
    List_Elemente* del;
    tmp= list->head;

    if(tmp== pDel){
        list->head = tmp-> pnext;
        free(tmp);
        return;
    }
    while(tmp!= NULL) {
        if(tmp ->pnext ==pDel) {
            del= tmp->pnext;
            tmp-> pnext = del->pnext;
            free(del);
            return;
        }
        tmp= tmp->pnext;
    }
}

void print (List* list) {

    List_Elemente* tmp;
    tmp= list->head;

    while(tmp!= NULL) {
        printf(" %d\n %s", tmp->Information1, tmp->Information2);
        tmp= tmp->pnext;
    }
    printf("--------------\n");

}


int main() {

    List Liste1;
    List_Elemente* a;

    a = malloc(sizeof *a);
    a->Information1 = 10;
    strcpy(a->Information2, "Hallo");
    a->pnext =NULL;

    Liste1.head = a;

    List_Elemente* b;
    b = malloc(sizeof *b);
    b->Information1 = 15;
    strcpy(b->Information2, "Welt");
    b->pnext =NULL;

    print(&Liste1);
    Einfügen(b, &Liste1);
    print(&Liste1);

    return 0;
}