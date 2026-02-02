#include <stdio.h>

int main(void) {

int zahl;
char buchstabe;

for(zahl=8; zahl>0; zahl--) {
    for(buchstabe='A'; buchstabe<='H'; buchstabe++) {
        printf("%c%d \t ", buchstabe, zahl);
}
printf("\n");

}

    return 0;
}


