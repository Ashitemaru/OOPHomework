#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "plan.h"

class Day {
protected:
    int mon;
    int date;
    std::string day;

    std::vector<std::string> plan;

public:
    Day(int m, int d, std::string _day): mon(m), date(d), day(_day) {};

    bool insert(Plan pl) {
        if (pl.getDay() != std::make_pair(mon, date)) return false;
        plan.push_back(pl.getPlan());
        return true;
    }

    virtual void print() {
        std::cout << mon << '/' << date << ' ' << day << ' ';
        if (plan.empty()) std::cout << "Today is Free" << std::endl;
        else std::cout << "Today's Plan:" << std::endl;
        if (!plan.empty()) {
            for (std::string x: plan) {
                std::cout << x << std::endl;
            }
        }
    }

};