#include <stdio.h>
#include <string.h>

int main (int argc, char **argv) {
    
if( argc < 2) {
    printf("No arguments provided.\n");
    return 1;
}

for(int i=0; i<argc; i++) {
///for(char *ptr= argv; ptr< argc; ptr++){ ----->??

printf(" Arguments %d  at adress %p  has content %s  (length: %zu)\n", i, argv[i], argv[i], strlen(argv[i]));


}
return 0;
}