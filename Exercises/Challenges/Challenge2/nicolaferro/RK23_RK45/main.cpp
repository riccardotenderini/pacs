#include "rk45.hpp"
#include "rk23.hpp"
#include <fstream>
#include <cmath>
#include <iostream>

void 
compare(
std::function<double (double const &)> const & exact,
std::vector<std::pair<double,double>> result,
double error)
{
	double max_error(0);

	for (auto i : result)
		max_error=std::max(max_error,std::abs(exact(i.first)-i.second));

	std::cout.setf(std::ios::scientific);
	std::cout<<"Max error "<<max_error<<" Desired max error "<<error;
	std::cout<<std::endl;
}

int main()
{
  using namespace std;
  using namespace ODE;

  //auto fun = [](double const & t, double const & y){return 10*y;};
  auto fun = [](double const & t, double const & y){return -std::sin(t);};

  //auto exact=[](double const &t){return std::exp(10.*t);};
  auto exact=[](double const &t){return std::cos(t);};

  double t0=0;
  double y0=1;
  double T=100;
  double h_init=0.2;
  double errorDesired45=1.e-7;
  double errorDesired23=1.e-4;
  int status;

  cout<<"Available Runge-Kutta's methods:"<<endl;
  cout<<"type 23 for R23;"<<endl;
  cout<<"type 45 for R45."<<endl;

  unsigned flag;

  cin>>flag;

  if(flag == 23){
	cout<<endl;
	cout<<"Method chosen: R23."<<endl;

	auto result= 
    	rk23(fun,t0,T,y0,h_init,(T-t0)/4.,errorDesired23,status,1000000);
  	ofstream file("result23.dat");

  	for (auto v : result)
    		file<<v.first<<" "<<v.second<<std::endl;

	compare(exact, result, errorDesired23);
  }
  else if(flag == 45){
	cout<<endl;
	cout<<"Method chosen: R45."<<endl;

	auto result= 
    	rk45(fun,t0,T,y0,h_init,(T-t0)/4.,errorDesired45,status,10000);
  	ofstream file("result45.dat");

  	for (auto v : result)
    		file<<v.first<<" "<<v.second<<std::endl;

	compare(exact, result, errorDesired45);
  }
  else{
  	cout<<"Invalid options."<<endl;
  }

  return 0;
}
