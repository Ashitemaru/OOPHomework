#pragma once
#include <string>
#include <iostream>
class Student{
    int Chi;
    int Mat;
    int Eng;
    std::string name;
public:
    Student(std::string);
    std::string getName();
    int getTotal();
    void set_sub(int,char*);
    bool operator<(Student);
    friend std::ostream& operator<<(std::ostream&,const Student&);
    ~Student();
};