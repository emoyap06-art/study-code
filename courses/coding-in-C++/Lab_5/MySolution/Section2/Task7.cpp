#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> data= {7, -1, 13, 21, 8, -1, 8};

    std::cout<<"Original data: ";

    for(int var : data)
    {
        std::cout<<var; std::cout<<", ";
    }
    std::cout << std::endl;

    //Replace '-1' with '0'
    std::replace(data.begin(), data.end(), -1, 0);

    std::cout<<"Corrected data: ";

    for(auto var : data)
    {
        std::cout<<var <<", ";
    }
    std::cout<< std::endl;

    //count occurences of value 8
    auto amount= std::count(data.begin(), data.end(), 8);

    std::cout<<"Occurences of the value 8: ";
    std::cout<<amount;

    std::cout<< std::endl;


    //reverese the dataset
    std::reverse(data.begin(), data.end());

    std::cout<<"reversed data: ";

    for(int var : data)
    {
        std::cout<<var <<", ";
    }
    std::cout <<std::endl;



    //*******************Task8******************    */
    for(std::vector<int>::iterator it = data.begin();
        it!=data.end();
        ++it) {
            std::cout<<*it <<", ";

            std::cout << std::endl;

    }
    return 0;
}
