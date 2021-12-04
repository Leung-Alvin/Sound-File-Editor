#include "normalization.h"

std::vector<float> Normalization::process(const std::vector<float> &input){
	float largest = std::abs(input[0]);
	for(int i = 0; i < input.size(); i++)
	{
		float val = std::abs(input[i]);
		if(val > largest){
			largest = val;
		}
	}
	float scalar = 0.0;
	if(largest != 0){
		scalar = 1/largest;
	}
	return GainAdjustment::process(input,scalar);
}



/*
	std::vector<float> output;
	output.reserve(input.size());
	auto maxLocation = std::max_element(input.begin(), input.end(),abs_compare);
	float maxValue = *maxLocation;
	for(int i = 0; i < input.size(); i++){
		output[i] = input[i] / maxValue;
	}
	return output;
}

*/


/*
	float largest = std::abs(input[0]);
	for(int i = 1; i < input.size(); i++)
	{
		float val = std::abs(input[i]);
		if(val > largest){
			largest = val;
		}
	}
	float scalar = 0.0;
	if(largest != 0){
		scalar = 1/largest;
	}
	return GainAdjustment::process(input,scalar);
*/
