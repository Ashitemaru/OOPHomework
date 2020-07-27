#pragma once
#include <string>
#include "Person.h"
#include "Course.h"
class Student: public Person{
public:
    int score;
    Student(std::string,int,std::string);
    ~Student();
    std::string getInfo();
};