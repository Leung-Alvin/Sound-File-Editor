#include "gainadjustment.h"

std::vector<float> GainAdjustment::process(const std::vector<float>&input, float gain){
	std::vector<float> output;
	output.reserve(input.size());
	for(int i = 0; i < input.size(); i++){
		output[i] = gain*input[i];
	}
	return output;
}
