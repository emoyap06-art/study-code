#include <stdio.h>
#include <string.h>
#include <ctype.h>  //Lib for tolower() function

char array[100];
char* ptr_array1 = array;
char* ptr_array2 = array;

int main() {
    printf("Enter a word: \n");
    fgets(array, sizeof(array), stdin);
    array[strcspn(array, "\n")] = '\0'; // Entfernt das Newline-Zeichen, das von fgets hinzugefügt wird

ptr_array1 = &array[0];
ptr_array2 = &array[strlen(array)-1];

int is_palindrome =1;

while(ptr_array1 < ptr_array2) {

        if(tolower(*ptr_array1) != tolower(*ptr_array2)) {
            is_palindrome = 0;
            break;
        } else {
            is_palindrome = 1;
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