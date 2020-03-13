CXXFLAGS = -g -Wall -std=c++17

CXX_FILES = $(wildcard *.cc)
TARGETS = $(CXX_FILES:%.cc=%)

all: $(TARGETS) .gitignore

.PHONY: clean

clean:
	rm -f *~ *.0 $(TARGET)
