#include <stdio.h>

int main() {


/*
FILE *Text = fopen("Text.txt", "r"); 
if(Text == NULL) {
    return 1;
}

int Ausgabe;

while((Ausgabe= fgetc(Text)) != EOF) {
    printf("%c", Ausgabe);
}
*/



/*
FILE *Text = fopen("Text.txt", "r");
if(Text == NULL) {
    return 1;
}

char Zeile_speichern[100];

while((fgets(Zeile_speichern, sizeof(Zeile_speichern), Text)) != NULL) {
    printf("%s", Zeile_speichern);
}
*/


/*
FILE *Text = fopen("Text.txt", "r");
if(Text == NULL) return 1;

char text [20];

fscanf(Text, "%s", &text);
printf("Text: %s", text);
*/

/*
FILE *Text = fopen("Text.txt", "r");
if(Text == NULL) return 1;

char text [100]; 
int Zahlen_a, Zahlen_b;

fscanf(Text, " %d %d %s", &Zahlen_a, &Zahlen_b, &text);
printf("Zahl: %d %d %s", Zahlen_a, Zahlen_b, &text);
*/


/*
FILE *pt = fopen("Input.txt", "w");
if(pt == NULL) return 1;

fputc('A', pt);
fputs("BCDEFGH", pt);

*/

FILE *pt = fopen("courses/Input.txt", "w");
if(pt == NULL) return 1;

char text[]= "Ordner verschoben";
int x= 10;
fprintf(pt, "Text: %s\n", text);
fprintf(pt, "Die Zahl ist: %d\n", x);



fclose(pt);

return 0;
}