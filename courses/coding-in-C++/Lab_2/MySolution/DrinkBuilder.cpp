#include <iostream>
#include <string>

class DrinkBuilder {
    std::string name;
    int sugar;
    int temperature;
    bool withmilk;

    public:

    static constexpr int DEFAULT_TEMPERATURE=10;
    static constexpr int MAX_SUGAR=5;

    
    DrinkBuilder() {
        this->name= "undefined";
        this->sugar= 0;
        this->temperature= DEFAULT_TEMPERATURE;
        this->withmilk= false;
    }

    DrinkBuilder& setName(const std::string& name) {
        this->name=name;
        return *this;
    }

    DrinkBuilder& setSugar(int sugar) {
        if(sugar>=0 && sugar<MAX_SUGAR)   {
            this->sugar = sugar; 
        }
        return *this;
    }

    DrinkBuilder& setTemperature(int temperature) {
        if(temperature>0) {
        this->temperature=temperature;
        }
        return *this;
    }

    DrinkBuilder& setMilk(bool withmilk) {
        this->withmilk= withmilk;
        return *this;
    }

    void print() {
        std::cout <<"Drink:" <<name <<std::endl;
        std::cout <<"Sugar:" <<sugar <<std::endl;
        std::cout <<"Temperature:" <<temperature <<std::endl;
        std::cout <<"With Milk(1):" <<withmilk <<std::endl;
    }

    bool isValid() const {
        return sugar >= 0 && sugar<MAX_SUGAR
        && temperature>0
        && name !=" ";
        
    }

};

    int main () {
        DrinkBuilder drink_1;

        drink_1.setName("Tea").setSugar(0).setTemperature(40).setMilk(false).print();
        return 0;

    }

