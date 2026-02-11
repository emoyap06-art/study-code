#include <stdio.h>

int main() {

float nummer1;
float nummer2;
char operator;
float ergebnis;

    printf("Geben Sie die erste Zahl ein: ");

      if (scanf(" %f", &nummer1) != 1) {
       printf("Ungültige Eingabe. Bitte geben Sie eine Zahl ein.\n");
        return 1; // Beendet das Programm mit einem Fehlercode
      }
    printf(" Zahl 1 ist: %f\n", nummer1);  



    printf("Geben Sie die zweite Zahl ein: \n");

     if (scanf(" %f", &nummer2) != 1) {
        printf("Ungültige Eingabe. Bitte geben Sie eine Zahl ein.\n");
        return 1; // Beendet das Programm mit einem Fehlercode
     }
    printf(" Zahl 2 ist: %f\n", nummer2);



    printf("Wählen Sie nun einen dieser Oparatoren aus: +, -, *, / \n");    
    scanf(" %c", &operator);



    if(operator == '+') {
        ergebnis= nummer1 + nummer2;
    
    } else if(operator== '-') {
        ergebnis = nummer1 - nummer2;

    } else if (operator == '*') {
        ergebnis = nummer1 * nummer2;
        
    } else if (operator == '/') {
        if (nummer2 == 0) {
            printf("Mathematischer Fehler!\n");
            return 1; // Beendet das Programm mit einem Fehlercode
        } else {
        ergebnis= nummer1 / nummer2;
        
        }
    }

    printf("Das Ergebnis ist= %.2f \n", ergebnis);

    return 0;
}