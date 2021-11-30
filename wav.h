#include <fstream>
#include <iostream>
#include "wavheader.h"
#include <vector>
#ifndef WAV_H
#define WAV_H

class Wav{

public:

Wav() = default;

private:
	wav_header header;
	unsigned char* buffer;
	std::vector<float> data; //new
	
public:

unsigned char* getBuffer() const;

wav_header getHeader() const;

std::vector<float> getData() const;

void setHeader(wav_header h);

void setBuffer();

void setData(std::vector<float> data);

Wav* readFile(std::string s);

void read(const std::string &fileName);

void save(const std::string &outFileName);


};
#endif

/*
Wav* readFile(std::string s){
	s+= ".wav";
	wav_header waveHeader;
	unsigned char* buffer;
	Wav* ret = new Wav();
	std::ifstream file(s, std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*) &waveHeader, sizeof(wav_header));
		buffer = new unsigned char[waveHeader.data_bytes];
		file.read((char*) buffer, waveHeader.data_bytes);
		file.close();
		ret.setHeader(waveHeader);
		ret.setBuffer(buffer);
		/*for(int i = 0; i < waveHeader.data_bytes / waveHeader.sample_alignment; i++)
		{

		return ret;
	}
	return nullptr;
}
*/
