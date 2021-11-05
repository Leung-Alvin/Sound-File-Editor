#include "wav.h"
#include "wavheader.h"
#include "wavManager.h"


const int NUM_ARGS = 1;
bool startOrQuit(){
	std::cout << "Type \"Quit\" to quit out of Wavio or Type in \"Start\" to continue" << std::endl;
	std::string s;
	std::cin >> s;
	if(s == "Quit") {return 0;}
	else if(s == "Start"){ return 1;} //run program
	else{return startOrQuit();}
}

int main(int argc, char const *argv[]){
	bool check;
	std::cout << "Type \"Quit\" to quit out of Wavio or Type in \"Start\" to continue" << std::endl;
	std::string s;
	std::cin >> s;
	if(s == "Quit") {check = 0;}
	else if(s == "Start") {check = 1;} //run program
	else{check = startOrQuit();}
	if(!check){
	 std::cout << "Program End" << std::endl;
	 return 0;
	}
	else{
		std::cout <<"Program Run" << std:: endl;
	}
	return 0;
}


