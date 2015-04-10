CXX = $(mkCxxCompiler)
OBJ = edge.o tetrahedon.o
OPTFLAGS = -O3
CXXFLAGS =-Wall -std=c++11
SOURCE = main.cpp
EXEC = main


%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<
$(EXEC): $(OBJ) $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $@  $^

.PHONY: clear

clear:
	$(RM) $(OBJ) $(EXEC)

