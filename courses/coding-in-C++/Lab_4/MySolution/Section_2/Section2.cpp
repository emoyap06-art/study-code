#define M_PI 3.41
#include <iostream>
#include <string>


class shape {
    public:
    virtual double area() const =0;
    virtual ~shape()= default;
    };

class Circle : public shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}

    double area() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public shape {
private:
    double width;
    double hight;
public:
    Rectangle(double width, double hight) : width(width), hight(hight) {}

    double area() const override{
        return width * hight;
    }     
};


int main () {

    Circle c1(1.5);
    Rectangle r1(2, 3);

    Circle c2(3.1);
    Rectangle r2(2.1, 6.7);

    std::cout <<"Fläche Kreis: " <<c1.area() <<std::endl;
    std::cout <<"Fläche Recteck: " <<r1.area() <<std::endl;

    //--------------------PART III------------------------------

    shape* s_array[4] = { &c1, &c2, &r1, &r2};

    for(int i=0; i<4; i++) {
        std::cout <<"Square: " <<s_array[i]->area() <<"\n" <<std::endl;
    }
    return 0;
}