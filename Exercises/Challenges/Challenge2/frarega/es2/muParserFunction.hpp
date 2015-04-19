#ifndef HH_MUPARSERFUNCTION_HH
#define HH_MUPARSERFUNCTION_HH
#include <string>
#include "muParser.h"

class muParserFunction{
public:
	//! constructor
	/*!
	@param s the expression of the function f(t,x)
	*/
	muParserFunction(const std::string & s);
	~muParserFunction();
	//! evaluates the function
	double operator()(double const &t, double const &y);
private:
	mu::Parser parser;
	double M_t,M_y;
};

//! prints message on the standard error
void printMuException(mu::Parser::exception_type &e);
#endif
