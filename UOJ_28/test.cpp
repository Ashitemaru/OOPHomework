#include <iostream>

class q {
public:
    virtual std::string get() = 0;
    virtual ~q() {};
};

class Base: public q {

public:
    virtual std::string get() {
        return "Base";
    }

    virtual ~Base() {
        if (get() == "Base") std::cout << "~~~" << std::endl;
    }
};

class Derive: public Base {
public:
    virtual std::string get() {
        return "Derive";
    }

    virtual ~Derive() {
        std::cout << "$$$" << std::endl;
    }
};

int main() {
    Derive* d = new Derive;
    delete d;
    return 0;
}