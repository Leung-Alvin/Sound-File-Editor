#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "gainadjustment.h"
#include <cmath>
#include <vector>
   /**
    * This class represents the normalization proccessor used to normalize sound data.
    */
class Normalization{
public:
    /**
     * used to process the sound data (float vector) and make the loudest sound the maximum value 
       to create an evenly sounding wav file.
     * @param input: float vector of sound data to be normalized
     */
static std::vector<float> process(const std::vector<float> &input);
};
#endif
