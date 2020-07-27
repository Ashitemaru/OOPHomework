#include "Student.h"
#include <string>
#include <cassert>
#include <iostream>
#include <tuple>

Student::Student(std::string n):name(n),Chi(0),Mat(0),Eng(0){};

std::string Student::getName(){
    return name;
}

int Student::getTotal(){
    return Chi+Mat+Eng;
}

void Student::set_sub(int score,char* sub){
    switch(sub[0]){
        case 'C':{
            Chi=score;
            break;
        }
        case 'M':{
            Mat=score;
            break;
        }
        case 'E':{
            Eng=score;
            break;
        }
        default: assert(false);
    }
    return;
}

bool Student::operator<(Student b){
    auto atu=std::make_tuple(getTotal(),Chi,Mat,Eng);
    auto btu=std::make_tuple(b.getTotal(),b.Chi,b.Mat,b.Eng);
    return atu<btu;
}

std::ostream& operator<<(std::ostream& out,const Student& src){
    out<<src.name<<"-Total-"
       <<src.Chi+src.Mat+src.Eng<<"-Chinese-"
       <<src.Chi<<"-Math-"
       <<src.Mat<<"-English-"
       <<src.Eng;
    return out;
}

Student::~Student(){};