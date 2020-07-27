#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

Student::Student(std::string sname,int score,std::string sinfo):Person(sname,sinfo),score(score){
    std::cout<<"constructing Student "<<sname<<std::endl;
}

Student::~Student(){
    std::cout<<"destructing Student "<<(*this).getName()<<std::endl;
}

std::string Student::getInfo(){
    return Person::getInfo()+" Score:"+std::to_string(score);
}