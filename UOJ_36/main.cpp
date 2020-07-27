#include "Hero.h"
#include "BladestormHero.h"
#include "AvatarHero.h"
#include <cstdlib>
#include <cstdio>

void ourAssert(bool flag){
	if(!flag) {
		printf("error!\n");
		exit(0);
	}
}

int main() {

    Hero* KD_lv0 = new OrcHero();
    Hero* KD_lv1 = new BladestormHero(KD_lv0);
    Hero* KD_lv2 = new AvatarHero    (KD_lv1);
    Hero* KD_lv3 = new BladestormHero(KD_lv2);
    Hero* KD_lv4 = new BladestormHero(KD_lv3);
    Hero* KD_lv5 = new BladestormHero(KD_lv4);

    name2Level KD_skillMap;
    KD_lv5->getSkill(KD_skillMap);

    ourAssert(KD_skillMap["Bladestorm"] == 4);
    ourAssert(KD_skillMap["Avatar"] == 1);
    printf("test1 ok!\n");

    Hero* KT_lv0 = new HumanHero();
    Hero* KT_lv1 = new AvatarHero(KT_lv0);
    Hero* KT_lv2 = new AvatarHero(KT_lv1);

    name2Level KT_skillMap;
    KT_lv2->getSkill(KT_skillMap);

    ourAssert(KT_skillMap["Avatar"] == 2);
    printf("test2 ok!\n");
    return 0;
}