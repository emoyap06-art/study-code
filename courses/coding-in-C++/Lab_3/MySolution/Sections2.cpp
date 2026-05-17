#include <iostream>
#include <string>
#include <vector>

class User {
    protected:
    std::string name;
    int id;

    public:
    User(const std::string& name, const int id)
            :  name(name), id(id) {}
    
    void printInfo() {
        std::cout <<"User:" <<name <<std::endl;
        std::cout <<"ID:" <<id <<std::endl;
    }
};

class Student : public User{
    private:
    std::string cours;

    public:
    Student(std::string name, int id, const std::string& cours) : User(name, id), cours(cours) {}

    void printRole() {
        std::cout <<"Role: " <<"Student" <<std::endl;
        std::cout <<"Name: " <<this->name <<std::endl;
        std::cout <<"ID: " <<this->id <<std::endl;
        std::cout <<"Cours" <<this->cours <<std::endl;
    }

};

class Instructor : public User{
    private:
    std::string subject;

    public:
    Instructor(std::string name, int id, std::string subject) : User(name, id), subject(subject) {}

    void printRole() {
        std::cout <<"Role: " <<"Instructor" <<std::endl;
        std::cout <<"Name: " <<this->name <<std::endl;
        std::cout <<"ID: " <<this->id <<std::endl;
        std::cout <<"Cours:" <<this->subject <<std::endl;
    }
    
};

int main () {
    Student student_1("Emirhan Yapar", 3037373, "TFE25-2");
    Instructor instructor_1 ("Braunagel", 1234, "Programming");

    student_1.printInfo();
    student_1.printRole();

    instructor_1.printInfo();
    instructor_1.printRole();

    return 0;
}