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


