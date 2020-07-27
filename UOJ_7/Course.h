#pragma once
#include <string>
class Student;
class Teacher;
class Course{
private:
    int num_of_students;
    std::string subject;
    Teacher* teacher;
    Student** list;
    int exist_students;
public:
    Course();
    Course(int,std::string);
    ~Course();
    void addTeacher(std::string);
    void addStudent(std::string,int,std::string);
    std::string getSubject();
    Student* getStudent(std::string);
    Teacher* getTeacher();
};