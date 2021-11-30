#include "wav.h"
#include "wavheader.h"
#include "wavManager.h"
#include "echo.h"

const int NUM_ARGS = 1;
const std::string separator = "---------------------";

//Start menu that asks the user whether they want to quit or continue

bool startOrQuit(){
	std::cout << separator << "\nWelcome to Wavio! \nMenu (Type the Number in) \n\"0\" - Quit \n\"1\" Start \n" << separator<< std::endl;
	std::string s;
	std::cin >> s;
	if(s == "0") {return 0;}
	else if(s == "1"){ return 1;} //run program
	else{return startOrQuit();}
}

//Reads the file name inside the folder of the program. If the name is invalid or is not formatted, 
//readFile() returns a nullptr to be used in startSequence().


//Transitions startOrQuit() and readFile() together in order to create a smooth start sequence


void printMetaData(std::string fileName, wav_header header){
	std::cout << separator << std::endl;
	std::cout << "File Name: " << fileName<< std::endl;
	std::cout << "Sample Rate: " << header.sample_rate << " Hz" << std::endl;
	std::cout << "Bits per Sample: " << header.bit_depth << "-Bit" << std::endl;
	int monoOrStereo = header.num_channels;
	std::string s;
	if(monoOrStereo == 1){
		s = "Mono";
	}
	else{
		s = "Stereo";
	}	
	std::cout << "Mono or Stereo: " << s << std::endl;
	std::cout << separator << std::endl;
}

int startSequence(){
	if(!startOrQuit()){
	 std::cout << "Program End" << std::endl;
	 return 0;
	}
	else{
		std::cout <<"Program Run" << std:: endl;
		std::cout << "Please type a file name to open, exclude \".wav\"" << std::endl;
		std::string s;
		std::cin >> s;
		s+=".wav";
		Wav wav;
		wav.read(s);
		/*
		if(wav == nullptr){ 
			std::cout << "File does not exist" << std:: endl;
			return startSequence();
		}
		else{
		*/
			std::cout << "File does exist" << std:: endl;
			printMetaData(s,wav.getHeader());
			std::vector<float> echoData = Echo::process(wav.getData(), 20, 1);
			wav.setData(echoData);
			wav.save("Copy.wav");


	}
	return 0;
}



void processSequence(){
}	

int main(int argc, char const *argv[]){
	startSequence();
}

// Access Token: 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

/*
	bool check;
	std::cout << "Type \"0\" to quit out of Wavio or Type in \"1\" to continue" << std::endl;
	std::string s;
	std::cin >> s;
	if(s == "0") {check = 0;}
	else if(s == "1") {check = 1;} //run program
	else{check = startOrQuit();}
*/
/*
	std::string izeof(wav_header)directory = findDirectory(s);
	std::ifstream ifs(directory+"/" + s);
	if(!ifs){
		return 0;
	}
	return 1;
*/
/*
	int route = readFile();
	if(route == 0){
		stringstream error;
		error << "File " << s << " does not exist";
		throw invalid_argument (error.str());
	}
	else if(route == 1){
		stringstream error;
		error << "File " << 
*/

	

