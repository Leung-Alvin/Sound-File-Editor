#include <iostream>
#include <string>
#include <fstream>

#ifndef WAVHEADER_H
#define WAVHEADER_H

using namespace std;

typedef struct wav_header{
	//RIFF Header
	char RIFF[4]; //RIFF Header
	int chunkSize; //RIFF Chunk Size
	char wave_header[4]; //
	char fmt[4]; //Format header
	int fmt_size; 
	short audio_format;
	short num_channels;
	int sample_rate;
	int byte_rate;
	short sample_alignment;
	short bit_depth;

	//DATA
	char data_header[4];
	int data_bytes;
	//char bytes[];
} wav_header;

#endif
