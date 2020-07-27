#include <iostream>
#include "player.h"
#include "mp3.h"
#include "wav.h"
#include "mp4.h"
#include "avi.h"

int main(){
	std::cout << "Create a player" << std::endl;
	Player* player = new Player();
	Adapter* mp3 = new AudioAdapter(new MP3());
	Adapter* wav = new AudioAdapter(new WAV());
	Adapter* mp4 = new VideoAdapter(new MP4());
	Adapter* avi = new VideoAdapter(new AVI());
	player->add(mp3);
	player->add(wav);
	player->add(mp4);
	player->add(avi);
	std::cout << "play all" << std::endl;
	player->play();
	std::cout << "pause all" << std::endl;
	player->pause();
	std::cout << "double speed" << std::endl;
	player->doubleSpeed();
	delete mp3;
	delete wav;
	delete mp4;
	delete avi;
	delete player;
	return 0;
}
