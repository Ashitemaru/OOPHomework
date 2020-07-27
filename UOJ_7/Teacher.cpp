#include <iostream>
#include <string>
#include "Teacher.h"
#include "Course.h"

Teacher::Teacher(std::string tname):Person(tname,""){
    std::cout<<"constructing Teacher "<<tname<<std::endl;
}

Teacher::~Teacher(){
    std::cout<<"destructing Teacher "<<(*this).getName()<<std::endl;
}