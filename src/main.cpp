#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main(int argc, char* argv[]) {
	// error checking for correct usage
	if(argc != 2){
		std::cerr<<"Incorrect Usage. Correct usage..."<<std::endl;
		std::cerr<<"helium <file_name>.he"<<std::endl;
		return -1;
	}
	/*
	enum keyword_t {RETURN, IF, UNKNOWN};
	struct keyword_list_t {std::string keyword, enum keyword_t id} keyword_list[]{
		{"return", RETURN},
		{"if", IF}
	}
	*/
	

	// read the file into string file_text
	std::string file_text;
	std::ifstream ifs(argv[1]);
	file_text.assign((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()	));

	// Lexical analysis
	std::string buffer;
	for (int i = 0; i < file_text.length(); i++){
		/************************************/
		// TODO:
		// > Make the logic cleaner
		// > include other keywords
		// > include a lot more things
		/************************************/
		// alphabetical value followed by alphanumeric value
		// e.g. return, uint64_t, etc.
		if(std::isalpha(file_text.at(i))){	
			buffer.push_back(file_text.at(i));
			i++;
			while (std::isalnum(file_text.at(i))){
				buffer.push_back(file_text.at(i));
				i++;			
			}
			i--;
		}
		// number value
		else if(std::isdigit(file_text.at(i))){
			buffer.push_back(file_text.at(i));
			i++;
			while (std::isdigit(file_text.at(i))){
				buffer.push_back(file_text.at(i));
				i++;			
			}
			i--;		
			continue;
		}
		// blank line
		// check for the value of buffer
		else if (std::isblank(file_text.at(i)) || file_text.at(i) == ';'){
			if (buffer == "return"){
				//TODO:implement
				std::cout<<"Return statement found!"<<std::endl;
			}
			else{
				std::cerr<<"You messed up! Current buffer is..."<<std::endl;
				std::cerr<<buffer<<std::endl;		
			}
			buffer.clear();
		}
		// punctuation
		/*
		else if (std::ispunct(file_text.at(i))){
			//TODO: implement
			if(buffer == ";"){
				std::cout<<"Semicolon found!"<<std::endl;
			}
			buffer.clear();
			
		}
		*/

	}
	
			
	// print file for now
	// std::cout<<file_text<<std::endl;

	return 0;
}
