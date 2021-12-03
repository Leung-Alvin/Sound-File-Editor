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
#include <variant>
#include <iostream>

const float MAX_16BIT = 65535; //Reason of Change 32768 65535

const float MAX_8BIT = 512; //256 512

static bool abs_compare(float a, float b)
{
    return (std::abs(a) < std::abs(b));
}


void Wav::read8_bit(const std::string &fileName){
	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	char* buffer = new char[header.data_bytes];
	file.read((char*)buffer, header.data_bytes);
	for(int i = 0; i < header.data_bytes/header.sample_alignment; i++){
		data.push_back((float) buffer[i] / MAX_8BIT);
	}
	file.close();
}

void Wav::read16_bit(const std::string &fileName){
	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	short* buffer = new short[header.data_bytes];
	file.read((char*)buffer, header.data_bytes);
	for(int i = 0; i < header.data_bytes/header.sample_alignment; i++){
		data.push_back((float) buffer[i] / MAX_16BIT);
	}
	file.close();
}

int Wav::read(const std::string &fileName){
	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*) &header,sizeof(wav_header));
		int bd = header.bit_depth;
		if(bd == 8){ 
			read8_bit(fileName);
		}
		/*else if(bd == 16){
			read16_bit(fileName);
		}*/
		else{
			read16_bit(fileName);
		}
	}
	std::string riff_header(header.RIFF,4);
	std::string wave_header(header.wave_header,4);
	if(riff_header != "RIFF"){ 
		return -1;
	}
	if(wave_header != "WAVE"){
		return -1;
	}
	file.close();
	return 1;
}

void Wav::save8_bit(const std::string &outFileName){
	std::ofstream outFile(outFileName,std::ios::out | std::ios::binary);
	auto maxLocation = std::max_element(data.begin(),data.end(),abs_compare);
	float maxValue = *maxLocation;
	char* buffer = new char[header.data_bytes];
	for(int i = 0; i < data.size(); i++){
		data[i] = data[i] / maxValue;
		buffer[i] = (char) (data[i] * MAX_8BIT);
	}
	outFile.write((char*) &header, sizeof(wav_header));
	outFile.write((char*) buffer, header.data_bytes);
	outFile.close();
	
}

void Wav::save16_bit(const std::string &outFileName){
	std::ofstream outFile(outFileName,std::ios::out | std::ios::binary);
	auto maxLocation = std::max_element(data.begin(),data.end(),abs_compare);
	float maxValue = *maxLocation;
	short* buffer = new short[header.data_bytes];
	for(int i = 0; i < data.size(); i++){
		data[i] = data[i] / maxValue;
		buffer[i] = (char) (data[i] * MAX_16BIT);
	}
	outFile.write((char*) &header, sizeof(wav_header));
	outFile.write((char*) buffer, header.data_bytes);
	outFile.close();
	
}


void Wav::save(const std::string &outFileName){
	int bd = header.bit_depth;
	if(bd == 8 | bd ==16){
		save8_bit(outFileName);
	}
	/*else if(bd == 16){
		save16_bit(outFileName);
	}*/
}
		

wav_header Wav::getHeader() const{
	return header;
}


std::vector<float> Wav::getData() const{
	return data;
}

void Wav::setHeader(wav_header h){
	header = h;
}


void Wav::setData(std::vector<float> newData){
	for(int i = 0; i < newData.size(); i++){
		data.push_back(newData[i]);
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


