#pragma once
#include "vehicle.h"
class Motor: public Vehicle{
public:
    Motor(int,std::string);
    using Vehicle::describe;
    void sell();
};