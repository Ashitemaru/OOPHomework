#ifndef WAV_H
#define WAV_H

#include "audio.h"
#include <iostream>

class WAV: public Audio{
public:
	void play(){
		std::cout << "audio: playing wav" << std::endl;
	}
	void pause(){
		std::cout << "audio: pause playing wav" << std::endl;
	}
	std::string getName(){
		return "WAV";
	}
};

#endif