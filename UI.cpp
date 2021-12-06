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

void UI::processSequence(Wav w){
	std::cout << separator << std::endl;
	std::cout << "What would you like to do" << std::endl;
	std::cout << " 0 - Normalization \n 1 - Echo \n 2 - Gain Adjustment" << std::endl;
	std::cout << separator << std::endl;
	std::string s;
	std::cin >> s;
	if(s == "0") { //run normalization
		std::string outFileName;
		std::cout << "What would you like to name the output file? Exclude .wav" << std::endl;
		std:: cin >> outFileName;	
		outFileName += ".wav";
		auto normData = Normalization::process(w.getData());
		w.setData(normData);
		w.save(outFileName);	
	}
	else if( s == "1") { //run echo
		float gain;
		int delay;
		std::string outFileName;
		std::cout << "What would you like to name the output file? Exclude .wav" << std::endl;
		std:: cin >> outFileName;
		outFileName += ".wav";
		std::cout<< "How much gain? (Float)" << std::endl;
		std:: cin >> gain;
		std::cout <<"How much delay? (Integer)" << std::endl;
		std::cin >> delay;
		auto echoData = Echo::process(w.getData(), gain, delay);
		w.setData(echoData);
		w.save(outFileName);
	}
	else if (s == "2") { //run gain adjustment
		float gain;
		std::string outFileName;
		std::cout << "What would you like to name the output file? Exclude .wav" << std::endl;
		std:: cin >> outFileName;
		outFileName += ".wav";
		std::cout<< "How much gain? (Float)" << std::endl;
		std:: cin >> gain;
		auto gainData = GainAdjustment::process(w.getData(),gain);
		w.setData(gainData);
		w.save(outFileName);
	}
	
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
		try{
		int n = wav.read(s);
		}
		catch(std::invalid_argument e){
			std::cout << e.what() << std::endl;
			return startSequence();
		}
		std::cout << "File does exist" << std:: endl;
		printMetaData(s,wav.getHeader());
		processSequence(wav);
		startSequence();

	}

}


