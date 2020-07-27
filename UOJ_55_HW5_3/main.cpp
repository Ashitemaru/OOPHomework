#include<iostream>
#include<list>
#include"myqueriable.h"

using namespace std;

bool op1(int x){return x > 2 && x < 10;}
class Op2{
public:
    int operator()(int x) {return x * 2;}
}op2;

int main(){
    list<int> li = {1, 4, 6, 2, 10};
    auto out = from(li)
        .where(op1)  // 4, 6
        .apply(op2)  // 8, 12
        .sum();
    cout << out << endl;
}