#include <iostream>


template <typename T>
void Print(const T arr[], int size) {
    std::cout << "["; 

    for(int i=0; i<size; i++) {
        std::cout<<arr[i];

        if(i< size-1) {
            std::cout<<",";
        }
    }
    std::cout<<"]" <<std::endl;
}

int main() {
    /*int
    int i_arr[]= {7, 14, 21, 28};
    int size=4;

    Print(i_arr, size);
    */
    /*double
    double d_arr[]= {7.1, 14.2, 21.3, 28.4, 35.5};
    int size=5;

    Print(d_arr, size);

    */

    // Character array
    char charArr[] = {'A', 'B', 'C', 'D'};
    int size=4;
    Print(charArr, size);


    return 0;
}


