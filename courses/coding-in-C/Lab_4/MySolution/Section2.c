#include <stdio.h>
#include <string.h>

char array[100];

int main() {

    printf("Enter a word: \n");
    if (fgets(array, sizeof(array), stdin) != NULL) {

    array[strcspn(array, "\n")] = '\0'; // Entfernt das Newline-Zeichen, das von fgets hinzugefügt wird

char* ptr_array1 = &array[0];
char* ptr_array2 = &array[strlen(array)-1]; //-1, da Array beo 0 beginnt und strlen die Anzahl der Zeichen zurückgibt, nicht den Index des letzten Zeichens

int is_palindrome =1;

while(ptr_array1 < ptr_array2) {

        if(*ptr_array1 != *ptr_array2) {
            is_palindrome = 0;
            break;
        } 

        ptr_array1++;
        ptr_array2--;
}

if(is_palindrome) {
printf("Your provided word ' %s' is a palindrome.\n", array);
} else {
printf("Your provided word ' %s' is not a palindrome.\n", array);
}

    return 0;
}
}