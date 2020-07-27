#pragma once
#include "Student.h"
class ClassSystem{
    int num_of_students;
    Student list[1010];
    int class_number;
public:
    ClassSystem();
    void addStudent(Student);
    void addClassNumber();
    void signIn(std::string);
    Student getStudentById(int);
    Student getStudentByName(std::string);
};