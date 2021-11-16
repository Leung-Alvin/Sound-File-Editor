#include "wavManager.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <math.h>

WavManager::WavManager(const string &fileName){
	loadWav(fileName);
}

void WavManager::loadWav(const string &fileName){
	std::ifstream ifs(fileName, ios::binary | ios::in);
	//if(ifs.is_open()){
		//ifs.read((char*)&wa
}
void WavManager::normalize(float data[]){
	/*float largest = data[0];
	for(float f : data)
	{
		if(fabs(f) > largest){
			largest = f;
		}
	}
	if(largest != 0){
		float scalingValue = 1/largest;
	}
	float dataScaled[data.size()];*/
}

/*


    Original data: n = {0,0.2,0.4,0,-0.3}

    Largest absolute value: 0.4, so scaling value s = 1/0.4 = 2.5

    Scaled result: n_scaled = {0, 0.5,1,0,-0.75}

*/
