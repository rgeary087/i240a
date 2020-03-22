CXX = g++
CXXFLAGS = -g -Wall -std=c++17
CXX_FILES = $(wildcard *.cc)

all:		seq-test nums clean

seq-test: 	seq-test.o command.o 
		$(CXX) $(CXXFLAGS) -o seq-test seq-test.o command.o

seq-test.o: 	seq-test.cc arrayseq.hh command.hh seq.hh
		$(CXX) $(CXXFLAGS) -c seq-test seq-test.cc

command.o:	command.cc arrayseq.hh command.hh seq.hh
		$(CXX) $(CXXFLAGS) -c command.cc

nums:		nums.o
		$(CXX) $(CXXFLAGS) -o nums nums.o

nums.o:		nums.cc arrayseq.hh
		$(CXX) $(CXXFLAGS) -c nums.cc

.phony:		clean

clean:	
		rm -f *~ *.o $(all)
