#pragma once
#include "SkilledHero.h"

class BladestormHero : public SkilledHero {
public:
	BladestormHero(Hero* ptr) {
		BladestormLevel++;
	};
};