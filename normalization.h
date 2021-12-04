#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "gainadjustment.h"
#include <cmath>
#include <vector>
class Normalization{
public:
static std::vector<float> process(const std::vector<float> &input);
};
#endif
