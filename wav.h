#include <fstream>
#include <iostream>
#include "wavheader.h"
#include <vector>
#ifndef WAV_H
#define WAV_H

class Wav{

public:
    /**
     * constructor for Wav class
     */
Wav() = default;

private:
	wav_header header;
	std::vector<float> data;
	
public:

    /**
     * Returns for the header attribute of this Wav object.
     * @return wav_header, the Wav header of this Wav.
     */
wav_header getHeader() const;
    /**
     * Returns the sound data of this Wav object.
     * @return vector<float>, the float vector representing the sound data.
     */
std::vector<float> getData() const;
    /**
     * Sets the header of this object to the new header (h)
     * @param h, the new header to set this Wav's header to.
     */
void setHeader(wav_header h);
    /**
     * Sets the sound data of this object to the new sound data (dat)
     * @param data, the new sound data to set this Wav's sound data to.
     */
void setData(std::vector<float> data);
    /**
     * reads the input file and instantiates the Wav attributes on the Wav object calling it
       it attempts to read both 8-bit and 16-bit mono/stereo Wav files.
     * @param fileName, the name of the Wav file that this Wav is trying to read into
       @return int, an integer that is coded to represent the sucess/failure of the read. If the
       file could not be read properly, an error message is sent to the user.
     */
int read(const std::string &fileName);
    /**
     * saves the current Wav object's properties into a Wav file onto the folder named 
       outFileName.
     * @param fileName, the name of the Wav file that this Wav is trying to write into
     */
void save(const std::string &outFileName);
   /**
     * used for reading 8-bit audio
     * @param fileName, 8-bit audio file name
     */
void read8_bit(const std::string &fileName);
   /**
     * used for reading 16-bit audio
     * @param fileName, 16-bit audio file name
     */
void read16_bit(const std::string &fileName);
    /**
     * used for saving 8-bit audio
     * @param FileName, name of the Wav file to be written into
     */
void save8_bit(const std::string &outFileName);
    /**
     * used for saving 16-bit audio
     * @param FileName, name of the Wav file to be written into
     */
void save16_bit(const std::string &outFileName);

};
#endif

/*
	for(int i = 0; i < newData.size(); i++){
		if(i < data.size()){
			data[i] = newData[i];
		}
		else{
			data.push_back(newData[i]);
		}
	}
	header.data_bytes = header.num_channels * newData.size() * header.sample_alignment;
	setBuffer();
*/
