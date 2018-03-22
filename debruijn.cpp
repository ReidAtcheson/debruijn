

#include "debruijn.h"

using namespace boost::math::quadrature;

real_t phi(real_t u){
  real_t pi = 2.0*asin(1.0);
  real_t sum=0.0;
  int N=32;
  real_t tmp=100.0;

  int i=1;
  while(abs(tmp)>1e-15){
    tmp=0.0;
    for(int n=(i-1)*N+1;n<=i*N;n++){
       tmp += (2.0*pi*pi*n*n*n*n*exp(9.0*u) - 3.0*pi*n*n*exp(5.0*u))*exp(-pi*n*n*exp(4*u));
    }
   sum+=tmp;
   i+=1;
  }
  return sum;
}

std::complex<real_t> H(real_t t,real_t x,real_t y){

  real_t M=1.0;

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



  real_t lim=1.0; 
  real_t reQ = 0.0;
  real_t imQ = 0.0;
  real_t tempre=100.0;
  real_t tempim=100.0;
  while(abs(tempre) > 1e-15 || abs(tempim) > 1e-15){
    tempre   = integrator.integrate(reH,lim-1,lim);
    tempim   = integrator.integrate(imH,lim-1,lim);
    reQ += tempre;
    imQ += tempim;
    lim+=1.0;
  }


  return std::complex<real_t>(reQ,imQ);
}
