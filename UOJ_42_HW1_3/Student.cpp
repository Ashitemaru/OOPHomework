#include "Student.h"
#include <string>

Student::Student(){};

Student::Student(std::string input_name):name(input_name),present_times(0),total_times(0){};

std::string Student::getName(){
    return name;
}

void Student::Present(){
    present_times++;
    return;
}

int Student::getPresentTimes(){
    return present_times;
}

void Student::Adjust(){
    total_times++;
    return;
}

int Student::getAbsentTimes(){
    return total_times-present_times;
}