#include "wav.h"
#include "wavheader.h"
#include "echo.h"
#include "gainadjustment.h"
#include "normalization.h"
   /**
    * This class represents the UI class responsible for interacting with the user and taking in inputs or printing out information.
    */
class UI{
public:

    /**
     * String constant that represents a separator using dashes to separate parts of text
     */
const std::string separator = "---------------------";
    /**
     * constructor for UI class
     */
UI() = default;

public:
    /**
     * used to prompt the user to determine whether to start or quit the program
     */
bool startOrQuit();
    /**
     * prints the metadata revolving a certain WAV file
     * @param fileName: the wav file that needs its meta data printed
     * @param header: the header of the wav file.
     */
void printMetaData(std::string fileName, wav_header header);
    /**
     * used to start the whole program and can be used to reset the program from the beginning.
     */
void startSequence();
    /**
     * used to process inputs and allow the user to choose a processor (echo, normalize, gain)
     * @param w: the Wav object that needs to be processed.
     */
void processSequence(Wav w);

};
