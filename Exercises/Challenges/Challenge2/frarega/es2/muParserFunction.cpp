#include <string>
#include "muParserFunction.hpp"

muParserFunction::muParserFunction(const std::string & expr){ 
	this->parser.SetExpr(expr);
}

muParserFunction::~muParserFunction(){
	this->parser.ClearVar();
}

double muParserFunction::operator()(double const &t, double const &y){
	this->M_t=t;
	this->M_y=y; 
	this->parser.DefineVar("t",&M_t);
	this->parser.DefineVar("y",&M_y);
	return this->parser.Eval();
}

void printMuException(mu::Parser::exception_type &e){
	using std::cout;
	cout << "Content of muParser exception" << "\n";
	cout << "Message:  " << e.GetMsg() << "\n";
	cout << "Formula:  " << e.GetExpr() << "\n";
	cout << "Token:    " << e.GetToken() << "\n";
	cout << "Position: " << e.GetPos() << "\n";
	cout << "Errc:     " << e.GetCode() << "\n";
}
