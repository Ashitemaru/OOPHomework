#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class Person {
private:
    std::string name;
    std::string info;
public:
    std::string getName() const; // 给私有成员提供公有访问接口
    std::string getInfo() const;
    Person(const std::string& _name, const std::string& _info="");
    ~Person();
};

#endif