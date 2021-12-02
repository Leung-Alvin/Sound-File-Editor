#include "wav.h"
#include "wavheader.h"
#include "wavManager.h"
#include "echo.h"

class UI{
public:
const int NUM_ARGS = 1;
const std::string separator = "---------------------";
UI() = default;

public:
bool startOrQuit();
void printMetaData(std::string fileName, wav_header header);
void startSequence();
void processSequence(std::string fileName);

};
