#include <stdio.h>
#define Groesse 8

void DruckBuchstabenreihe(void) {
    char buchstabe;
    printf("   ");
    for(buchstabe= 'A'; buchstabe<='H'; buchstabe++) {
        printf(" %c  ", buchstabe); 
   }
    printf("\n");
}
   
void DruckTrennlinie(void) {
    printf("  +");
    for (int i=1; i<=Groesse; i++) {
        printf("---+");
    }
    printf("\n");
}

void DruckZeile(int zahl, int zeilenindex) {
    int spaltenindex;
    printf(" %d |", zahl);

    for (spaltenindex=0; spaltenindex<Groesse; spaltenindex++) {
        if((spaltenindex  +zeilenindex) %2 == 0) {
            printf("###|");
        } else
        {
            printf("   |");
    }
}
printf("   %d\n", zahl);
}



int main(void) {

int zahl;
int zeilenindex=0;

DruckBuchstabenreihe();

for(zahl=8; zahl>=1; zahl--) {
    DruckTrennlinie();
    DruckZeile(zahl, zeilenindex);
    zeilenindex++;
}
DruckTrennlinie();
DruckBuchstabenreihe();

    return 0;
}