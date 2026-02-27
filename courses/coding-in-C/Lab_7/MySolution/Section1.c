#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int N;
    printf(" Gib einen Wert für N ein:");
    if(scanf("%d", &N)!=1) {
        printf("Fehler beim Einlesen");
        return 1;
    } 
    /*
    int *ptr=malloc(sizeof *ptr);
    int *ptr= calloc(N, sizeof *ptr);
    if(ptr==NULL) {
        printf("Speicherallokaltion fehlgeschlagen");
    }
    *ptr=N;
    printf("Gespeichert: %d", *ptr);
    free(ptr);
    */
    
    int* ptr= &N;
    int* arr= calloc(N, sizeof *arr);

    if(arr == NULL) {
        printf("Speicherallokation fehlgeschlagen");
        return 1;
    }
    printf("Gespeichert: %d", arr[0]);

    for(int i=0; i< *ptr; i++) {
        arr[i]= i * i;
    printf("%d\n", arr[i]);
    }

    int newN= 2* N;
    int* tmp= realloc(arr, newN * sizeof *arr);
    if(tmp == NULL) {
        printf("Allokation fehlgeschlagen");
        free(arr);
        return 1;
    }

    arr = tmp;

    for(int i=N; i< newN; i++) {

        arr[i] = i * i;
    }

    for(int i=0; i< newN; i++) {
        printf(" %d", arr[i]);
    }


    free(arr);
    return 0;
}