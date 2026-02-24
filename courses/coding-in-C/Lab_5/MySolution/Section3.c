#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    srand(time(NULL));

int array [10] = {0};
array[2] =1;
array[4]= 1;
array[6]= 1;

int *p = array;

//temporäres array
int next[10];
int *p2= next;

int count[10];
int *pc = count;

printf("Time 0: ");
for(int i=0; i<10; i++) {

printf("%d", *(p + i));
}
printf("\n");

// ---- next auf 0 setzen ----
    for (int i = 0; i < 10; i++) {
        *(p2 + i) = 0;
    *(pc +i) =0;
    }

for(int i =0; i<10; i++) {

if(*(p + i)==1) {
    
    int dir = rand() %2;
    int new_index;

    if(dir == 0) {
        new_index= i-1;
    }else {
        new_index= i+1;
    }

    if(new_index<0){
        new_index = 0;
    }
    if(new_index >=10) {
        new_index = 9;
    }
*(p2 + new_index) =1;

*(pc + new_index) += 1;
}
}

//------ Kollisionsbehandlung ----
for(int j=0; j<10; j++) {
if(*(pc +j)==1) {*(p2 + j)=1;
} else {
    *(p2 + j) =0;
    printf("Collision at index %d\n", j);
}
 }

printf("Time 1: ");
for(int i=0; i<10; i++) {
printf("%d", next[i]);
}

    return 0;
}
