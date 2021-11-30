#include "wav.h"
#include "wavheader.h"
#include "wavManager.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

const float MAX_16BIT = 65535;

static bool abs_compare(float a, float b)
{
    return (std::abs(a) < std::abs(b));
}

void Wav::read(const std::string &fileName){
	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*) &header,sizeof(wav_header));
		buffer = new unsigned char[header.data_bytes];
		file.read((char*) buffer, header.data_bytes);
		file.close();
	}
	for(int i = 0; i < header.data_bytes / header.sample_alignment; i++) {
		data.push_back((float)buffer[i] / MAX_16BIT);
	}
}


void Wav::save(const std::string &outFileName){
	std::ofstream outFile(outFileName,std::ios::out | std::ios::binary);
	auto maxLocation = std::max_element(data.begin(),data.end(),abs_compare);
	float maxValue = *maxLocation;
	for(int i = 0; i < data.size(); i++){
		data[i] = data[i] / maxValue;
		buffer[i] = (short) (data[i] * MAX_16BIT);
	}
	outFile.write((char*) &header, sizeof(wav_header));
	outFile.write((char*) buffer, header.data_bytes);
	outFile.close();
}
		

wav_header Wav::getHeader() const{
	return header;
}

unsigned char* Wav::getBuffer() const{
	return buffer;
}

std::vector<float> Wav::getData() const{
	return data;
}

void Wav::setHeader(wav_header h){
	header = h;
}

void Wav::setBuffer(unsigned char* b){
	buffer = b;
}

void Wav::setData(std::vector<float> newData){
	data.reserve(newData.size());
	for(int i = 0; i < newData.size(); i++){
		data[i] = newData[i];
		if(i >= data.size() -1){
			data.push_back(newData[i]);
		}
	}
}
	


//std::vector<float> getData() const;

// [00110100, 10001010, ...]
// binary conversion to decimal?

