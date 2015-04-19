#include "rk.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
int main(int argc, char** argv)
{
  using namespace std;
  using namespace ODE;
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
  //  auto fun = [](double const & t, double const & y){return -10*y;};
  auto fun = [](double const & t, double const & y){return -std::sin(t);};
  double t0=0;
  double y0=1;
  double T=100;
  double h_init=0.2;
  double errorDesired=1.e-7;
  std::size_t maxSteps=10000;
  double c1=1.0;
  double c2=1./64.;
  int status;

  if      (k_met==1) {h_init=0.2; errorDesired=1.e-7; c1=1.0; c2= 1./16; maxSteps=1.e6;}
  else if (k_met==2) {h_init=0.2; errorDesired=1.e-7; c1=1.0; c2= 1./64; maxSteps=1.e4;}
  auto result= 
    rk(methods[k_met-1],fun,t0,T,y0,h_init,(T-t0)/4.,errorDesired,status,maxSteps,c1,c2);
  ofstream file("result.dat");
  for (auto v : result)
    file<<v.first<<" "<<v.second<<std::endl;
  file.close();

  // Only if I know the exact solution
  //auto exact=[](double const &t){return std::exp(-10.*t);}
  auto exact=[](double const &t){return std::cos(t);};
  double max_error(0);
  for (auto i : result)
    max_error=std::max(max_error,std::abs(exact(i.first)-i.second));
  std::cout.setf(std::ios::scientific);
  std::cout<<"Max error "<<max_error<<" Desired max error "<<errorDesired;
  std::cout<<std::endl;
}
