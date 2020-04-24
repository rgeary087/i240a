CXX = g++
CXXFLAGS = -g -Wall -std=c++17
CXX_FILES = $(wildcard *.cc)
OFILES = $(CXX_FILES:cc=o)

all: balanced clean

balanced:	$(OFILES)
		$(CXX) $(OFILES) -o $@
.phony:	clean

clean:
	rm -f *~ *.o $(all)


