#include <iostream>
#include <complex>
#include <fstream>

#include <cmath>
#include <cstdlib>

#include "preface.h"
#include "debruijn.h"








int main(int argc,char** argv){


  if(argc<=3){
    std::cout<<"Usage: ./main nx ny A"<<std::endl;
    return 1;
  }

  int nx=atoi(argv[1]);
  int ny=atoi(argv[2]);
  real_t A = atof(argv[3]);
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




