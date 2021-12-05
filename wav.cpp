#include "wav.h"
#include "wavheader.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iostream>

const float MAX_16BIT = 32767; //Reason of Change 32768 65535

const float MAX_8BIT = 256; //256 512

static bool abs_compare(float a, float b)
{
    return (std::abs(a) < std::abs(b));
}

void Wav::read8_bit(const std::string &fileName){
	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	char* buffer = new char[header.data_bytes];
	file.read((char*)buffer, header.data_bytes);
	for(int i = 0; i < header.data_bytes / header.sample_alignment; i++){
		data.push_back((float) buffer[i] / MAX_8BIT);
	}
	file.close();
	delete[] buffer;
}

void Wav::read16_bit(const std::string &fileName){
	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	short* buffer = new short[header.data_bytes];
	file.read((char*)buffer, header.data_bytes);
	for(int i = 0; i < header.data_bytes/header.sample_alignment; i++){
		data.push_back((float) buffer[i] / MAX_16BIT);
	}
	file.close();
	delete[] buffer;
}

int Wav::read(const std::string &fileName){
	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*) &header,sizeof(wav_header));
		int bd = header.bit_depth;
		if(bd == 8){ 
			read8_bit(fileName);
		}
		else if(bd == 16){
			read16_bit(fileName);
		}
		else{
			return -1;
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
	char* buffer = new char[data.size()];
	for(int i = 0; i < data.size(); i++){
		data[i] = data[i] / maxValue;
		buffer[i] = (char) (data[i] * MAX_8BIT);
	}
	header.data_bytes = data.size() * header.sample_alignment;
	header.chunkSize = header.data_bytes + 44 - 8;
	outFile.write((char*) &header, sizeof(wav_header));
	outFile.write((char*) buffer, header.data_bytes);
	outFile.close();
	delete[] buffer;
	
}

void Wav::save16_bit(const std::string &outFileName){
	std::ofstream outFile(outFileName,std::ios::out | std::ios::binary);
	auto maxLocation = std::max_element(data.begin(),data.end(),abs_compare);
	float maxValue = *maxLocation;
	short* buffer = new short[data.size()];
	for(int i = 0; i < data.size(); i++){
		data[i] = data[i] / maxValue;
		buffer[i] = (short) (data[i] * MAX_16BIT);
	}
	header.data_bytes = data.size() * header.sample_alignment;
	header.chunkSize = header.data_bytes + 44 - 8;
	outFile.write((char*) &header, sizeof(wav_header));
	outFile.write((char*) buffer, header.data_bytes);
	outFile.close();
	delete[] buffer;
	
}


void Wav::save(const std::string &outFileName){
	int bd = header.bit_depth;
	std::cout << bd << std::endl;
	if(bd == 8){
		save8_bit(outFileName);
	}
	else if(bd == 16){
		save16_bit(outFileName);
	}
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
		data[i] = newData[i];
	}
}
	


