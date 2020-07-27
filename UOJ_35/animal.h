#pragma once
#include <string>

class Animal{
protected:
    std::string name;
public:
    Animal(std::string n):name(n){};
    virtual void speak()=0;
    virtual void swim()=0;
    void action(){
        speak();
        swim();
        return;
    }
    virtual ~Animal(){};
};