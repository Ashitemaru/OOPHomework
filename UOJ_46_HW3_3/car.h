#pragma once
#include "vehicle.h"
class Car: public Vehicle{
public:
    Car(int,std::string);
    using Vehicle::describe;
};