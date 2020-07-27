#ifndef AUDIO_H
#define AUDIO_H

class Audio {
public:
	virtual void play() = 0;
	virtual void pause() = 0;
	virtual std::string getName() = 0;
	virtual ~Audio() {}
};
#endif