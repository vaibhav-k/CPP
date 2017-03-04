#include <iostream>
#include <cmath>
#include "matlib.h"

using namespace std;

const double root2Pi = sqrt( 2.0 * 3.141592653589793 );

double normcdf( double x ) {
    if (x<=0) {
        return 1-normcdf(-x);
    }
    double k = 1/(1 + 0.2316419*x);
    double poly = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937
                  + k*(-1.821255978 + 1.330274429*k))));
    double approx = 1.0 - 1.0/root2Pi * exp(-0.5*x*x) * poly;
    return approx;
}

double norminv(double x)
{
    return 1234.0;
}

static inline double hornerFunction(double x, double a0,  double a1)
{
    return a0 + x*a1;
}

int main()
{
    cout << "normcdf(1.96)="
         << normcdf(1.96) << "\n";
    cout << "norminv(0.975)="
         << norminv(0.975) << "\n";
    return 0;
}
