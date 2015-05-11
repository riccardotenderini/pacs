#include <iostream>
#include <fstream>
#include <cmath>
//#include <cstring>
#include <iostream>
#include <string>
//#include <cstring>
#include "GetPot"
#include "rk.hpp"
//#include "muParser.h"
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
  int maxSteps=-1; //deafult values depends on the method
  double c1=1;
  double c2=-1; //deafult values depends on the method  
  int k_met=-1; //NO default value
  int status;
  std::string expr(""); //NO default value  
  std::string y_ex(""); //NO default value
  std::string s_met("");

  GetPot cl (argc,argv);
  if (cl.search(2,"-f","--file"))
  {	
	//default file: "options"
	GetPot file(cl.next("options.pot").c_str());

	t0=file("equation/t0",t0);
	y0=file("equation/y0",y0);
	T=file("equation/T",T);
	h_init=file("solver/h_init",h_init);
	errorDesired=file("solver/errorDesired",errorDesired);
	maxSteps=file("solver/maxSteps",maxSteps);
	c1=file("solver/c1",c1);
	c2=file("solver/c2",c2);
	expr=file("equation/fun","");
	y_ex=file("equation/sol","");
	s_met=file("solver/method","");
  }
  else
  {
	t0=cl("t0",t0);
	y0=cl("y0",y0);
	T=cl("T",T);
	h_init=cl("h_init",h_init);
	errorDesired=cl("errorDesired",errorDesired);
	maxSteps=cl("maxSteps",maxSteps);
	c1=cl("c1",c1);
	c2=cl("c2",c2);
	expr=cl("fun","");
	y_ex=cl("sol","");
	s_met=cl("method","");
	cout<<s_met;
  }

  if      (strcmp(s_met.c_str(),"rk23")==0 || strcmp(s_met.c_str(),"RK23")==0) k_met=1;	
  else if (strcmp(s_met.c_str(),"rk45")==0 || strcmp(s_met.c_str(),"RK45")==0) k_met=2;

  if (expr.empty())
  {
	  cout<< "Type the right-hand of the differantial equation dy/dt=f(t,y)"<<std::endl;
	  cout<< "(the only allowed variables are \"t\" and \"y\")"<<std::endl;
	  while(expr.size()==0) // to filter out extra carriage returns
	  {
		getline(cin,expr);
		if(!cin.good()) throwInputException();
	  }
	  if(!cin.good()) throwInputException();
  }
  muParserFunction fun(expr);
  
  std::vector<step_function> methods;
  methods.push_back(rk23_step);
  methods.push_back(rk45_step);
  if (k_met<0)
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

  //if not specified by the user, I set default values according to the chosen method
  if (c2<0 && k_met==1) c2=1./16;
  if (c2<0 && k_met==2) c2=1./64;
  if (maxSteps<0 && k_met==1) maxSteps=1.e6;
  if (maxSteps<0 && k_met==2) maxSteps=1.e4;

  if (cl.search(2,"-p","--print-options"))
  {
	cout<<"********OPTIONS********"<<endl;
	cout<<"Equation:"<<endl;
	cout<<"\tf(t,y)="<<expr<<endl;
	cout<<"\ty(0)="<<y0<<endl;
	cout<<"\tt0="<<t0<<endl;
	cout<<"\tT="<<T<<endl;
	cout<<"Solver:"<<endl;
	cout<<"\tMethod: "<<(k_met==1?"Runge-Kutta23":"Runge-Kutta45")<<endl;
	cout<<"\th_init="<<h_init<<endl;
	cout<<"\terrorDesired="<<errorDesired<<endl;
	cout<<"\tmaxSteps="<<maxSteps<<endl;
	cout<<"\tc1="<<c1<<endl;
	cout<<"\tc2="<<c2<<endl;
	cout<<"***********************"<<endl;
  }
  
  cout << "Now I will solve the equation:"<<std::endl<<"\t\tdy/dt="<<expr<<std::endl;
  cout << "\t\ty(0)="<<y0<<endl<<endl;

  try
  {
	auto result= rk(methods[k_met-1],fun,t0,T,y0,h_init,(T-t0)/4.,errorDesired,status,maxSteps,c1,c2);
	
	ofstream file("result.dat");
	for (auto v : result)
		file<<v.first<<" "<<v.second<<std::endl;
	file.close();

	cout<<"Computation completed successfully!"<<endl;
	if (y_ex.empty())
	{
		cout<<"If you now the exact solution, type it, otherwise type \"quit\""<<endl;	
	
		while(y_ex.size()==0) // to filter out extra carriage returns
		{
			getline(cin,y_ex);
			if(!cin.good()) throwInputException();
		}
		if(!cin.good()) throwInputException();
		if (y_ex=="quit") exit(0);
	}
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
