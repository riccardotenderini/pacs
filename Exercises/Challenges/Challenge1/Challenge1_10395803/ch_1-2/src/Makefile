CXX=g++
CXXFLAGS=-I$(IDIR) -std=c++14

# Percorso (relativo) alla cartella con header files
IDIR=../include
# Percorso (relativo) alla cartella con file oggetto
ODIR=../obj

# Nomi degli header
_HEAD = edge.hpp triangle.hpp func.hpp
# Percorso agli header
HEAD = $(patsubst %,$(IDIR)/%,$(_HEAD))

# Nomi file oggetto
_OBJ = edge.o triangle.o func.o main.o
# Percorso ai file oggetto
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o : %.cpp $(HEAD)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
main : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
.PHONY: clean distclean

clean :
	$(RM) $(ODIR)/*.o *~ core $(INCDIR)/*~
	
distclean: clean
	$(RM) main


