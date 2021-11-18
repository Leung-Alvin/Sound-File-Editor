#include "wav.h"
#include "wavheader.h"
#include "wavManager.h"
#include <bits/stdc++.h>
#include <libgen.h>


const int NUM_ARGS = 1;
bool startOrQuit(){
	std::cout << "Type \"0\" to quit out of Wavio or Type in \"1\" to continue" << std::endl;
	std::string s;
	std::cin >> s;
	if(s == "0") {return 0;}
	else if(s == "1"){ return 1;} //run program
	else{return startOrQuit();}
}
Wav* readFile(){
	std::cout << "Please type a file name to open" << std::endl;
	std::string s;
	std::cin >> s;
	wav_header waveHeader;
	unsigned char* buffer;
	Wav* ret = new Wav();
	std::ifstream file(s, std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*) &waveHeader, sizeof(wav_header));
		buffer = new unsigned char[waveHeader.data_bytes];
		file.read((char*) buffer, waveHeader.data_bytes);
		file.close();
		
	}
	return nullptr;
}
int startSequence(){
	if(!startOrQuit()){
	 std::cout << "Program End" << std::endl;
	 return 0;
	}
	else{
		std::cout <<"Program Run" << std:: endl;
		if(readFile() == nullptr){ 
			std::cout << "File does not exist" << std:: endl;
			return startSequence();
		}
		else{
			std::cout << "File does exist" << std:: endl;
		}


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

	

