#include "motor.h"
#include "vehicle.h"
#include <iostream>
#include <string>

Motor::Motor(int num,std::string nam):Vehicle(num,nam,"motor"){};

void Motor::sell(){
    std::cout<<"A motor is sold!"<<std::endl;
    return;
}