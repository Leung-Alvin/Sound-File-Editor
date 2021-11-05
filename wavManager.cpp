#include "wavManager.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

WavManager::WavManager(const string &fileName){
	loadWav(fileName);
}

void WavManager::loadWav(const string &fileName){
	std::ifstream ifs(fileName, ios::binary | ios::in);
	//if(ifs.is_open()){
		//ifs.read((char*)&wa
}
