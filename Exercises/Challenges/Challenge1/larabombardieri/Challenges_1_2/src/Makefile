CXX=$(mkCxxCompiler)

IDIR=../include
CXXFLAGS=-I$(IDIR) -std=c++11 -Wall 

_DEPS=Geometry2D.hpp
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
SRCS=main.cpp Geometry2D.cpp
OBJ=$(SRCS: .cpp=.o)
EXEC=main

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) 

.PHONY: clean
clean: $(RM) *.o *~