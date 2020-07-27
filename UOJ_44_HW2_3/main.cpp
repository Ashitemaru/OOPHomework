#include <iostream>
using namespace std;
class B {
public:
    B(int i) {}
};

class A {
private:
    int a = 1;
    char c = 'c';
    B b; // (2)
public:
    A() = default; // (1)
    A(int i):a(i), b(i) {}
    A(char ch) = delete; // (3)
};

int main(){
    return 0;
}