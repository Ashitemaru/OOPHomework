#pragma once

#include <string>

class Plan {
private:
    int mon;
    int date;
    std::string p;

public:
    Plan(int m, int d, std::string _p): mon(m), date(d), p(_p) {};

    std::string getPlan() {
        return p;
    }

    std::pair<int, int> getDay() {
        return std::make_pair(mon, date);
    }

};