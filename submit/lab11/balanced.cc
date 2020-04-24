#include "stack.hh"

#include <iostream>
#include <cstring>

struct DelimMap{
	int delim;
	int encoding;
};

DelimMap delimEncodings[] = {
	{ '(', 1},
	{ ')', -1},
	{ '[', 2},
	{ ']', -2},
	{ '<', 3},
	{ '>', -3},
	{ '{', 4},
	{ '}', -4}
};
void checkDelim(char a){
	bool isIn = false;
	for(unsigned int i = 0; i < sizeof(delimEncodings)/sizeof(delimEncodings[0]); i++){
		if(a == delimEncodings[i].delim){
		       	isIn = true;
		}
	}
	if(!isIn){
		std::cout<<"invalid delimiter " << a << std::endl;
		exit(1);
	}	
}
int getDelimEncoding(char a){
	int ret = 0;
	for(unsigned int i = 0; i < sizeof(delimEncodings)/sizeof(delimEncodings[0]); i++){
		if(a == delimEncodings[i].delim){
			ret = delimEncodings[i].encoding;
		}
	}
	return ret;

}
int main(int argc, char* argv[]){
	Stack stk;
	for(auto i = 1; i < argc; i++){
		if(strlen(argv[i]) != 1){
			std::cout<<"invalid delimiter " << argv[i] << std::endl;
			exit(4);
		}
		checkDelim(argv[i][0]);
		int delim = getDelimEncoding(argv[i][0]);
		if(delim > 0){
			stk.push(delim);
		}else{
			if(stk.size() <= 0){
				std::cout << "unbalanced @ " << i << std::endl;
				exit(2);
			}
			int d = stk.pop();
			if(delim*(-1) != d){
				std::cout << "unbalanced @ " << i <<  std::endl;
				exit(3);
			}
		}	
	}
	if(stk.size() > 0){
		std::cout << "unbalanced @ " << argc << std::endl;
		exit(5);
	}
	return 0;

}
