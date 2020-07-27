#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Computer.h"

class ComputerCollection{
    std::vector<Computer> list;
public:
    friend std::istream& operator>>(std::istream&,ComputerCollection&);
    friend std::ostream& operator<<(std::ostream&,const ComputerCollection&);
    Computer& operator[](std::string);
    void sortByScore();
};