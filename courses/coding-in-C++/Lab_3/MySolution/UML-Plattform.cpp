#include <iostream>
#include <string>
#include <vector>

class Content{
    private:
    std::string title;
    std::string type;

    public:
    Content(const std::string& title, const std::string& type)
            :title(title), type(type) {}
    
    void display() const {
        std::cout<<"Content: " <<title <<std::endl;
        std::cout<<"(" <<type << ")" <<std::endl;
    }

};



class Lesson{

private:
    std::string title;
    std::vector<Content> contents;

public:
    Lesson(const std::string& title) 
            : title(title) {}
            
    void addContent(const Content& content) {
        contents.push_back(content);
    }

    void showLesson() const {
        std::cout <<"Lesson: "<<title <<std::endl;
        for(const Content& content: contents) {
            content.display();
        }
    }

};


class courses{
    std::string title;
    std::string description;
    std::vector<Lesson> lessons;

    public:
    courses(const std::string& title, const std::string& description)
            :title(title), description(description) {}

    void addLesson(const Lesson& lesson_1) {
        lessons.push_back(lesson_1);
    }

    void showCourse() const {
        std::cout<< "Course: " <<std::endl;
        for(const Lesson& lesson_1: lessons) {
            lesson_1.showLesson();
        }
    }
};


class User{
private:
    int id;
    std::string name;
    std::string email;
    std::vector<courses*> enrolledcourses;

public:
    User(int id, const std::string name, const std::string email)
            :id(id), name(name), email(email) {}

    void enroll(courses* cours_1) {
        enrolledcourses.push_back(cours_1);
        std::cout <<name <<"enrolled in a course" <<std::endl;
    }
    void showUser() {
        std::cout <<"Name: " <<name << std::endl;
        std::cout <<"ID: " <<id << std::endl;
        std::cout <<"E-Mail: " <<email <<std::endl;
    }
};

class platform {

    private:
    std::string name;
    std::vector <User> UserName;
    std::vector<courses> Kurse;

    public:
    platform(const std::string& name)
            :name(name) {}

    void addCours(const courses cours_1) {
        Kurse.push_back(cours_1);
        std::cout <<" Cours added to other courses" <<std::endl;
    }

    void addUser(const User User_1) {
        UserName.push_back(User_1);
        std::cout <<"New User added" <<std::endl;
    }

    void showPlatform() const {
        std::cout << "Platform: " << name << std::endl;
        std::cout << "Number of courses: " << Kurse.size() << std::endl;
        std::cout << "Number of users: " << UserName.size() << std::endl;
    }

    
};

int main () {
    platform moodle("Moodle DHBW");

    courses cppCourse("C++ Basics", "Introduction to object-oriented programming");

    Lesson lesson3("UML and Classes");

    Content text1("UML Basics", "Text");
    Content video1("Class Diagram Tutorial", "Video");

    lesson3.addContent(text1);
    lesson3.addContent(video1);

    cppCourse.addLesson(lesson3);

    User user1(1, "Emirhan", "emirhan@example.com");

    moodle.addCours(cppCourse);
    moodle.addUser(user1);

    user1.enroll(&cppCourse);

    moodle.showPlatform();
    user1.showUser();
    cppCourse.showCourse();

    return 0;
}