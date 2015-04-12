CXX = $(mkCxxCompiler)
OPTFLAGS = -O2
CXXFLAGS = $(OPTFLAGS) -Wall -std=c++11 -I.
EXEC = main
SRCS = *.cpp
HEADERS = *.hpp

all: $(EXEC)

$(EXEC): $(OBJS)

$(OBJS): $(SRCS) $(HEADERS)

.PHONY: clean all

clean:
	-rm *.*~ *~ *.o $(EXEC)
	
