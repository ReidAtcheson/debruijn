#ifndef __DEBRUIJN_PREFACE_H_
#define __DEBRUIJN_PREFACE_H_

#include <boost/multiprecision/cpp_dec_float.hpp> 
#include <boost/math/quadrature/exp_sinh.hpp>
#include <boost/math/quadrature/tanh_sinh.hpp>



typedef boost::multiprecision::number<boost::multiprecision::cpp_dec_float<50> > cpp_dec_float_50;
typedef boost::multiprecision::number<boost::multiprecision::cpp_dec_float<100> > cpp_dec_float_100;

//typedef cpp_dec_float_100 real_t;
typedef double real_t;


#endif
