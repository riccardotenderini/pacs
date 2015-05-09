#include "rk45.hpp"
#include "rk23.hpp"
#include<iostream>
#include <fstream>
#include <cstring>

#include <cmath>
int main(int argc,char *args[])
{
  using namespace std;
  using namespace ODE;
  //  auto fun = [](double const & t, double const & y){return -10*y;};
  auto fun = [](double const & t, double const & y){return -std::sin(t);};


  double t0=0;
  double y0=1;
  double T=100;
  double h_init=0.2;
  double errorDesired45=1.e-7;
  double errorDesired23=1.e-4;
  int status;

  if( argc != 2){
	
   std::cout<<"error input"<<std::endl;
   return -1;
}
  
  if(strcmp(args[1],"rk45")==0){  
  
  auto result= 
    rk45(fun,t0,T,y0,h_init,(T-t0)/4.,errorDesired45,status,10000);
  ofstream file("resultrk45.dat");
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
  std::cout<<"Max error "<<max_error<<" Desired max error "<<errorDesired45;
  std::cout<<std::endl;
  }
 
  
  else if(strcmp(args[1],"rk23")==0) {

  auto result= 
    rk23(fun,t0,T,y0,h_init,(T-t0)/4.,errorDesired23,status,100000);
  ofstream file("resultrk23.dat");
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
  std::cout<<"Max error "<<max_error<<" Desired max error "<<errorDesired23;
  std::cout<<std::endl;
  }
   
  else{
  std::cout<<"error input"<<std::endl;
  }

  return 0;
  
}
