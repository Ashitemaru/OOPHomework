#pragma once

#include "what.h"
#include <string>
#include <iostream>

class Alien: public WhatCanMotion, public WhatCanSpeak {
    std::string name;
public:
    Alien(std::string _name): name(_name) {};

    virtual void speak() override {
        std::cout << name + " is speaking" << std::endl;
    }

    virtual void motion() override {
        std::cout << name + " is moving" << std::endl;
    }

    virtual void stop() override {
        std::cout << name + " stops" << std::endl;
    }

    virtual ~Alien() {};
};