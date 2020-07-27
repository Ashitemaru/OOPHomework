#pragma once
#include "Student.h"
#include <iostream>
#include <vector>
class StudentCollection{
    int num_of_students;
    std::vector<Student> list;
public:
    StudentCollection();
    friend std::istream& operator>>(std::istream&,StudentCollection&);
    friend std::ostream& operator<<(std::ostream&,const StudentCollection&);
    Student operator[](std::string);
    void sortByScore();
    ~StudentCollection();
};