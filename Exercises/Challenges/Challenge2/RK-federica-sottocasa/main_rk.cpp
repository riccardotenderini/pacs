#include "rk.hpp"
#include<iostream>
#include <fstream>
#include<cstring>
#include <cmath>

int main(int argc, char* args[])
{
  using namespace std;
  using namespace ODE;


if(argc!=2)
	cout<<"You should write ./main_rk RK23 or ./main_rk RK45"<<endl;

if((strcmp(args[1],"RK45")!=0) & (strcmp(args[1],"RK23")!=0))
	cout<<"You have to choose between RK23 and RK45"<<endl;

double c2;
std::size_t maxSteps;

//I create a pointer to the step function that I want to use
double (*step)(const std::function<double(const double&, const double&)>&, const double&, const      double&, const double&, double&);

//According to which scheme I choose I fix the pointer to the right step function and I fix also some parameters 
//I could have pass them also from command line or from a file, but I've decided to fix them here
//I then pass this value to function rk which is generic and the same for rk23 e rk45 !!

if(strcmp(args[1],"RK45")==0) {   
			      step=rk45_step;
			      c2=1./64.;  //parameter for increasing time step
					  // I need to have a sufficient decrease of the local  error to allow time step coarsening
			      maxSteps=10000;
			      
			    }

if(strcmp(args[1],"RK23")==0) {
				step=rk23_step; 
				c2=1./16.;  //parameter for increasing time step, here I've increased it according to the order of the scheme
				maxSteps=1000000;
			        }


 //auto fun = [](double const & t, double const & y){return -10*y;};
auto fun = [](double const & t, double const & y){return -std::sin(t);};
  double t0=0;
  double y0=1;
  double T=100;
  double h_init=0.2;
  double errorDesired=1.e-7;
  int status;



  auto result= rk(fun,args[1],t0,T,y0,h_init,(T-t0)/4.,errorDesired, status,c2,step,maxSteps);

  ofstream file("result.dat");
  for (auto v : result)
  file<<v.first<<" "<<v.second<<std::endl;
  file.close();

  // Only if I know the exact solution
  //auto exact=[](double const &t){return std::exp(-10.*t);};
  auto exact=[](double const &t){return std::cos(t);};
  double max_error(0);
  for (auto i : result)
    max_error=std::max(max_error,std::abs(exact(i.first)-i.second));
  std::cout.setf(std::ios::scientific);
  std::cout<<"Max error "<<max_error<<" Desired max error "<<errorDesired;
  std::cout<<std::endl;
}
