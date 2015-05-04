#include "rk.hpp"
#include "muParserInterface.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

void printAndExit()
{
  std::cout<<"Something wrong with input"<<std::endl;
  std::exit(1);
}

int main()
{
  using namespace std;
  using namespace ODE;
  using namespace MuParserInterface;

  string expr;
  muParserInterface par;
  
  
  cout << "Give me an expression possibly contaning variables t and y"<<std::endl;
  while(expr.size()==0) // to filter out extra carriage returns
     {
	getline(cin,expr);
	if(!cin.good()) printAndExit();
     }
  if(!cin.good()) printAndExit();
  cout<<"You have typed:"<<expr<<endl;
  par.set_expression(expr);

  auto fun = [&par](double const & t, double const & y){array<double,2> coor = {{0,y}}; return par(t,coor.data());}; 
  // auto fun = [](double const & t, double const & y){return -10*y;};
  // auto fun = [](double const & t, double const & y){return -std::sin(t);};
  // cout << fun << endl;
  
  Parametri data;
  data.t0=0;
  data.y0=1;
  data.T=100;
  data.h_init=0.2;
  data.errorDesired=1.e-5;
  data.maxsteps = 10000;

  int status;
  Flag flag;  
  while(1){
  	cout << "Solve with RK23 or RK45? [0 for RK23 - 1 for RK 45]" << endl;
        char p;
        cin >> p;
	if(p == '0'){
		flag.RKmethod = RK23;
		break;
	}else if(p == '1'){
		flag.RKmethod = RK45;
		break;
	}
  }
  while(1){
  	cout << "Solve with cutting half timestep or optimal timestep? [0/CHTS for CHTS - 1/OTS for OTS]" << endl;
	char p;
        cin >> p;
	if(p == '0'){
		flag.timestep = CHTS;
		break;
	}else if(p == '1'){
		flag.timestep = OTS;
		break;
	}
  }

  std::vector<std::pair<double,double>> result= 
    rk(fun,data,status,flag);

  ofstream file("result.dat");

  for (auto v : result)
    file<<v.first<<" "<<v.second<<std::endl;
  file.close();
  
  char p;
  cout << "Do you know the exact solution? [Y for yes, other key for no]" << endl;
  cin >> p;
  if( p == 'Y'){
	cout<< "Give me an expression of the exact solution in t"<<std::endl;
        expr.clear();
	while(expr.size()==0) // to filter out extra carriage returns
	{
		getline(cin,expr);
		if(!cin.good()) printAndExit();
	}
	if(!cin.good()) printAndExit();
	cout<<"You have typed:"<<expr<<endl;
	  
	par.set_expression(expr);
	auto exact = [&par](double const & t){array<double,2> coor = {{0,0}}; return par(t,coor.data());}; 
	  
  
  	// Only if I know the exact solution
  	// auto exact=[](double const &t){return std::exp(-10.*t);};
  	// auto exact=[](double const &t){return std::cos(t);};

  	double max_error(0);
  	for (auto i : result)
    		max_error = std::max(max_error,std::abs(exact(i.first)-i.second));
  	std::cout.setf(std::ios::scientific);
  	std::cout<<"Max error "<<max_error<<" Desired max error " << data.errorDesired;
  	std::cout<<std::endl;
  	if(max_error > data.errorDesired)
		std::cout << "Not a good convergence, try with optimal timestep [OTS]" << std::endl;
  }

  return 0;
}

