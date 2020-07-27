#ifndef MP4_H
#define MP4_H

#include "video.h"
#include <iostream>

class MP4: public Video{
public:
	void playVideo(){
		std::cout << "video: playing mp4 of length " << getLength() << std::endl;
	}
	void pauseVideo(){
		std::cout << "video: pause playing mp4" << std::endl;
	}
	int getLength(){
		return 20;
	}
	void doubleSpeed(){
		std::cout << "video: double speed mp4" << std::endl;
	}
	std::string getName(){
		return "MP4";
	}
};

#endif