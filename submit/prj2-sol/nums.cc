#include <cerrno>
#include <iostream>
#include <string>
#include <algorithm>
#include <cerrno>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "seq.hh"
#include "arrayseq.hh"
#include "command.hh"
#include "dlinkseq.hh"


using TestType = int;
SeqPtr<TestType> arr = ArraySeq<TestType>::make();
SeqPtr<TestType> dlink = DLinkSeq<TestType>::make();
void readFileArr(char* argv, Seq<TestType>& seq){//accepts a file name and a sequence. Reads the file and puts the data into the sequence
	int i;
	std::ifstream in(argv);
	if(!in){
		std::cerr << "cannot read file name" << std::endl;
	}
	while(in>>i){
		seq.push(i);
	}
	if(!in.eof()){
		std::cerr << "i/o error on file \"" << argv << "\""<<std::endl;
	}
	in.close();

}
void outData(ConstIter<TestType>& begin, ConstIter<TestType>& end){
//outputs the data
	while(begin){
		std::cout<< *begin <<std::endl;
		begin = ++begin;
	}
	while(end){
		std::cout<<*end<<std::endl;
		end = --end;
	}
}
int main(int argc,char* argv[]){//reads in the filename and if it should be built with an 
//array sequence of a dlinksequence
	if(argc == 3){
		assert(strcmp(argv[1],"[-a]")==0);
		readFileArr(argv[2], *arr.get());
		outData(*arr->cbegin(), *arr->cend());
	}else{
		readFileArr(argv[1], *dlink.get());
		outData(*dlink->cbegin(), *dlink->cend());
	}
	

}
