#include "UI.h"



//Start menu that asks the user whether they want to quit or continue

bool UI::startOrQuit(){
	std::cout << separator << "\nWelcome to Wavio! \nMenu (Type the Number in) \n\"0\" - Quit \n\"1\" Start \n" << separator<< std::endl;
	std::string s;
	std::cin >> s;
	if(s == "0") {return 0;}
	else if(s == "1"){ return 1;} //run program
	else{return startOrQuit();}
}

void UI::printMetaData(std::string fileName, wav_header header){
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

void UI::startSequence(){
	if(!startOrQuit()){
	 std::cout << "Program End" << std::endl;
	}
	else{
		std::cout << "Please type a file name to open, exclude \".wav\"" << std::endl;
		std::string s;
		std::cin >> s;
		s+=".wav";
		Wav wav;
		int n = wav.read(s);
		if(n == -1){
			std::cout << "Invalid File" << std::endl;
			return startSequence();
		}
		wav.save("Test1.wav");
		Wav test2;
		test2.setHeader(wav.getHeader());
		test2.setData(wav.getData());
		test2.setBuffer(wav.getBuffer());
		test2.save("Test2.wav");
		std::cout << "File does exist" << std:: endl;
		printMetaData(s,wav.getHeader());
		auto echoData = Echo::process(wav.getData(), 0.6, 5000);
		wav.setData(echoData);
		printMetaData("copy",test2.getHeader());
		wav.save("Test3.wav");


	}

}

void UI::processSequence(){
}	