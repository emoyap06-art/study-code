#include <stdio.h>

int main() {

float nummer1;
float nummer2;
char operator;
float ergebnis;

    printf("Geben Sie die erste Zahl ein: ");
    scanf("%f", &nummer1);
    printf(" Zahl 1 ist: %f\n", nummer1);
    //if (scanf("%f", &nummer1) != 1) {
    //    printf("Ungültige Eingabe. Bitte geben Sie eine Zahl ein.\n");
    //    return 1; // Beendet das Programm mit einem Fehlercode
    //}

    printf("Geben Sie die zweite Zahl ein: ");
    scanf("%f", &nummer2);
    printf(" Zahl 2 ist: %f\n", nummer2);
    //if (scanf("%f") != 1) {
    //    printf("Ungültige Eingabe. Bitte geben Sie eine Zahl ein.\n");
    //    return 1; // Beendet das Programm mit einem Fehlercode
    //}
    printf("Wählen Sie nun einen dieser Oparatoren aus: +, -, *, / \n");    
    scanf(" %c", &operator);

    if(operator == '+') {
        ergebnis= nummer1 + nummer2;
    
    } else if(operator== '-') {
        ergebnis = nummer1 - nummer2;
    } else if (operator == '*') {
        ergebnis = nummer1 * nummer2;
    } else if (operator == '/') {
        ergebnis= nummer1 / nummer2;
        if (nummer2 == 0) {
            printf("Mathematischer Fehler!\n");
            return 1; // Beendet das Programm mit einem Fehlercode
        }
    }

    printf("Das Ergebnis ist= %f\n", ergebnis);

    return 0;
}