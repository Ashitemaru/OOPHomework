#pragma once
#include "engine.h"
#include "wheel.h"
#include <string>
class Vehicle{
protected:
    std::string type;
    Engine _engine;
    Wheel _wheel;
public:
    void describe();
    Vehicle(int num,std::string nam,std::string typ="vehicle");
};