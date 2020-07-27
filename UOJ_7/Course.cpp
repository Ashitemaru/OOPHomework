#include "Course.h"
#include <string>
#include <iostream>
#include "Teacher.h"
#include "Student.h"

Course::Course(){};

Course::Course(int NOS,std::string sub):num_of_students(NOS),subject(sub){
    exist_students=0;
    list=new Student*[1010];
    std::cout<<"constructing Course: "<<subject<<std::endl;
}

Course::~Course(){
    delete teacher;
    for(int i=0;i<num_of_students;i++)
        delete list[i];
    delete [] list;
    std::cout<<"destructing Course: "<<subject<<std::endl;
}

void Course::addTeacher(std::string tname){
    teacher=new Teacher(tname);
    return;
}

void Course::addStudent(std::string sname,int score,std::string sinfo){
    list[exist_students]=new Student(sname,score,sinfo);
    exist_students++;
    return;
}

std::string Course::getSubject(){
    return (*this).subject;
}

Student* Course::getStudent(std::string sname){
    Student* result=nullptr;
    for(int i=0;i<num_of_students;i++)
        if((*list[i]).getName()==sname){
            result=list[i];
            std::cout<<"Student ";
            break;
        }
    return result;
}

Teacher* Course::getTeacher(){
    return teacher;
}