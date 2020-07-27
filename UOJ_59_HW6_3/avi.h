#ifndef AVI_H
#define AVI_H

#include "video.h"
#include <iostream>

class AVI: public Video{
public:
	void playVideo(){
		std::cout << "video: playing avi of length " << getLength() << std::endl;
	}
	void pauseVideo(){
		std::cout << "video: pause playing avi" << std::endl;
	}
	int getLength(){
		return 50;
	}
	void doubleSpeed(){
		std::cout << "video: double speed avi" << std::endl;
	}
	std::string getName(){
		return "AVI";
	}
};

#endif