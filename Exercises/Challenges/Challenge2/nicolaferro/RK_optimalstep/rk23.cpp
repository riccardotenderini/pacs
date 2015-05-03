#include "rk23.hpp"
#include <cmath>
#include <algorithm> // for max
namespace ODE
{
  // f(t,y)
  double rk23_step
  (
   std::function<double (double const &, double const &)> const & f,
   double const & y0, 
   double const & t0, 
   double const & h, 
   double & error
   )
  {
    // Butcher array (row 1 is trivial)
    constexpr double a21 = 1./2.;
    constexpr double c2  = a21;
    
    constexpr double a32 = 3./4.;
    constexpr double c3  = a32;

    constexpr double a41 = 2./9.;
    constexpr double a42 = 1./3.;
    constexpr double a43 = 4./9.;
    constexpr double c4  = a41 + a42 + a43;
    
    constexpr double b21 = 7./24.;
    constexpr double b22 = 1./4.;
    constexpr double b23 = 1./3.;
    constexpr double b24 = 1./8.;

    constexpr double b31 = 2./9.;
    constexpr double b32 = 1./3.;
    constexpr double b33 = 4./9.;
    
    double F1 = h * f(t0, y0);
    double F2 = h * f(t0 + c2 * h, y0 + a21 * F1);
    double F3 = h * f(t0 + c3 * h, y0 + a32 * F2);
    double F4 = h * f(t0 + c4 * h, y0 + a41 * F1 + a42 * F2 + a43 * F3);

    double y2 =   y0 + b21 * F1 + b22 * F2 + b23 * F3 + b24 * F4;
    double y3 =   y0 + b31 * F1 + b32 * F2 + b33 * F3;
    error = std::abs(y2 - y3);
    return y3;
  }


  std::vector<std::pair<double,double>> 
    rk23(std::function<double (double const &, double const &)> const & dy,
	 double const & t0,
	 double const & T,
	 double const & y0,
	 double const & h_initial, 
	 double const & h_max, 
	 double const & final_error,
	 int & status,
	 std::size_t const & maxSteps)
  {
    status=0;
    const std::size_t maxReduction=maxSteps;
    // parameters for decreasing/increasing time step
    double const c1=1.0;

    double length=T-t0;
    //! Make sure that h allows to reach T
    std::size_t initialNSteps=std::max(static_cast<size_t>(1),static_cast<size_t>(length/h_initial));
    double h=length/initialNSteps;
    // To avoid underflow we need in any case to limit the time step to a positive number
    // Here I allow h to become 32 time smaller than that giving the maximal number of steps
    double h_min = length/(16.*maxSteps);

    // Some counters
    std::size_t count(0);
    std::size_t stepsCounter(0);

    // Initial data
    double time(t0);
    double y(y0);
    double errorPerTimeStep=final_error/initialNSteps;

    if (initialNSteps>=maxSteps) throw std::runtime_error("RK23: initial time step h too small!");

    std::vector<std::pair<double,double>> solution;
    solution.emplace_back(std::make_pair(t0,y0));

    double localError;
    double newy;

    while (time<T && stepsCounter <maxSteps)
      {
	//Do a step
	//adjust h if needed for the last step
	if (time + h > T) h = T-time;

	newy = rk23_step(dy,y,time,h,localError);

	while (localError > c1*errorPerTimeStep && count<maxReduction)
	  {
	    if( h> h_min)
	      {
		// calculate scaling factor
		double s = .8*std::pow(errorPerTimeStep/localError, 1./2.);
		
		h *=s;
		errorPerTimeStep *=s;
		++count;
		newy = rk23_step(dy,y,time,h,localError);
	      }
	    else status=3;
	  }

	if (count>=maxReduction)status=1;

	count=0;
	//! advance
	y = newy;
	time +=h;
	++stepsCounter;
	solution.emplace_back(std::make_pair(time,y));
	//! check if we reached end
	if(localError<c1*errorPerTimeStep && h<h_max)
	  {
	    double s = .8*std::pow(errorPerTimeStep/localError, 1./3.);
	   
	    h *=s;
	    errorPerTimeStep *=s;
	  }
      }
    //handle exceptions
    if(stepsCounter>=maxSteps && time < T)
      {
	status=2;
	throw std::runtime_error("RK23: Max number of time steps exceeded");
      }
    return solution;
  }

}// end namespace
