#include "wav.h"
#include "wavheader.h"
#include "wavManager.h"

unsigned char* Wav::getBuffer() const{
	return buffer;
}

// [00110100, 10001010, ...]
// binary conversion to decimal?

