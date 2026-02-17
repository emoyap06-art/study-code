#include <stdio.h>

int main () {

for(char j='A'; j<='H';j++) {

    for (int i=8; i>=1; i--){

        printf(" %c", j);
        printf("%d", i);
    }
printf("\n");
}


    return 0;
}