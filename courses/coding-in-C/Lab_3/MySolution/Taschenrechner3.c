#include <stdio.h>

float number1;
float number2;
char operator;
float ergebnis;

void Plus (void) {
ergebnis= number1 + number2;
}

void Minus (void) {
    ergebnis= number1 - number2;
}

void Mal (void) {
    ergebnis= number1 * number2;
}
void Geteilt (void) {
    if(number2 ==0) {
        printf("Mathematischer Fehler! \n");
        return 1;
    }

    ergebnis = number1 / number2;
}



int main () {
    printf("Zahl 1: \n");
    scanf(" %f", &number1);

    printf("Zahl 2: \n");
    scanf (" %f", &number2);

    printf("Wähle den Operator ( +, -, *, /): \n");
    scanf(" %c", &operator);

    switch (operator) {
        case '+':
        Plus();
        break;

        case '-':
        Minus();
        break;

        case '*':
        Mal();
        break;

        case '/':
        Geteilt();
        break;

        default:
        printf("Falsche Eingabe\n");
        return 1;
    }
    printf("Das Ergebnis= %f\n\n", ergebnis);

    return 0;
}