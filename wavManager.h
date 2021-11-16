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
	wav_header header;

public:
	void loadWav(const string &fileName);
	void normalize(float data[]);
};

#endif
