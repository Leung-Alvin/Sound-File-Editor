#include <fstream>
#include <iostream>
#ifndef WAV_H
#define WAV_H

class Wav{


Wav() = default;

void readFile(const std::string &fileName);
};

#endif
