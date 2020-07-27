#pragma once

#include "AbstractFactory.h"

class HumanFactory: public AbstractFactory {
public:
    virtual Casern* createCasern(){
        return new HumanCasern;
    }
    virtual Footman* createFootman(std::string _footmanId){
        return new HumanFootman(_footmanId);
    }
    virtual Commander* createCommander(std::string _commanderId){
        return new HumanCommander(_commanderId);
    }
    virtual Belong* createBelong(Footman* _footman, Commander* _commander){
        return new HumanBelong(_footman,_commander);
    }
};

class OrcFactory : public AbstractFactory {
public: 
    virtual Casern* createCasern(){
        return new OrcCasern;
    }
    virtual Footman* createFootman(std::string _footmanId){
        return new OrcFootman(_footmanId);
    }
    virtual Commander* createCommander(std::string _commanderId){
        return new OrcCommander(_commanderId);
    }
    virtual Belong* createBelong(Footman* _footman, Commander* _commander){
        return new OrcBelong(_footman,_commander);
    }
};
