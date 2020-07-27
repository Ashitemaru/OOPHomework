#pragma once
#include "Hero.h"

class SkilledHero : public Hero {
protected:
	static int AvatarLevel;
	static int BladestormLevel;
public:
	virtual void getSkill(name2Level& skillMap) {
		skillMap["Avatar"] = AvatarLevel;
		skillMap["Bladestorm"] = BladestormLevel;
		AvatarLevel = 0;
		BladestormLevel = 0;
	}
};

int SkilledHero::AvatarLevel = 0;
int SkilledHero::BladestormLevel = 0;