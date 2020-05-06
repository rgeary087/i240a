CXX = g++
CXXFLAGS = -g -Wall -std=c++17
CXX_FILES = $(wildcard *.cc)

all:	command-test multi-queues clean

command-test:	command-test.o command.o command-stream.o job.o
		$(CXX) $(CXXFLAGS) -o command-test command-test.o command.o command-stream.o job.o


command-test.o:	command-test.cc command.hh command-stream.hh
		$(CXX) $(CXXFLAGS) -c command-test.cc


command-stream.o:	command-stream.cc command-stream.hh command.hh
			$(CXX) $(CXXFLAGS) -c command-stream.cc

command.o:	command.cc job.hh command.hh
		$(CXX) $(CXXFLAGS) -c command.cc


job.o:		job.cc
		$(CXX) $(CXXFLAGS) -c job.cc

multi-queues:	multi-queues.o 
	$(CXX) $(CXXFLAGS) -o multi-queues multi-queues.o command.o command-stream.o job.o

multi-queues.o:	multi-queues.cc command.hh command-stream.hh job.hh MaxHeap.hh MinHeap.hh heap.hh
	$(CXX) $(CXXFLAGS) -c multi-queues.cc


.phony:	clean


clean:	
	rm -f *~ *.o $(all)


