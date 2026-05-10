#include <iostream>
#include <cstdint>
#include <limits>


namespace validation {

    const std::uint8_t ADULT_AGE_LIMIT=18;
    const std::uint8_t SENIOR_AGE_LIMIT=65;

    bool isAdult(std::uint8_t age){
        return age >= ADULT_AGE_LIMIT;
    }

    bool isSenior(std::uint8_t age) {
        return age >= SENIOR_AGE_LIMIT;
    }
}

int main () {
    const int MAX_AGE= 150;
    int age = 0;

    std::cout <<"Please Enter your Age:\n";

    while(true) {
        if(!(std::cin >> age)) {
            std::cout <<"Please enter a valid number." <<'\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(age < 0) {
            std::cout <<"You entered a negative Age. Please try again!" <<'\n';
        }
        else if (age> MAX_AGE) {
            std::cout <<"Please enter a Age under the limit of" <<static_cast<int>(MAX_AGE) << '\n';
        }
        else {
            break;
        }
        std::cout <<"Please enter your age:";
    }

    std::cout <<"Your entered age is:\t" <<static_cast<int>(age) <<'\n' <<std::endl;

    const std::uint8_t validated_age = static_cast<std::uint8_t>(age);

    if (validation::isSenior(validated_age))
    {

        std::cout << "That means that you are a senior citizen.\n" << std::endl;
    }
    else if (validation::isAdult(validated_age))
    {
        std::cout << "That means that you are an adult." << std::endl;
    }
    else
    {
        std::cout << "That means that you are still a kid or teenager.\n" << std::endl;
    }

    return 0;
}
