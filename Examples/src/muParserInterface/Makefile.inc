LIBRARY_NAME=muParserInterface
STATIC_LIBFILE=lib$(LIBRARY_NAME).a
DYNAMIC_LIBFILE=lib$(LIBRARY_NAME).so
LDLIBS+= -lmuparser -L../../../Extras/muParser/lib -l$(LIBRARY_NAME) -L.
