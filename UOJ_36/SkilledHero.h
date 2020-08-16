#pragma once
#include "Hero.h"

class SkilledHero : public Hero {
protected:
	static int avatarLevel;
	static int bladestormLevel;
public:
	virtual void getSkill(name2Level& skillmap) override {
		skillmap["Avatar"] = avatarLevel;
		skillmap["Bladestorm"] = bladestormLevel;
		avatarLevel = 0;
		bladestormLevel = 0;
		return;
	};
};

int SkilledHero::avatarLevel = 0;
int SkilledHero::bladestormLevel = 0;