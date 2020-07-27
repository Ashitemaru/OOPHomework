#pragma once
#include "Footman.h"
#include "Commander.h"
#include "Belong.h"
#include <vector>


class Casern {
    std::vector<Footman*> FootmanList;
    std::vector<Commander*> CommanderList;
    std::vector<Belong*> BelongList;
public:
    virtual std::string getKind() = 0;
	virtual void addFootman(Footman* _footman){
        FootmanList.push_back(_footman);
        return;
    }
    virtual void addCommander(Commander* _commander){
        CommanderList.push_back(_commander);
        return;
    }
    virtual void addBelong(Belong* _belong){
        BelongList.push_back(_belong);
        return;
    }
    virtual Footman* getFootmanbyIndex(int loc){
        return FootmanList[loc];
    }
    virtual Commander* getCommanderbyIndex(int loc){
        return CommanderList[loc];
    }
    virtual Belong* getBelongbyIndex(int loc){
        return BelongList[loc];
    }
};