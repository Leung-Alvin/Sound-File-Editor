#include <iostream>
#include <string>
#include <fstream>

#ifndef WAVHEADER_H
#define WAVHEADER_H

using namespace std;
   /**
    * A structure to represent the header of WAV files
    */

typedef struct wav_header{
   /**
    * A character array the stores the RIFF header
    */
	char RIFF[4];
   /**
    * An integer referring to the RIFF Chunk size
    */
	int chunkSize;
   /**
    * A character array that stores the WAV header
    */
	char wave_header[4];
   /**
    * A character array that stores the fmt header
    */
	char fmt[4];
   /**
    * An integer representing the length of format data
    */
	int fmt_size;
   /**
    * A short that determines the type of format (1 is PCM)
    */ 
	short audio_format;
   /**
    * A short that represents the number of channels
    */
	short num_channels;
   /**
    * An integer that represents Sample Rate, Sample Rate = # of Samples/second, or Hertz
    */
	int sample_rate;
   /**
    * An integer that represents Byte Rate, Byte Rate = (Sample Rate * BitsPerSample * Channels)
    * /8
    */
	int byte_rate;
   /**
    * A short that represents Sample Alignment (SA), SA = (BitsPerSample * Channels) / 8.1 - 8
    * bit mono2 - 8 bit stereo/16 bit mono4 - 16 bit stereo 
    */
	short sample_alignment;
   /**
    * An short that represents the number of bits per sample
    */
	short bit_depth;
   /**
    * A character array that stores the data header.
    */
	char data_header[4];
   /**
    * An integer that stores the number of data bytes the WAV has.
    */
	int data_bytes;
} wav_header;

#endif
