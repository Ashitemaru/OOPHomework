#pragma once

#include "Footman.h"
#include "Commander.h"
#include "Belong.h"
#include "Casern.h"

class HumanFootman :  public Footman {
public:
    using Footman::Footman;
};

class OrcFootman :  public Footman {
public:
    using Footman::Footman;
};

class HumanCommander :  public Commander {
public:
    using Commander::Commander;
};

class OrcCommander :  public Commander {
public:
    using Commander::Commander;
};

class HumanBelong :  public Belong {
public:
    using Belong::Belong;
};

class OrcBelong :  public Belong {
public:
    using Belong::Belong;
};

class HumanCasern : public Casern {
public:
    virtual std::string getKind() { return "HumanCasern"; }
};

class OrcCasern : public Casern {
public:
	virtual std::string getKind() { return "OrcCasern"; }
};
