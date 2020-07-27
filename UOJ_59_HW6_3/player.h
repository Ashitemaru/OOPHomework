#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "audio.h"
#include "video.h"

class Adapter{
public:
	virtual void play()=0;
	virtual void pause()=0;
	virtual void doublespeed()=0;
	virtual ~Adapter(){};
};

class Player{
	std::vector<Adapter*> playlist;
public:
	void add(Adapter* ada){
		playlist.push_back(ada);
	}
	void play(){
		if (playlist.empty())
			std::cout << "Nothing to play" << std::endl;
		for (Adapter* ada: playlist)
			ada->play();
	}
	void pause(){
		if (playlist.empty())
			std::cout << "Nothing to pause" << std::endl;
		for (Adapter* ada: playlist)
			ada->pause();
	}
	void doubleSpeed(){
		if (playlist.empty())
			std::cout << "Nothing to double speed" << std::endl;
		for (Adapter* ada: playlist)
			ada->doublespeed();
	}
};

class AudioAdapter: public Adapter{
	Audio* aud;
public:
	AudioAdapter(Audio* src):aud(src){};
	virtual void play() override {
		aud->play();
	}
	virtual void pause() override {
		aud->pause();
	}
	virtual void doublespeed() override {
		std::cout<<"audio cannot be double speed"<<std::endl;
	}
	virtual ~AudioAdapter(){delete aud;}
};

class VideoAdapter: public Adapter{
	Video* vid;
public:
	VideoAdapter(Video* src):vid(src){};
	virtual void play() override {
		vid->playVideo();
	}
	virtual void pause() override {
		vid->pauseVideo();
	}
	virtual void doublespeed() override {
		vid->doubleSpeed();
	}
	virtual ~VideoAdapter(){delete vid;}
};

#endif