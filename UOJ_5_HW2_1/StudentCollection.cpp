#include "StudentCollection.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAXN 100

StudentCollection::StudentCollection():num_of_students(0){
    list.clear();
};

std::istream& operator>>(std::istream& in,StudentCollection& sc){
    char name[MAXN]={'\0'};
    char subject[MAXN]={'\0'};
    char score_s[MAXN]={'\0'};
    std::cin.ignore(MAXN,'\n');
    std::cin.getline(name,MAXN,'-');
    std::cin.getline(subject,MAXN,'-');
    std::cin>>score_s;
    //input.
    int loc=-1;
    for(int i=0;i<sc.num_of_students;i++)
        if(name==sc.list[i].getName()){
            loc=i;
            break;
        }
    if(loc<0){
        sc.list.push_back(Student(name));
        loc=sc.num_of_students;
        sc.num_of_students++;
    }
    //if student does not exist, create it.
    int score=atoi(score_s);
    sc.list[loc].set_sub(score,subject);
    //final settings.
    return in;
}

std::ostream& operator<<(std::ostream& out,const StudentCollection& src){
    for(int i=0;i<src.num_of_students;i++) out<<src.list[i]<<std::endl;
    return out;
}

Student StudentCollection::operator[](std::string name){
    for(int i=0;i<num_of_students;i++)
        if(list[i].getName()==name) return list[i];
    return list[0];
}

bool my_cmp(Student a,Student b){
    return b<a;
}
void StudentCollection::sortByScore(){
    std::sort(list.begin(),list.end(),my_cmp);
}

StudentCollection::~StudentCollection(){};