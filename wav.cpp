#include "wav.h"
#include "wavheader.h"
#include "wavManager.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <cstdlib>

const float MAX_16BIT = 65535; //Reason of Change 32768 65535

static bool abs_compare(float a, float b)
{
    return (std::abs(a) < std::abs(b));
}

int Wav::read(const std::string &fileName){
	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*) &header,sizeof(wav_header));
		buffer = new unsigned char[header.data_bytes];
		file.read((char*) buffer, header.data_bytes);
		file.close();
	}
	std::string riff_header(header.RIFF,4);
	if(riff_header != "RIFF"){
		return -1;
	}
	std::string wave_header(header.wave_header,4);
	if(wave_header != "WAVE"){
		return -1;
	}
	for(int i = 0; i < header.data_bytes / header.sample_alignment; i++) {
		data.push_back((float)buffer[i] / MAX_16BIT);
	}
	return 1;
}



void Wav::save(const std::string &outFileName){
	std::ofstream outFile(outFileName,std::ios::out | std::ios::binary);
	auto maxLocation = std::max_element(data.begin(),data.end(),abs_compare);
	float maxValue = *maxLocation;
	for(int i = 0; i < data.size(); i++){
		data[i] = data[i] / maxValue;
		buffer[i] = (char) (data[i] * 100);
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
	buffer = new unsigned char[header.data_bytes];
	int bufferit = 0;
	while(bufferit < data.size()){
		buffer[bufferit] = data[bufferit];
		bufferit++;
	}
	for(int i = 0; i < newData.size(); i++){
		data.push_back(newData[i]);
		buffer[bufferit+i] = (char) (data[bufferit+i] * MAX_16BIT);
	}
}
	
void Wav::printData(std::string fileName){
	std::ofstream file;
	file.open(fileName);
	for(int i=0;i<data.size();++i){
		file<<data[i]<<endl;
	}
	file.close();
}

/*
	header.data_bytes = header.num_channels * newData.size() * header.sample_alignment;
	buffer = new unsigned char[header.data_bytes];
	int bufferit = 0;
	while(bufferit < data.size()){
		buffer[bufferit] = data[i];
		bufferit++;
	}
	for(int i = 0; i < newData.size(); i++){
		data.push_back(newData[i]);
		buffer[bufferit+i] = (char) (data[bufferit+i] * MAX_16BIT);
	}







	for(int i = 0; i < newData.size(); i++){
		data[i] = newData[i];
	}
	//header.data_bytes = header.num_channels * newData.size() * header.sample_alignment;
	//setBuffer();
*/


