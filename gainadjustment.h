#ifndef GAINADJUSTMENT_H
#define GAINADJUSTMENT_H
#include <vector>

class GainAdjustment{
public:
	static std::vector<float> process(const std::vector<float> &input, float gain);
};

#endif
