#include <iostream>

template <typename T, int N>
T weakest(const T (&arr)[N]) {
T min = arr[0];

for(int i=1; i< N; i++) {
    if(arr[i]<min) {
        min=arr[i];
        }
    }
    return min;
}

int main() {
    //int
    int i_arr[4]= {12, 4, 5, 7};

    int result = weakest(i_arr);

    std::cout << "Schwaechster Wert: " << result << std::endl;


    return 0;
}


/* Der Sizeparameter wird nicht mehr benötigt, da die Größe direkt über das Array übergeben wird. Das heißt das Array füllt die Variable 'N'
mit einem Wert nach der Eingabe.
Der Vorteil ist man hat keine extra parameter*/