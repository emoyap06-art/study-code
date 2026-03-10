#include <stdio.h>
#include <stdlib.h>
#include "/workspaces/study-code/courses/coding-in-C/Lab_7/Übung2/list.h"

/**
 * @brief Liste namens list1 initialisieren
 * 
 * @param list1 neue leere erste Liste
 */
void init_list(List *list1) {
    list1->head=NULL;
}

/**
 * @brief Am Anfasng der List ein neues Element anfügen 
 * 
 * @param NewNode neues Element
 */
void push_front(List *list1, int value) {
    Node* NewNode= malloc(sizeof (*NewNode));
    if (NewNode==NULL) {
        printf("Erstellen fehlgeschlagen");
        return;
    }
    NewNode->value = value;
    
    NewNode->next = list1->head;
    list1->head= NewNode; 
    return;
}

/**
 * @brief Am Ende der Liste ein neues Element anfügen
 * 
 * @param p_help Hilfsointer, der bis zu letzetn stellt iteriert
 */
void push_end(List *list1, int value) {
    Node* NewNode= malloc(sizeof (*NewNode));
    if(NewNode==NULL) {
        printf("Speicherallokation fehlgeschlagen");
        return;
    }    
    NewNode->value = value;
    NewNode->next = NULL;

    if(list1->head==NULL){
        list1->head = NewNode;
    }
    //Pointer zum durchzähleb bis zum Ende, um dort dann einzusetzen
    Node* p_help;
    p_help= list1->head;

    while(p_help->next!=NULL) {
        p_help= p_help->next;
    }
    p_help->next= NewNode;
    return;
}

/**
 * @brief Die erstellte Liste ausgeben
 * 
 * @param p_current Ponter, der durch Liste iteriert und mit dessen Hilfe die gesamte List ausgegeben wird
 */

void print_list(List* list1) {

    if(list1->head==NULL){
        printf("Die Liste ist leer\n");
        return;
    }

    //pointer, der durch Liste läuft und jeden Wert ausgibt
    Node* p_current;
    p_current= list1->head;

    printf("Liste:\n ");

    while(p_current!=NULL){
        printf(" %d\n", p_current->value);
        p_current= p_current->next;
    }
    printf("\n");
    return;
}

/**
 * @brief Element am anfang der List löschen
 * 
 * @param p_help Zum Zwischenspeichern der Liste, damit diese nicht verloren gehr
 * @param p_delete Zu löschendes Element
 */
void delete_first(List* list1) {
    if(list1->head==NULL) {
        printf("Füge zunächst ein Element ein, um diesen zu löschen");
        return;
    }
    Node* p_help;
    p_help=list1->head;
    list1->head= p_help->next;
    free(p_help);
    return;
}

void delete_last(List* list1) {
    if (list1->head==NULL) {
        printf("Füge zunächst ein Element ein, um diesen zu löschen");
        return;
    }

    //Wenn Liste nur ein Element hat
    if(list1->head->next==NULL) {
        free(list1->head);
        list1->head=NULL;
    }

    Node* p_current;
    p_current=list1->head;
    while(p_current->next->next!= NULL) {
        p_current= p_current->next;
    }
    free(p_current->next);
    p_current->next=NULL;
    return;
}

int summe_liste(List *list1) {
    Node* p_current;
    int summe=0;
    p_current=list1->head;

    while(p_current!=NULL) {
        summe= summe+ p_current->value;
        p_current= p_current->next;
    }
    //printf("Summe: %d\n", summe);
    return summe;
}

int count_nodes(List* list1) {
    Node* p_current;
    int count=0;
    p_current = list1->head;

    while(p_current!=NULL) {
        count++;
        p_current= p_current->next;
    }
    //printf("Anzahl Elemente %d", &count);
    return count;
}

void delete_list(List* list1) {

    while(list1->head != NULL) {
        delete_first(list1);
    }
    list1->head=NULL;
}

int contains(List* list1, int value) {
    Node* p_current;
    p_current= list1->head;

    while(p_current!= NULL){
        if(p_current->value == value) {
            return 1;
        }
    p_current=p_current->next;
    }
    return 0;
} 
