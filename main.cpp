#include "wav.h"
#include "wavheader.h"
#include "wavManager.h"
#include <bits/stdc++.h>


const int NUM_ARGS = 1;
bool startOrQuit(){
	std::cout << "Type \"0\" to quit out of Wavio or Type in \"1\" to continue" << std::endl;
	std::string s;
	std::cin >> s;
	if(s == "0") {return 0;}
	else if(s == "1"){ return 1;} //run program
	else{return startOrQuit();}
}

std::string findDirectory(std::string fileName){
	return fileName.system("find . -name" + " fileName");
}


bool readFile(){
	std::cout << "Please type a filename to open" << std::endl;
	std::string s;
	std::cin >> s;
/*
	std::string directory = findDirectory(s);
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
}


int main(int argc, char const *argv[]){
	bool check;
	std::cout << "Type \"0\" to quit out of Wavio or Type in \"1\" to continue" << std::endl;
	std::string s;
	std::cin >> s;
	if(s == "0") {check = 0;}
	else if(s == "1") {check = 1;} //run program
	else{check = startOrQuit();}
	if(!check){
	 std::cout << "Program End" << std::endl;
	 return 0;
	}
	else{
		std::cout <<"Program Run" << std:: endl;
		if(readFile()){ 
			std::cout << "file exists" << std:: endl;
		}
		else{
			std::cout << "file does not exist" << std:: endl;
		}


	}
	return 0;
}

// Access Token: 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



	

