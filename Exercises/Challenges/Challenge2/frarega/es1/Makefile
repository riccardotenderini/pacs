DEPS = rk.hpp
OBJ = rk.o
CXXFLAGS = -std=c++11
SOURCE = main.cpp

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
main: $(OBJ) $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean, distclean

clean:
	$(RM) $(OBJ) main

distclean:
	$(RM) $(OBJ) main result.dat
	
