#include <iostream>
#include <vector>
#include <algorithm>

int main() {

std::vector<int> data = {42, 17, 42, 5, 99, 17, 6, 12};

//Print data
std::cout << "Original Data:";

for (int value: data) {
    std::cout << value <<" ";
}
std::cout << std::endl;


//Sort Data
std::sort(data.begin(), data.end()); //begin= erstes Elment; end= Positition nach dme letztene Element



//Print Sorted Data
std::cout << "Sorted Data:";

for(int value : data) {
    std::cout << value <<" ";
}
std::cout << std::endl;


//Search for 63
auto result = std::find(data.begin(), data.end(), 63);

//Check if value exists
if(result != data.end()) {
    std::cout<<"63 Existiert!" << std::endl;
}
else {
    std::cout<<"63 existiert nicht!" << std::endl;
}

return 0;

}