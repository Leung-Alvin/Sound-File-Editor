#include <fstream>
#include <iostream>
#include "wavheader.h"
#ifndef WAV_H
#define WAV_H

class Wav{

public:

Wav() = default;

private:
	wav_header header;
	unsigned char* buffer;
public:

unsigned char* getBuffer() const;

void setHeader(wav_header h);

void setBuffer(unsigned char* b);


};
#endif
