#include <iostream>
#define func(x) x*(-1)+(x/4)
int main(){
    int a=5;
    std::cout<<func(1.5+a)<<1.5+a*(-1)+(1.5+a/4)<<std::endl;
    return 0;
}