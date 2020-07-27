#pragma once
#include "Person.h"
#include "Course.h"
#include <string>
class Teacher: public Person{
public:
    Teacher(std::string);
    ~Teacher();
};