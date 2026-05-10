#include <iostream>
#include "Header.hpp"

using namespace std;
void printFromHeader() {
    cout <<"Hello from .hpp";
}

int main() {
    cout <<"Hello World!" <<endl;
    printFromHeader();

    return 0;
}