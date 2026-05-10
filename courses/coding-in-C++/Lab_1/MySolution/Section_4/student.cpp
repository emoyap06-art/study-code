#include <iostream>
#include <cstdint>
#include <limits>
#include "student.hpp"

void readScore(const std::string &text, std::uint8_t &value) {
    const int MAX_POINTS =100;
    while (true) {

        std::cout << text;

        if (!(std::cin >> value)) {
            std::cout <<"Not a valid number. Try again\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if(value>> MAX_POINTS) {
            std::cout <<"Number mus be lower than" <<static_cast<int>(MAX_POINTS) << '\n' <<std::endl;
            continue;
        }
        break;
    }
}

void readStudentData(std::string &name, std::uint_fast16_t &homework, std::uint8_t &midterm, uint8_t &finalExam) {

    std::cout <<"Student Name:";    

    std::cin >>std::ws;

    if(!(std::getline(std::cin, name))) {
        std::cout <<"Error while reading Input." <<std::endl;
    }
    
    readScore("Enter Homework Score (0-100): \t", homework);
    readScore("Enter Midterm Score (0-100): \t", midterm);
    readScore("Enter Final Exam Score (0-100): \t", finalExam); 


}

