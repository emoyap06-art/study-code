#include <stdio.h>

void TrennLinie (void) {

    for(int i=1; i<=8; i++) {
        printf(" +--+");
    }
}

int main() {
    
    for(char i='A'; i<='H'; i++) {
        printf("  %c ", i);
        TrennLinie();
        //for(int j=0; )

    
    }
}