#include <iostream>
#include <vector>
#include <cmath>

class Vector2D {
    private:
        double x;
        double y;
    
    public:
    Vector2D() : x(0.0), y(0.0) {}

    Vector2D(const double x, const double y) : x(x), y(y) {}

    double get_X() const{
        return x;
    }

    double get_Y() const{
        return y;
    }

    void print() const
    {
        std::cout << '\n'
                  << "(" << this->x << ", " << this->y << ")" << std::endl;
    }

    double length() const {
        return sqrt((x*x) + (y*y));
    }

    double length_rounded(int precision) const {
        double factor = std::pow(10.0, precision); //gerundeter Wert
        double length = this->length();
        return std::round(length* factor)  / factor;

    }
    //Part III

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y+ other.y);
    }

    Vector2D& operator+=(const Vector2D& other)  {
        x= x+other.x;
        y= y+other.y;
        return *this;
    }


    //Skalar Multiplikation
    Vector2D operator*(const Vector2D& other) {
        x= x*other.x;
        y= y*other.y;
        return *this;
    }
};

// std::cout << ...
std::ostream& operator << (std::ostream& os,const Vector2D& other) {
        return os<< "(" << other.get_X() << ", " << other.get_Y() << ")\n";
    }



int main () {
    Vector2D a(5,6), b(7,8);
    a.print();
    b.print();

    Vector2D c = a + b;
    c.print();

    //a+=b;
    //a.print();

    Vector2D d= a*b;
    d.print();

    Vector2D e= a*b;
    e.print();

    std::cout << e;
    return 0;
}