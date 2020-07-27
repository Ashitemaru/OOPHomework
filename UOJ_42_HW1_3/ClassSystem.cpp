#include "ClassSystem.h"
#include "Student.h"
#include <string>

ClassSystem::ClassSystem():num_of_students(0),class_number(0){};

void ClassSystem::addStudent(Student candi){
    list[num_of_students]=candi;
    num_of_students++;
    return;
}

void ClassSystem::addClassNumber(){
    class_number++;
    for(int i=0;i<num_of_students;i++)
        list[i].Adjust();
    return;
}

void ClassSystem::signIn(std::string name){
    for(int i=0;i<num_of_students;i++)
        if(list[i].getName()==name){
            list[i].Present();
            break;
        }
    return;
}

Student ClassSystem::getStudentById(int num){
    return list[num];
}

Student ClassSystem::getStudentByName(std::string iname){
    for(int i=0;i<num_of_students;i++)
        if(list[i].getName()==iname){
            return list[i];
        }
    return list[0];
}