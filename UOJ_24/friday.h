#pragma once

#include "day.h"

#include <iostream>
#include <string>

class Friday: public Day {
public:
    Friday(int m, int d, std::string _day): Day(m, d, _day) {};

    virtual void print() {
        std::cout << mon << '/' << date << ' ' << day << ' ';
        if (plan.empty()) std::cout << "Today is Free" << std::endl;
        else std::cout << "Today's Plan:" << std::endl;
        if (!plan.empty()) {
            for (std::string x: plan) {
                std::cout << x << std::endl;
            }
        }
        if (plan.empty()) std::cout << "Friday is Free :)" << std::endl;
        else std::cout << "Friday is Busy :(" << std::endl;
    }
};