#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include "rk.hpp"
#include "muParser.h"
#include "muParserFunction.hpp"

int throwInputException()
{
	std::cout<<"Something went wrong while typing the function. The program will exit."<<std::endl;
	std::exit(1);
}

int main(int argc, char** argv)
{
  using namespace std;
  using namespace ODE;

  double t0=0;
  double y0=1;
  double T=100;
  double h_init=0.2;
  double errorDesired=1.e-7;
  std::size_t maxSteps=10000;
  double c1=1.0;
  double c2=1./64.;
  int status;
  std::string expr;

  cout<< "Type the right-hand of the differantial equation dy/dt=f(t,y)"<<std::endl;
  cout<< "(the only allowed variables are \"t\" and \"y\")"<<std::endl;
  while(expr.size()==0) // to filter out extra carriage returns
  {
	getline(cin,expr);
	if(!cin.good()) throwInputException();
  }
  if(!cin.good()) throwInputException();
  muParserFunction fun(expr);
  
  cout<<"Type inizial value y(0):"<<endl;
  cin>>y0;

  std::vector<step_function> methods;
  methods.push_back(rk23_step);
  methods.push_back(rk45_step);
  int k_met=1;
  if      (argc>1 && (strcmp(argv[1],"rk23")==0 || strcmp(argv[1],"RK23")==0)) k_met=1;
  else if (argc>1 && (strcmp(argv[1],"rk45")==0 || strcmp(argv[1],"RK45")==0)) k_met=2;
  else
  {
	bool ok=false;
	while (!ok)
	{
		cout<<"Which method do you want to be used? (type the corresponding number)"<<endl;
		cout<<"1. Runge-Kutta23 (Bogacki–Shampine method)"<<endl;
		cout<<"2. Runge-Kutta45 (Runge–Kutta–Fehlberg method)"<<endl;
		cin>>k_met;
		if (k_met>0 and k_met<3) ok=true;
		else cout<<"You should chose a method!"<<endl;
	}
  }

  cout << "Now I will solve the equation:"<<std::endl<<"\t\tdy/dt="<<expr<<std::endl;
  cout << "\t\ty(0)="<<y0<<endl<<endl;


  if      (k_met==1) {h_init=0.2; errorDesired=1.e-7; c1=1.0; c2= 1./16; maxSteps=1.e6;}
  else if (k_met==2) {h_init=0.2; errorDesired=1.e-7; c1=1.0; c2= 1./64; maxSteps=1.e4;}

  try
  {
	auto result= rk(methods[k_met-1],fun,t0,T,y0,h_init,(T-t0)/4.,errorDesired,status,maxSteps,c1,c2);
	
	ofstream file("result.dat");
	for (auto v : result)
		file<<v.first<<" "<<v.second<<std::endl;
	file.close();

	cout<<"Computation terminated successfully!"<<endl;
	cout<<"If you now the exact solution, type it, otherwise type \"quit\""<<endl;
	
	std::string y_ex;
	while(y_ex.size()==0) // to filter out extra carriage returns
	{
		getline(cin,y_ex);
		if(!cin.good()) throwInputException();
	}
	if(!cin.good()) throwInputException();
	if (y_ex=="quit") exit(0);
	mu::Parser parser;
	parser.SetExpr(y_ex);
	double max_error(0);
	for (auto i : result)
	{
		parser.DefineVar("t",&i.first);
		max_error=std::max(max_error,std::abs(parser.Eval()-i.second));
	}
	std::cout.setf(std::ios::scientific);
	std::cout<<"Max error "<<max_error<<" Desired max error "<<errorDesired;
	std::cout<<std::endl;
  }
  catch (mu::Parser::exception_type &e)
  {
	cout<<"Error in evaluating expression:"<<std::endl;
	printMuException(e);
	std::exit(1);
  }
}
