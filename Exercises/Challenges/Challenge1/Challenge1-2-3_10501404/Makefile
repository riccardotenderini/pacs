CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++0x -I. -O3

SRC = *.cpp
DEPS = *.hpp

all: challenge

challenge: $(SRC) $(DEPS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $@

.PHONY: clean

clean:
	rm -f challenge *~
