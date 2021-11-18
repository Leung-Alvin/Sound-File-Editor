#include "wav.h"
#include "wavheader.h"
#include "wavManager.h"

unsigned char* Wav::getBuffer() const{
	return buffer;
}

void Wav::setHeader(wav_header h){
	header = h;
}

void Wav::setBuffer(unsigned char* b){
	buffer = b;
}

// [00110100, 10001010, ...]
// binary conversion to decimal?

