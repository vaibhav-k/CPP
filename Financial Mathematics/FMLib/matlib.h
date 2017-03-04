#ifndef MATLIB_H_INCLUDED
#define MATLIB_H_INCLUDED

#pragma once

const double PI = 3.14159265358979;

/**
 * Computes the cumulative
 * distribution function of the
 * normal distribution
 */
double normcdf( double x );

/*
* Computes the inverse of normcdf
*/
double norminv( double x );

static inline double hornerFunction(double x, double a0,  double a1);
#endif // MATLIB_H_INCLUDED
