#ifndef ECHO_H
#define ECHO_H
#include <vector>

class Echo{
public:
	static std::vector<float> process(const std::vector<float>&input, float gain, int delay);
};


/*
#ifndef ECHO_H
#define ECHO_H


#include <iostream>
#include "Processor.h"

class Echo:public Processor{
	
private:

	int delay;

public:

	Echo();

	Echo(int);

	void createEcho(unsigned char*, int);	

	void processBuffer(unsigned char* buffer, int bufferSize);
	
};

*/	

#endif
