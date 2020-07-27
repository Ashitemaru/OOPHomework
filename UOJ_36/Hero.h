#pragma once
#include <map>
#include <string>

typedef std::map<std::string, int> name2Level;

class Hero {
public:
    virtual void getSkill(name2Level& skillMap) = 0;
	virtual ~Hero() { }
};

class OrcHero : public Hero {
public:
    void getSkill(name2Level& skillMap) {}
};

class HumanHero : public Hero {
public:
    void getSkill(name2Level& skillMap) {}
};