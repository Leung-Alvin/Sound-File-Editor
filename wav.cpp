#include "wav.h"
#include "wavheader.h"
#include "wavManager.h"

void Wav::readFile(const std::string &fileName){
	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	/*if(file.is_open()) {
		file.read((char*)&wav_header, sizeof(wav_header));
		buffer = new unsigned char [waveHeader.data_bytes];
		file.read((char*)buffer, waveHeader.data_bytes);
		file.close();
	}*/

}
