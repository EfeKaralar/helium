#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
	// error checking for correct usage
	if(argc != 2){
		std::cerr<<"Incorrect Usage. Correct usage..."<<std::endl;
		std::cerr<<"helium <file_name>.he"<<std::endl;
		return -1;
	}
	// read the file into string file_text
	std::string file_text;
	std::ifstream ifs(argv[1]);
	file_text.assign((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()	));
	
	// print file for now
	std::cout<<file_text<<std::endl;

	return 0;
}
