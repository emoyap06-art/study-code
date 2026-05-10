#include <iostream>
#include <string>

template <typename T>
void swapValue(T& a, T& b) {
    std::cout <<"before Swap = " << a <<"\nbefore Swap =" << b << '\n' << std::endl;
    T temp =a;
    a = b;
    b= temp;
    std::cout <<"after Swap " << a <<"\nafter Swap=" << b << '\n' << std::endl;

}

int main () {

    //Int
    int a=10;
    int b=20;

    swapValue(a, b);

    //Double
    double c = 10.1;
    double d = 20.2;

    swapValue(c, d);    

    //String
    std::string s1= "hallo";
    std::string s2= "Welt";

    swapValue(s1, s2);


    return 0;
}
