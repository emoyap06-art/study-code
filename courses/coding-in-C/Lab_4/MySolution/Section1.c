#include <stdio.h>
#include <string.h>

void change_second_letter(char p[]) {
    *(p + 1) = 'c';
    printf("%s\n", p);
}

int main() {

    char satz[] = "Curly bird catches the worm";
    char* ptr_satz = satz;
//------------------------------
    char Input[20];
    char* ptr_Input = Input;

    printf (" %c \n", satz[0]);
    printf(" %c", *ptr_satz);

*ptr_satz = satz[0];    
*ptr_satz = 'E';
*ptr_satz++;
*ptr_satz = 'a';
printf("\n %s \n", satz);
//--------------------------------

printf("Enter a word: ");
fgets(Input, sizeof(Input), stdin);
Input[strcspn(Input, "\n")] = '\0'; 

change_second_letter(Input);

//change_second_letter("AAtions speak louder than words");
char satz2[] ="AAtions speak louder than words";
change_second_letter(satz2); // korrekt: char [] ist intern char *; String literal wird nicht verändert, da es im statischen Speicher liegt und readonly ist
printf(" %s \n", "AAtions speak louder than words"); // String literal wird nicht verändert, da es im statischen Speicher liegt und readonly ist
    
return 0;
}