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

