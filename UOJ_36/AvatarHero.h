#pragma once
#include "SkilledHero.h"

class AvatarHero : public SkilledHero {
public:
	AvatarHero(Hero* src) {
		avatarLevel++;
	}
};