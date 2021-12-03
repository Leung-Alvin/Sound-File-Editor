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
	std::vector<float> data; //new
	
public:


wav_header getHeader() const;

std::vector<float> getData() const;

void setHeader(wav_header h);

void setData(std::vector<float> data);

Wav* readFile(std::string s);

int read(const std::string &fileName);

void save(const std::string &outFileName);

void printData(std::string fileName);

void read8_bit(const std::string &fileName);

void read16_bit(const std::string &fileName);

void save8_bit(const std::string &outFileName);

void save16_bit(const std::string &outFileName);

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
