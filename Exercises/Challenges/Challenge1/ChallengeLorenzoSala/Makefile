CXX = $(mkCxxCompiler)
OPTFLAGS = -O2
CXXFLAGS = $(OPTFLAGS) -Wall -std=c++11 -I.
EXEC1 = main_tria 
SRCS1 = main_tria.cpp
OBJS1 = $(SRCS1:.cpp = .o)
HEADERS = headers/*.hpp
EXEC2 = main_tetra 
SRCS2 = main_tetra.cpp
OBJS2 = $(SRCS2:.cpp = .o)

vpath %.hpp ./headers

all: tria tetra

tria: $(EXEC1)

$(EXEC1): $(OBJS1)

$(OBJS1): $(SRCS1) $(HEADERS)

tetra: $(EXEC2)

$(EXEC2): $(OBJS2)

$(OBJS2): $(SRCS2) $(HEADERS)



.PHONY: clean tria tetra all

clean:
	-rm $(EXEC1) *.*~ *~ *.o $(EXEC2)
	
