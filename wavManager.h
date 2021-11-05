#include "wavheader.h"
#include "wav.h"
#ifndef WAVMANAGER_H
#define WAVMANAGER_H
using namespace std;

class WavManager{
public:
	WavManager() = default;
	
	WavManager(const string &fileName);

public:
	WAV_HEADER header;

public:
	void loadWav(const string &fileName);
};/home/wes/cs202/labs/lab8

#endif
