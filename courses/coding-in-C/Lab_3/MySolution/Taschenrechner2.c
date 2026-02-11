#include <stdio.h>

int main () {
    float nummer1;
    float nummer2;
    char operator;
    float ergebnis;

    printf("Zahl 1:\n");
    if (scanf(" %f", &nummer1) != 1) {
        printf("Ungültige Eingabe. Bitte geben Sie eine Zahl ein.\n");
        return 1; // Beendet das Programm mit einem Fehlercode
    }

    printf("Zahl2:\n");
    if (scanf(" %f", &nummer2) != 1) {
        printf("Ungültige Eingabe. Bitte geben Sie eine Zahl ein.\n");
        return 1; // Beendet das Programm mit einem Fehlercode
    }
    
    printf("Operator wählen(+, -, *, /): \n");
    if (scanf(" %c", &operator) != 1) {
        printf("Ungültige Eingabe. Bitte geben Sie einen Operator ein.\n");
        return 1; // Beendet das Programm mit einem Fehlercode
    }

    switch (operator) {
        case '+':
        ergebnis = nummer1 + nummer2;
        break;

        case '-':
        ergebnis= nummer1 - nummer2;
        break;

        case '*':
        ergebnis= nummer1 * nummer2;
        break;

        case '/':
        if (nummer2 ==0) {
        printf("Mathematischer Fehler!\n");
        return 1; // Beendet das Programm mit einem Fehlercode
        }
        ergebnis= nummer1 / nummer2;
        break;
        
        default:
        printf("Ungültiger Operator!\n");
        return 1; // Beendet das Programm mit einem Fehlercode
        break;
    }    

    printf("Das Ergebnis= %f\n", ergebnis);

    return 0;
}