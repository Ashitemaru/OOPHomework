#pragma once
#include <string>
class Student{
    std::string name;
    int present_times;
    int total_times;
public:
    Student();
    Student(std::string);
    void Present();
    void Adjust();
    std::string getName();
    int getPresentTimes();
    int getAbsentTimes();
};