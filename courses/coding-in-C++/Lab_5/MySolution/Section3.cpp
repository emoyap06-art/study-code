#include <iostream>

template <typename T>
T weakest(const T arr[], int size) {
T min = arr[0];

for(int i=1; i<size; i++) {
    if(arr[i]<min) {
        min=arr[i];
        }
    }
    return min;
}

int main() {
    //int
    int i_arr[]= {12, 4, 5, 7};
    int size=4;

    int result = weakest(i_arr, size);

    std::cout << "Schwaechster Wert: " << result << std::endl;


    return 0;
}
