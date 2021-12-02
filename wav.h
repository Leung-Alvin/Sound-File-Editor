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

void setBuffer(unsigned char* b);

void setData(std::vector<float> data);

Wav* readFile(std::string s);

int read(const std::string &fileName);

void save(const std::string &outFileName);


};
#endif

/*
	for(int i = 0; i < newData.size(); i++){
		if(i < data.size()){
			data[i] = newData[i];
		}
		else{
			data.push_back(newData[i]);
		}
	}
	header.data_bytes = header.num_channels * newData.size() * header.sample_alignment;
	setBuffer();
*/
