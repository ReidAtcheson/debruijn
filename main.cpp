#include <iostream>
#include <complex>
#include <fstream>

#include <cmath>

#include "preface.h"
#include "debruijn.h"








int main(int argc,char** argv){

  int nx=512;
  int ny=512;

  real_t A = 25.0;
  real_t x0= -A;
  real_t y0= -A;
  real_t xn=  A;
  real_t yn=  A;
  
  real_t dx= (xn-x0)/nx;
  real_t dy= (yn-y0)/ny;


  real_t t=0.0;
  std::vector<double> Hs(nx*ny);
#pragma omp parallel for
  for(int i=0;i<nx;i++){
    for(int j=0;j<ny;j++){
      real_t x = x0 + i*dx;
      real_t y = y0 + j*dy;
      Hs[j+i*ny]=double(std::abs(H(t,x,y)));
    }
  }




  std::ofstream outfile("hs.dat", std::ios::out | std::ios::binary);
  outfile.write((char*)&Hs[0],nx*ny*sizeof(double));




  return 0;
}




