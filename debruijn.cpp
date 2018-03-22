

#include "debruijn.h"

using namespace boost::math::quadrature;

real_t phi(real_t u){
  real_t pi = 2.0*asin(1.0);
  real_t sum=0.0;
  int N=1000;
  for(int n=1;n<N;n++){
    sum+= (2.0*pi*pi*n*n*n*n - 3.0*pi*n*n*exp(4.0*u))*exp(-pi*n*n*exp(4*u));
  }
  return sum;
}

std::complex<real_t> H(real_t t,real_t x,real_t y){

  real_t M=2.0;

  tanh_sinh<real_t> integrator;
  auto reH = [t,x,y](real_t u) { 
    return exp(t*u*u)*phi(u)*cos(u*x)*cosh(u*y);
  };
  auto imH = [t,x,y](real_t u) {
    return  -exp(t*u*u)*phi(u)*sin(u*x)*sinh(u*y);
  };
  real_t termination = sqrt(std::numeric_limits<real_t>::epsilon());
  real_t error1;
  real_t L1;
  real_t error2;
  real_t L2;

  real_t reQ = integrator.integrate(reH,0.0,M);
  real_t imQ = integrator.integrate(imH,0.0,M);


  return std::complex<real_t>(reQ,imQ);
}
