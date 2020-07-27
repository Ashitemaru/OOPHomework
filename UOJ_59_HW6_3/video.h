#ifndef VIDEO_H
#define VIDEO_H

class Video {
public:
	virtual void playVideo() = 0;
	virtual void pauseVideo() = 0;
	virtual int getLength() = 0;
	virtual void doubleSpeed() = 0;
	virtual std::string getName() = 0;
	virtual ~Video() {}
};
#endif