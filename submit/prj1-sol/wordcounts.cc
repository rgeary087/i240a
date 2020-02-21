#include <iostream>
#include <string>
#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>
#include <stdlib.h>

typedef int Count;
typedef std::pair<std::string, Count> WordCount;

bool wordCountCompare(WordCount a, WordCount b){
	if(a.second == b.second){
		if(a.first.length() > b.first.length()){
			for(std::string::size_type i = 0; i < b.first.length();i++){
				if(a.first.at(i) != b.first.at(i)){
					return a.first.at(i) < b.first.at(i);
				}
			}
		}else{
			for(std::string::size_type i = 0; i < a.first.length();i++){
				if(a.first.at(i)!=b.first.at(i)){
					return a.first.at(i) < b.first.at(i);
				}
			}
		}
	}
	return a.second > b.second;
}
int main(int argc, char *argv[]){
	auto args = std::vector<std::string>(&argv[0], &argv[argc]);
	int arg [3];
	for(std::vector<std::string>::size_type i = 1; i < args.size()-1; i++){
		arg[i-1] = std::stoi(args[i]);
	}
	std::string r = "" +arg[0];
	if(r.length() != args[1].length()){
		std::cerr << "bad integer value " << args[1] << "for MAX_N_OUT" << std::endl;
		abort();
	}
	r = "" + arg[1];
	if(r.length() != args[2].length()){		
		std::cerr << "bad integer value " << args[2] << "for MAX_N_OUT" << std::endl;
		abort();
	}
	r = "" + arg[2];
	if(r.length() != args[3].length()){		
		std::cerr << "bad integer value " << args[3] << "for MAX_N_OUT" << std::endl;
		abort();
	};
	if(arg[0] <= 0){
	         std::cerr << "bad integer value "<< arg[0] << " for MAX_N_OUT" << std::endl;
		abort();	
	}
	if(arg[2] <= 0){
		std::cerr << "bad integer value " << arg[2] << " for MAX_WORD_LEN" << std::endl;
		abort();	
	}
	if(arg[1] > arg[2]){
		std::cerr << "MIN_WORD_LEN " << arg[1] << "is greater than MAX_WORD_LEN" << arg[2] << std::endl;
		abort();	
	}
	std::unordered_map<std::string, Count> map;
	std::ifstream in(args[4]);
	char chars[] = "()-'.!\?$%#@/\"\\\':,*\t`;[]%^&+_<>";
	if(!in){
		std::cerr << "cannot read \"" << args[4] << "\"" << std::endl;
	}
	while(in.good()){
		std::string w;
		in >> w;
		for(char c: chars){
			w.erase(std::remove(w.begin(),w.end(), c),w.end());
		}

		for(std::string::size_type i = 0; i < w.size(); i++){
			w[i]=tolower(w[i]);
		}
		std::size_t found = w.find(".com");
		if(found  != std::string::npos){
			w = w.substr(0,found);
		}
		if(w.length() >= arg[1] &&  w.length() <= arg[2]){
			map[w]+=1;
		}

	}
	if(!in.eof()){
		std::cerr << "i/o error on file \"" <<args[4]<< "\""<<std::endl;
	}
	auto wordCounts = std::vector<WordCount>(map.begin(), map.end()); 
	sort(wordCounts.begin(),wordCounts.end(),wordCountCompare);	
	for(std::vector<WordCount>::size_type i = 0; i < arg[0]; i++){
		std::cout << wordCounts[i].first << ": " << wordCounts[i].second << std::endl;
	}
}

