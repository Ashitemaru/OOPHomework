#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

int n;
std::regex patterns[3]={
    std::regex("[0-9]{4}[-.][0-9]{1,2}[-.][0-9]{1,2}"),
    std::regex("[0-9]{11}"),
    std::regex("[0-9A-Za-z]+@[0-9A-Za-z]+(\\.[0-9A-Za-z]+)+")
};

class student{
    std::string name;
    int y;
    int m;
    int d;
    std::string date;
    std::string tele;
    std::string email;
public:
    student(std::string n,std::string da,std::string t,std::string e):name(n),date(da),tele(t),email(e){
        y=std::stoi(da.substr(0,4));
        m=std::stoi(da.substr(5,2));
        d=std::stoi(da.substr(8,2));
    }
    std::tuple<int,int,int> getTuple(){return std::make_tuple(y,m,d);}
    friend std::ostream& operator<<(std::ostream& out,const student& src){
        out<<src.name<<'-'<<src.date<<'-'<<src.tele<<'-'<<src.email<<std::endl;
        return out;
    }
};

bool my_cmp(student& a,student& b){
    return a.getTuple()<b.getTuple();
}

int main(){
    std::cin>>n;
    std::string* list=new std::string[n];
    std::vector<student> pile;
    std::cin.ignore(1,'\n');
    for(int i=0;i<n;i++) getline(std::cin,list[i]);
    for(int i=0;i<n;i++){
        std::smatch sm[3];
        for(int j=0;j<3;j++) std::regex_search(list[i],sm[j],patterns[j]);
        int begin=(list[i][0]=='I')?5:11;
        int end=list[i].find('.');
        std::string name=list[i].substr(begin,end-begin);
        std::string date=sm[0][0];
        //std::cout<<date<<std::endl;
        if(date[4]==date[6]) date.insert(date.begin()+5,'0');
        if(date.length()<10) date.insert(date.end()-1,'0');
        std::replace(date.begin(),date.end(),'-','.');
        pile.push_back(student(name,date,sm[1][0],sm[2][0]));
    }
    std::sort(pile.begin(),pile.end(),my_cmp);
    for(int i=0;i<n;i++) std::cout<<pile[i];
    delete[] list;
    return 0;
}