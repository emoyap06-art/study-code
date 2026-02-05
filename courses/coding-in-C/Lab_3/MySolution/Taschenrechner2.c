#include <stdio.h>

int main () {
    float nummer1;
    float nummer2;
    char operator;
    float ergebnis;

    printf("Zahl 1:\n");
    scanf("%f", &nummer1);
    printf("Zahl2:\n");
    scanf("%f", &nummer2);
    printf("Operator wählen(+, -, *, /): \n");
    scanf(" %c", &operator);

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