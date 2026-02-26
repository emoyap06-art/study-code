#include <stdio.h>


typedef struct car {
    float fuel_level;
    float max_fuel_level;
    char model [10];

} car;


void refuel(car* ptr, float amount) {

    if(ptr->fuel_level + amount <= ptr->max_fuel_level) 
        {
        ptr-> fuel_level += amount;
        }    else{
            ptr->fuel_level = ptr->max_fuel_level;
                }
}

int main() {

car myCar;
car* ptr= &myCar;

ptr->fuel_level = 20;
ptr->max_fuel_level = 90;

printf("Fuel before: %f" ,ptr->fuel_level);

refuel(ptr, 50);
printf("\nFuel afterwards: %f" ,ptr-> fuel_level);

    return 0;
}