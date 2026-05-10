#include <iostream>
#include <string>

template <typename T, typename Q>
void output(T value1, Q value2, std::string string1, std::string string2) {
    std::cout<<string1;
    std::cout<<":";
    std::cout<<value1;
    std::cout<<"|";
    std::cout<<string2;
    std::cout<<":";
    std::cout<<value2 << std::endl;
}

int main () {
    output("too hot", "too fast", "Temperature", "speed");

    return 0;
}