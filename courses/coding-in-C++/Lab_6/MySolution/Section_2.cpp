#include <iostream>
#include <string>
#include <exception>

class Sensor {
private:
    std::string name;
    double current_value;
    double min_value;
    double max_value;
public:
    Sensor(const std::string& name, double current_value, double min_value, double max_value) {
        this->name=name;
        this->current_value;
        this->min_value;
        this->max_value;

        if(min_value > max_value) {
            throw std::logic_error("Min cannot be greater than MAX");
        }
        if(current_value < min_value || current_value >max_value) {
            throw std::out_of_range("Value out of range");
        }
    }
    void update_value(double value) {
        if(min_value<0 || max_value>100) {
            throw std::out_of_range("Values are out of range");
        }
    }
    double get_value() const{
        return current_value;
    }
    void print_info() const {
        std::cout<<"Sensor: " <<name <<std::endl;
        std::cout<<"Current Value: " <<current_value <<std::endl;
        std::cout<<" Allowed range: " <<min_value <<" - " <<max_value <<std::endl;
    }
};

int main () {
    try {
        Sensor Reifen("Luftdrucksensor", 2.6, 2.4, 3.2);
        Reifen.update_value(3.0);
    }
    catch (const std::exception& e) {
        std::cout <<e.what() <<std::endl;
    }
}