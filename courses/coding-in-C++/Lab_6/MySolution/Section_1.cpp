#include <iostream>
#include <string>
#include <stdexcept>


class myException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Configuration file is invalid";
    }
};

class Configloader {
    public:

    void load(const std::string& filename){
        if(filename.empty()) {
            throw std::invalid_argument("Filename cannot be empty");
        }
        if(filename.size() < 4 ||filename.substr(filename.size()-4)!= ".cfg") {
            throw std::invalid_argument("Ending is not allowed");
        }
        if(filename == "missing.cfg") {
            throw std::runtime_error("File could not be opened");
        }
        if(filename == "invalid.cfg") {
            throw myException();
        }
        std::cout << filename << "loades successfully" <<std::endl;
    }
};


int main () {

    Configloader loader;

    std::string testFiles[] = {
        "", 
        "test.txt",
        "test.pdf",
        "missing.cfg",
        "invalid.cfg",
        "a"
    };

    for(const std::string& file: testFiles) {
        try {
            loader.load(file);
        }
        catch(const myException& e) {
            std::cout <<"custom Exception: " <<e.what() <<std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "standard Exception" <<std::endl;
        }
        std::cout <<"--------------------" <<std::endl;

    }

    return 0;
}