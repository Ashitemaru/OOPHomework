#ifndef MP3_H
#define MP3_H

#include "audio.h"
#include <iostream>

class MP3: public Audio{
public:
	void play(){
		std::cout << "audio: playing mp3" << std::endl;
	}
	void pause(){
		std::cout << "audio: pause playing mp3" << std::endl;
	}
	std::string getName(){
		return "MP3";
	}
};

#endif