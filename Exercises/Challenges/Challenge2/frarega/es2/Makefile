DEPS = rk.hpp muParserFunction.hpp
OBJ = rk.o muParserFunction.o
CXXFLAGS = -std=c++11
SOURCE = main.cpp
MYLIBRARIES = ../../../../../Examples/lib
MYINCLUDE = ../../../../../Examples/include

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I $(MYINCLUDE) -L $(MYLIBRARIES)  -lmuparser
main: $(OBJ) $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $@ $^ -I $(MYINCLUDE)  -L $(MYLIBRARIES) -lmuparser

.PHONY: clean, distclean

clean:
	$(RM) $(OBJ) main

distclean:
	$(RM) $(OBJ) main result.dat
	
