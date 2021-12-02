#include "echo.h"

std::vector<float> Echo::process(const std::vector<float>& input, float gain, int delay){
	std::vector<float> output;
	output.reserve(input.size());
	for(int i = 0; i< input.size(); i++){
		if(i > delay) {
			output.push_back(input[i] + gain*output[i-delay]);
		} else {
			output.push_back(input[i]);
		}
	}
	return output;
}

/*
#include "echo.h"
#include <iostream>

Echo::Echo(){
	delay = 0;
}

Echo::Echo(int newDelay){
	delay = newDelay;
}

void Echo::createEcho(unsigned char* buffer, int bufferSize){

	for(int i = delay; i < bufferSize; i++){
		if((buffer[i] + buffer[i-delay]) > 255){
			buffer[i] = 255;
		}
		else{
			buffer[i] = buffer[i] + buffer[i-delay];
		}
}
}

void Echo::processBuffer(unsigned char* buffer, int bufferSize){
	createEcho(buffer, bufferSize);
}

y[n] = x[n] + y[n-d] 

x[n] + x[n-d]?

{3,6,7,3+3.5, 
*/

