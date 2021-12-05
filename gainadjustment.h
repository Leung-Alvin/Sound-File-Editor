#ifndef GAINADJUSTMENT_H
#define GAINADJUSTMENT_H
#include <vector>

class GainAdjustment{
public:
    /**
     * used to process the sound data (float vector) and amplify the amount of sound with gain
     * @param input: float vector of sound data to be amplified
       @param gain: float representing the amount to amplify the sound file by.
     */
	static std::vector<float> process(const std::vector<float> &input, float gain);
};

#endif
