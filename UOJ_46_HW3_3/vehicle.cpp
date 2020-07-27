#include "vehicle.h"
#include <string>
#include <iostream>

Vehicle::Vehicle(int num,std::string nam,std::string typ):_engine(nam),_wheel(num),type(typ){
    std::cout<<"Finish building a "<<type<<" with "<<num
             <<" wheels and a "<<nam<<" engine."<<std::endl;
};

void Vehicle::describe(){
    std::cout<<"A "<<type<<" with "<<_wheel.get_num()<<" wheels and a "
             <<_engine.get_name()<<" engine."<<std::endl;
    return;
}