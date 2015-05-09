#ifndef HH_RKINTEGRATOR_HH
#define HH_RKINTEGRATOR_HH
#include <functional>
#include <vector>
#include <cmath>
#include <stdexcept>
namespace ODE
{  //! Default max number of iteration: I set it to the number needed by rk23 which is higher than rk45!

  constexpr std::size_t MAX_STEPS=1000000; 

  //! Single step of RK
  /*!
    for the solution of \f$ dy/dt=f(y(y),t)

    The routine returns the error as the absoute value of the
    difference between the fifth order and fourth order
    approximation. An optimal step size could be computed by
    postprocessing the error with the formula
    \f[
    h_{opt}=(\frac{\epsilon h}{2error})^{1/4}
    ]\f
    where \epsilon is the error control tolerance.
    
    @param dy  the right hand side function :f(t,y)
    @param y0  initial value
    @param h   time step size
    @param error the estimated error
    @return the computed value for y
  */

double rk45_step(
	std::function<double (double const &, double const &)> const & dy,
	double const & y0,  
	double const & t0, 
	double const & h, 
	double & error);



double rk23_step
  (
   std::function<double (double const &, double const &)> const & dy,
   double const & y0, 
   double const & t0, 
   double const & h, 
   double & error
   );

  //! Adaptive RK
  /*!  Integrates /f[ dy/dt(t)=f(t,y(t)) \quad t \in (t0,T] \quad
    y(t0)=y0 /f] controlling the error at t=T I avoid recursion
    because too inefficient.  I do not use the formula for the optimal
    time step. I adopt a simple bisection procedure: the step is
    halved or doubled according to a test on the error. A maximal time step size
    is given to avoid too large time steps, which may cause overlooking variation of f
    with small support.

    @param dy the right hand side f(t,y)
    @param t0 initial time
    @param T final time
    @param y0 initial value
    @param h_initial initial time step size
    @param h_max maximal time step size allowed
    @param final_error Desired error at t=T
    @param status: 0=Ok 1=initial step too small; 2 number of steps exceeded; 
                   3 hmin reached, cannot guarantee error
    @return the solution as pairs t,y
   */


//I added the input arguments c2 that is a constant that changes according to the order of the method and step that it is a pointer to the function step that I want to use. In this way I see rk very general and adaptable to each RKstep !


std::vector<std::pair<double,double>> rk(
	std::function<double (double const &, double const &)> const & dy,
	char* scheme,
	 double const & t0,
	 double const & T,
	 double const & y0,
	 double const & h_initial, 
	 double const & h_max, 
	 double const & final_error,
	 int & status,
	 double const & c2,
	 double (*step)(const std::function<double(const double&, const double&)>&, const double&, const double&, const double&, double&),
	 std::size_t const maxSteps=MAX_STEPS
	 );

}// end namespace
#endif
