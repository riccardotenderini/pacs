#include "rk23.hpp"
#include "rk45.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

std::vector<std::pair<double,double>> 
    rk(std::function<double (double const &, double const &)> const & fun,
	 double const & t0,
	 double const & T,
	 double const & y0,
	 double const & h_init, 
	 double const & h_max, 
	 double const & final_error,
	 int & status,
	 Flag const & flag,
	 std::size_t const & maxSteps);


int main()
{
  using namespace std;
  using namespace ODE;
  auto fun = [](double const & t, double const & y){return -10*y;};
  // auto fun = [](double const & t, double const & y){return -std::sin(t);};
  double t0=0;
  double y0=1;
  double T=100;
  double h_init=0.2;
  double errorDesired=1.e-5;
  int status;
  Flag flag;  
  while(1){
  	cout << "Solve with RK23 or RK45? [0 for RK23 - 1 for RK 45]" << endl;
        char p;
        cin >> p;
	if(p == '0'){
		flag.RKmethod = 0;
		break;
	}else if(p == '1'){
		flag.RKmethod = 1;
		break;
	}
  }
  while(1){
  	cout << "Solve with cutting half timestep or optimal timestep? [0 for CHTS - 1 for OTS]" << endl;
	char p;
        cin >> p;
	if(p == '0'){
		flag.timestep = 0;
		break;
	}else if(p == '1'){
		flag.timestep = 1;
		break;
	}
  }

  std::vector<std::pair<double,double>> result= 
    rk(fun,t0,T,y0,h_init,(T-t0)/4.,errorDesired,status,flag,10000);

  ofstream file("result.dat");

  for (auto v : result)
    file<<v.first<<" "<<v.second<<std::endl;
  file.close();

  // Only if I know the exact solution
  auto exact=[](double const &t){return std::exp(-10.*t);};
  // auto exact=[](double const &t){return std::cos(t);};
  double max_error(0);
  for (auto i : result)
    max_error=std::max(max_error,std::abs(exact(i.first)-i.second));
  std::cout.setf(std::ios::scientific);
  std::cout<<"Max error "<<max_error<<" Desired max error "<<errorDesired;
  std::cout<<std::endl;
  if(max_error > errorDesired)
	std::cout << "Not a good convergence, try with optimal timestep [OTS]" << std::endl;

  return 0;
}


std::vector<std::pair<double,double>> 
    rk(std::function<double (double const &, double const &)> const & fun,
	 double const & t0,
	 double const & T,
	 double const & y0,
	 double const & h_init, 
	 double const & h_max, 
	 double const & final_error,
	 int & status,
	 Flag const & flag,
	 std::size_t const & maxSteps){
  
	std::vector<std::pair<double,double>> result;
	
	if (flag.RKmethod == 0){
		result = ODE::rk23(fun,t0,T,y0,h_init,h_max,final_error,status,flag,maxSteps);
		std::cout << "Solved with RK23" << std::endl;
	}else if(flag.RKmethod == 1){
		result = ODE::rk45(fun,t0,T,y0,h_init,h_max,final_error,status,flag,maxSteps);
		std::cout << "Solved with RK45" << std::endl;
	}
	return result;
};


